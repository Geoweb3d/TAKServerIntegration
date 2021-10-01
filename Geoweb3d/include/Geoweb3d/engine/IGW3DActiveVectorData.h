//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2021, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// Geoweb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../core/GW3DInterFace.h"
namespace Geoweb3d
{
    extern "C++"
    {
        class IGW3DActiveVectorDataEvents
        {
        public:
            virtual ~IGW3DActiveVectorDataEvents() {}
            virtual void OnData(const char* service, const char* ID, const GW3DGeometry* geometry, const Geoweb3d::IGW3DPropertyCollection* field_parms) = 0;
            virtual void OnStatus(const char* operation, const char* msg) = 0;
            virtual void ExceptionMsg(const char* operation, const char* msg) = 0;
        };

        //IGW3DWidgetEvents
        //note, its expected when a driver writes to this, its expectation is that its from the main thread.
        //Thus, if you have multiple threads, its suggested you buffer those messages until your main thread
        //is entered to where you can then write out your buffered messages
        class IGW3DWidgetEvents
        {
        public:
            virtual ~IGW3DWidgetEvents() {}
            virtual void OnWidgetsFatal(const char* operation, const char* msg, unsigned id) = 0;
            virtual void OnWidgetsWarning(const char* operation, const char* msg, unsigned id) = 0;
            virtual void OnWidgetsInfo(const char* operation, const char* msg, unsigned id) = 0;
        };

        class IGW3DActiveVectorData : public IGW3DIBaseObject
        {
        public:
            virtual ~IGW3DActiveVectorData() {}
            virtual bool Connect(const char* hostname, int port, const char* username, const char* password, IGW3DActiveVectorDataEvents* pcallback) = 0;

            virtual int GetNumOfServices() = 0;
            virtual const char* GetServiceName(int index) = 0;
            virtual void SubscribeToService(const char* service) = 0;
            virtual void UnSubscribeToService(const char* service) = 0;
            virtual bool isConnected() = 0;
            virtual const Geoweb3d::IGW3DDefinitionCollection* GetServiceFieldProperties(const char* service) = 0;
            virtual Geoweb3d::GeometryType GetServiceGeometryType(const char* service) = 0;
        };
    }

GW3D_DLL IGW3DActiveVectorData* CreateInstance( unsigned interface_version = GEOWEB3D_INTERFACE_VERSION );
GW3D_DLL void DestroyInstance( IGW3DActiveVectorData *p );

}//end namespace
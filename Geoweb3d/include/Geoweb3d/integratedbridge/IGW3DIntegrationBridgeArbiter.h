//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2021, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// GeoWeb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include <Geoweb3d/core/GW3DInterFace.h>
#include <Geoweb3dCore/Geoweb3dEngine.h>
#include <Geoweb3dCore/Geoweb3dTypes.h>
#include <Geoweb3d/core/GW3DGuids.h>
#include <Geoweb3d/core/GW3DGuidsHelper.h>

#ifdef __cplusplus

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	A macro that defines gw 3 dextern c. </summary>
///
/// <remarks>	Geoweb3d, 11/2/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

#define GW3DEXTERN_C    extern "C"
#else
#define GW3DEXTERN_C    extern
#endif

/*! Primary namespace */
namespace Geoweb3d
{

	//////////////////////////////////
	struct  GW3D_DLL IGW3DIntegrationBridgeArbiter : public IGW3DIBaseObject
	{
		struct  GW3D_DLL IGW3DIntegrationBridgeArbiterInitiStruct
		{
			IGW3DLineSegmentIntersectionTestWPtr hover_and_click_intersectiontest;
		};

		virtual GW3DResult Initialize( IGW3DIntegrationBridgeArbiterInitiStruct *p ) = 0;
		virtual IGW3DBridgedWindowCommunicator* get_BridgedWindowCommunicator() = 0;

		static IGW3DIntegrationBridgeArbiterPtr CreateInterface()
		{
			return CreateInterfacePtr< IGW3DIntegrationBridgeArbiterPtr, IGW3DIntegrationBridgeArbiter>( GUID_GEOWEB3D_SDK_INTEGRATED_BRIDGE_ARBITER );
		}
	};
}

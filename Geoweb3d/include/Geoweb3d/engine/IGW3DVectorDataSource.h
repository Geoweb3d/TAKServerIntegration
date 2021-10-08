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
#include <Geoweb3dCore/GW3DResults.h>
/*! Primary namespace */
namespace Geoweb3d
{

    extern "C++" 
    {

        namespace VirtualSystems
        {
            GW3D_DLL GW3DResult IGW3DCreateInMemoryFile(const char* filename, unsigned char* pdata, int64_t pdata_length, bool take_pdata_ownership);
        };


        struct GW3D_DLL IGW3DVectorDataSourceSummary
        {
            ~IGW3DVectorDataSourceSummary() {}
            virtual const IGW3DStringCollection* get_LayerNamesCollection() = 0;
        };

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// <summary>	    A vector datasource. </summary>
        ///
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        struct GW3D_DLL IGW3DVectorDataSource
        {
            virtual ~IGW3DVectorDataSource() {}
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Gets the name. </summary>
            ///
            /// <remarks>	Gets the name of the datasource (what was used to open or create). </remarks>
            ///
            /// <returns>	the name. </returns>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual const char* get_Name() = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Gets the driver. </summary>
            ///
            /// <remarks>	Vector driver the datasource was created or opened with. </remarks>
            ///
            /// <returns>	The driver. </returns>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual IGW3DVectorDriverWPtr get_Driver() = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Gets the driver properties used to open the datasource. </summary>
            ///
            /// <remarks>	If you didn't supply properties, the defaults will return.  If no default properties
            //				this will be null</remarks>
            ///
            /// <returns>	The driver. </returns>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual const IGW3DPropertyCollection* get_DriverProperties() const = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Gets the vector data source collection. </summary>
            ///
            /// <remarks>	The collection this datasource belongs to (this is the same collection returned by
            /// 			the GW3DVectorDriver). </remarks>
            ///
            /// <returns>	the vector data source collection. </returns>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual IGW3DVectorDataSourceCollection* get_VectorDataSourceCollection(bool reset_next_iterator = false) = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Gets the vector layer collection. </summary>
            ///
            /// <remarks>	Gets the collection of all vector layers that were created or opened using this
            /// 			driver. </remarks>
            ///
            /// <returns>	The vector layer collection. </returns>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual IGW3DVectorLayerCollection* get_VectorLayerCollection(bool reset_next_iterator = false) = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Executes an SQL command operation. </summary>
            ///
            /// <param name="statement">	The statement. </param>
            ///
            /// <returns>	GW3D_sOk if succeeded. </returns>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual GW3DResult ExecuteSQLCommand(const char* statement) = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Executes a SQL operation that results in a new layer. </summary>
            ///
            /// <param name="statement">	The statement. </param>
            ///
            /// <returns>	GW3D_sOk if succeeded. </returns>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual GW3DResult ExecuteSQLLayerCreator(const char* statement) = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	A macro that defines creating a layer is supported by the driver. </summary>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

#define isCreateLayerSupported       "CreateLayer" //True if this datasource can create new layers.

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	A macro that defines deleting a layer supported by the driver. </summary>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

#define isDeleteLayerSupported       "DeleteLayer" //True if this datasource can delete existing layers.

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Query if driver supports a given capability. </summary>
    ///
    /// <param name="isSupported">	The capability to query. </param>
    ///
    /// <returns>	true if capable, false if not capable. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual bool get_IsCapable(const char* isSupported) = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	copies a datasource to the destination, using the driver give as the export</summary>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual bool create_Copy(IGW3DVectorDriverWPtr export_driver, IGW3DPropertyCollection* export_driver_properties, const char* destination_name) = 0;

        };
    }
}
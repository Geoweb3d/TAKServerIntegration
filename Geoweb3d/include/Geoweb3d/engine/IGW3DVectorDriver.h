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
#include "../core/IGW3DDriver.h"

/*! Primary namespace */
namespace Geoweb3d
{
    extern "C++"
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// <summary>	A vector driver. </summary>
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        struct  GW3D_DLL IGW3DVectorDriver : public IGW3DDriver
        {
            virtual ~IGW3DVectorDriver() {}

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Gets the default properties for this driver </summary>
            ///
            /// <remarks>	Gets the default properties that can be used to open a datasource using this
            /// 			driver.  Check for null, as some drivers do not support properties.  </remarks>
            ///
            /// <returns>	The properties, or null if none exist. </returns>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual const IGW3DPropertyCollection* get_PropertyCollection() = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Gets the vector datasource collection. </summary>
            ///
            /// <remarks>	Gets the collection of all vector datasources that have been opened or created
            /// 			using this driver.  Vector datasources aare also created and opened through the
            /// 			collection. </remarks>
            ///
            /// <returns>	the vector datasource collection. </returns>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual IGW3DVectorDataSourceCollection* get_VectorDataSourceCollection(bool reset_next_iterator = false) = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Gets the name. </summary>
            ///
            /// <remarks>	Gets the name that was used to create or open the datasource (for example, the file
            /// 			path. </remarks>
            ///
            /// <returns>	the name. </returns>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual const char* get_Name() const = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	A macro that defines creating a datasource is supported. </summary>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

#define isCreateDataSourceSupported   "CreateDataSource"

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	A macro that defines deleting a datasource is supported. </summary>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

#define isDeleteDataSourceSupported  "DeleteDataSource"

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Query if driver supports a given capability. </summary>
    ///
    /// <param name="isSupported">	The capability to query. </param>
    ///
    /// <returns>	true if capable, false if not capable. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual bool get_IsCapable(const char* isSupported) = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Gets the file extentions this driver supports</summary>
            ///
            /// <remarks>	Most drivers only have 1 extention (such as .shp)  </remarks>
            ///
            /// <returns>  this can return null as well as be an empty collection </returns>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual IGW3DStringCollectionPtr get_FileExtentionCollection() const = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Gets the create options this driver supports</summary>
            ///
            /// <remarks>	 </remarks>
            ///
            /// <returns>  this can return null as well as be an empty collection </returns>
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            virtual IGW3DPropertyCollectionPtr get_Creation_Options() = 0;
            virtual IGW3DPropertyCollectionPtr get_Open_Options() = 0;

        };
    }
}




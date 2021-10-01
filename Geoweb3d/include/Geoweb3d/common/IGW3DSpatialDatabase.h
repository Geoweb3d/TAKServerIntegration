//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2017, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// Geoweb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////

#pragma once

#include "../core/GW3DInterFace.h"
#include <Geoweb3dCore/Geoweb3dTypes.h>

/*! Primary namespace */

namespace Geoweb3d
{
        extern "C++"
        {
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// <summary> </summary>
        ///
        /// <remarks></remarks>
        ///
        /// <see cref="IGW3DSpatialDatabaseCallback"/>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        struct GW3D_DLL IGW3DSpatialDatabaseCallback
        {
            virtual ~IGW3DSpatialDatabaseCallback() {}
            virtual void found_RecordIndex(const uint64_t& index, const GW3DEnvelope& env) = 0;
        };

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// <summary> </summary>
        ///
        /// <remarks></remarks>
        ///
        /// <see cref="IGW3DSpatialDatabase"/>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        struct GW3D_DLL IGW3DSpatialDatabase
        {
            virtual ~IGW3DSpatialDatabase() {}

            virtual GW3DResult put_Data(uint64_t, const GW3DEnvelope& env) = 0;

            virtual GW3DResult remove_Data(uint64_t, const GW3DEnvelope& env) = 0;

            virtual GW3DResult search(const GW3DEnvelope& env, IGW3DSpatialDatabaseCallback* cb) = 0;
        };
    }
}
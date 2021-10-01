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
#include "../core/IGW3DConstCollection.h"

namespace Geoweb3d
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Collection of colors with user defined attributes. </summary>
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    extern "C++"
    {
        struct GW3D_DLL IGW3DColorCollection : public IGW3DConstCollection< const IGW3DColor* >
        {
            virtual ~IGW3DColorCollection() {}
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Array indexer operator. </summary>
            ///
            /// <param name="index">	Zero-based index of the color. </param>
            ///
            /// <returns>	The indexed value. </returns>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual const IGW3DColor* operator[](unsigned long index) const = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Gets at index. </summary>
            ///
            /// <param name="index">	Zero-based index of the color. </param>
            ///
            /// <returns>	at index. </returns>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual const IGW3DColor* get_AtIndex(unsigned long index) const = 0;
        };
    }
}
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
#include "../core/IGW3DCollection.h"
#include "GW3DExports.h"

/*! Primary namespace */
namespace Geoweb3d
{
	extern "C++"
	{
		struct  GW3D_DLL IGW3DGeoFenceCollection : public IGW3DCollection< IGW3DGeoFenceWPtr >
		{
			virtual ~IGW3DGeoFenceCollection() {}

#ifndef SWIGGING	
			virtual const IGW3DGeoFenceWPtr operator[](unsigned long index) const = 0;

			virtual const IGW3DGeoFenceWPtr get_AtIndex(unsigned long index) const = 0;
#endif //SWIGGING
			virtual IGW3DGeoFenceWPtr create(IGW3DVectorLayerWPtr layer, const char* geo_fence_intruder, const char* name) = 0;

			static void close(IGW3DGeoFenceWPtr& geo_fence)
			{
				close_GeoFence(geo_fence);
			}
		};
	}
}
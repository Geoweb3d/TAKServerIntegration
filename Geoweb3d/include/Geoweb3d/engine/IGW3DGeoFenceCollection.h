//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2018, all rights reserved.
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
	struct IGW3DGeoFenceCollection : public IGW3DCollection< IGW3DGeoFenceWPtr >
	{
		virtual const IGW3DGeoFenceWPtr operator[](unsigned long index) const = 0;

		virtual const IGW3DGeoFenceWPtr get_AtIndex(unsigned long index) const = 0;

		virtual IGW3DGeoFenceWPtr create(IGW3DVectorLayerWPtr layer, const char* geo_fence_intruder, const char* name) = 0;

		static void close(IGW3DGeoFenceWPtr &geo_fence)
		{
			close_GeoFence(geo_fence);
		}
	};
}

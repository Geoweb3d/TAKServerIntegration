//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2020, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// Geoweb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../../Geoweb3dCore/GeometryExports.h"
#include "IGW3DRasterLayerEnvelopeStreamResult.h"

namespace Geoweb3d
{
	extern "C++"
	{
		struct  GW3D_DLL IGW3DRequest : public GW3DEnvelope
		{
			virtual ~IGW3DRequest() {}

			IGW3DRequest() : raster_width(256), raster_height(256)
			{

			}

			//will sample to this resolution
			int raster_width;
			int raster_height;
		};
		struct  GW3D_DLL IGW3DRasterLayerEnvelopeStream : public IGW3DRequest
		{
			virtual ~IGW3DRasterLayerEnvelopeStream() {}

			//note, if you did an async query, this will get called on a different
			//thread, so make sure you are threadsafe.
			//one day we can store these up on a Q and a user can gather all the 
			//requests on whatever thread they wish instead of what we have today
			virtual bool OnStream(IGW3DRasterLayerEnvelopeStreamResult* result) = 0;
		};
	}
}
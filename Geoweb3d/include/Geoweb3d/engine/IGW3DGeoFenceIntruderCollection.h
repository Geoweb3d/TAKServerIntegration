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
		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary> </summary>
		///
		/// <remarks></remarks>
		///
		/// <see cref="IGW3DWindow"/>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		enum GeoFenceStatus
		{
			START_PAGING = 0,
			STOP_PAGING,
			TILE_START_PAGING,
			TILE_STOP_PAGING,
			TILE_GEOFENCE_START,
			TILE_GEOFENCE_END,
			GEOFENCE_DIRTY,
			TEMP
		};

		struct  GW3D_DLL IGW3DIntruderCallback
		{
			virtual ~IGW3DIntruderCallback() {}

			virtual void statusOfGeoFenceSubscribers(GeoFenceStatus geo_fence_status, const unsigned long& frame_stamp, const uint64_t& tile_id = 0) = 0;
		};

		struct  GW3D_DLL IGW3DGeoFenceIntruderCollection : public IGW3DCollection< IGW3DGeoFenceIntruderWPtr >
		{
			virtual ~IGW3DGeoFenceIntruderCollection() {}

#ifndef SWIGGING
			virtual const IGW3DGeoFenceIntruderWPtr operator[](unsigned long index) const = 0;

			virtual const IGW3DGeoFenceIntruderWPtr get_AtIndex(unsigned long index) const = 0;
#endif //SWIGGING
			virtual IGW3DGeoFenceIntruderWPtr create(const char* name, bool use_grid, IGW3DIntruderCallback* cb) = 0;

			static void close(IGW3DGeoFenceIntruderWPtr& geo_fence_intruder)
			{
				close_GeoFenceIntruder(geo_fence_intruder);
			}
		};
	}
}

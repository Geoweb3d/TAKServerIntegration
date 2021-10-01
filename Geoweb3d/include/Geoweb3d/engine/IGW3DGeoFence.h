#pragma once
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
#include <Geoweb3dCore/GeometryExports.h>

/*! Primary namespace */
namespace Geoweb3d
{
	typedef uint16_t IGW3DGeoFenceRefreshMask;
	extern "C++"
	{
		enum IGW3DGEOFENCE_REFRESH_REQUEST
		{
			NONE = 0x00,
			TILES = 0x01,
			VIEWBOUNDS = 0x02,
			GRIDBOUNDS = 0x04,
			IGW3DGEOFENCE_REFRESH_REQUEST_MAX = 0xFFFF
		};

		struct  GW3D_DLL IGW3DGeoFenceRefreshRequest
		{
			virtual ~IGW3DGeoFenceRefreshRequest() {}

			IGW3DGeoFenceRefreshRequest()
			{
				refresh_mask_ = IGW3DGEOFENCE_REFRESH_REQUEST::NONE;
				env_.put(-180.0, 180.0, -90, 90.0, 0, 0);
			}

			IGW3DGeoFenceRefreshRequest(IGW3DGeoFenceRefreshMask refresh_mask)
			{
				refresh_mask_ = refresh_mask;
				env_.put(-180.0, 180.0, -90, 90.0, 0, 0);
			}

			IGW3DGeoFenceRefreshRequest(IGW3DGeoFenceRefreshMask refresh_mask, GW3DEnvelope& env)
			{
				refresh_mask_ = refresh_mask;
				env_ = env;
			}

			virtual void put_TileFlag(bool request_tiles)
			{
				if (request_tiles)
				{
					refresh_mask_ |= IGW3DGEOFENCE_REFRESH_REQUEST::TILES;
				}
				else
				{
					refresh_mask_ &= ~IGW3DGEOFENCE_REFRESH_REQUEST::TILES;
				}
			}
			virtual bool get_TileFlag()
			{
				return (refresh_mask_ & IGW3DGEOFENCE_REFRESH_REQUEST::TILES) > 0 ? true : false;
			}

			virtual void put_ViewboundsFlag(bool request_viewbounds)
			{
				if (request_viewbounds)
				{
					refresh_mask_ |= IGW3DGEOFENCE_REFRESH_REQUEST::VIEWBOUNDS;
				}
				else
				{
					refresh_mask_ &= ~IGW3DGEOFENCE_REFRESH_REQUEST::VIEWBOUNDS;
				}
			}
			virtual bool get_ViewboundsFlag()
			{
				return (refresh_mask_ & IGW3DGEOFENCE_REFRESH_REQUEST::VIEWBOUNDS) > 0 ? true : false;
			}

			virtual void put_GridboundsFlag(bool request_gridbounds)
			{
				if (request_gridbounds)
				{
					refresh_mask_ |= IGW3DGEOFENCE_REFRESH_REQUEST::GRIDBOUNDS;
				}
				else
				{
					refresh_mask_ &= ~IGW3DGEOFENCE_REFRESH_REQUEST::GRIDBOUNDS;
				}
			}
			virtual bool get_GridboundsFlag()
			{
				return (refresh_mask_ & IGW3DGEOFENCE_REFRESH_REQUEST::GRIDBOUNDS) > 0 ? true : false;
			}

			virtual void put_RequestMask(IGW3DGeoFenceRefreshMask request_mask)
			{
				refresh_mask_ = request_mask;
			}

			virtual IGW3DGeoFenceRefreshMask get_RequestMask()
			{
				return refresh_mask_;
			}

			virtual void put_RequestAll()
			{
				put_RequestMask(IGW3DGEOFENCE_REFRESH_REQUEST::TILES | IGW3DGEOFENCE_REFRESH_REQUEST::VIEWBOUNDS | IGW3DGEOFENCE_REFRESH_REQUEST::GRIDBOUNDS);
			}

			GW3DEnvelope env_;
			IGW3DGeoFenceRefreshMask refresh_mask_;

		};

		struct  GW3D_DLL IGW3DGeoFence
		{
			virtual ~IGW3DGeoFence() {}
			virtual GW3DResult refresh(IGW3DGeoFenceRefreshRequest refresh_request) = 0;
		};
	}
}

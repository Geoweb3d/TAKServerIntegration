//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2019, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// GeoWeb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include <Geoweb3d/core/GW3DInterFace.h>
#include <Geoweb3dCore/GeoWeb3dEngine.h>
#include <Geoweb3dCore/Geoweb3dTypes.h>

namespace Geoweb3d
{
	///////////////////////////////////////////////////////////
	struct IGW3DSDKVectorContext
	{
		virtual GW3DResult close_GW3DDataSource(const char* vectordrivername, const char* data_source_name) = 0;

		virtual IGW3DVectorLayerCollection* get_IGW3DVectorLayerCollection(const char* vector_driver_name, const char* data_source_name, bool create = true) = 0;

		virtual IGW3DVectorRepresentationDriverCollection* get_IGW3DVectorRepresentationDriverCollection() = 0;

	};
}

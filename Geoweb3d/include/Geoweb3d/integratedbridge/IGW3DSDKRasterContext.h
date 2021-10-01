//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2021, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// GeoWeb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include <Geoweb3d/core/GW3DInterFace.h>
#include <Geoweb3dCore/Geoweb3dEngine.h>
#include <Geoweb3dCore/Geoweb3dTypes.h>

namespace Geoweb3d
{
	///////////////////////////////////////////////////////////
	struct  GW3D_DLL IGW3DSDKRasterContext
	{
		virtual GW3DResult close_GW3DDataSource(const char* vectordrivername, const char* data_source_name) = 0;

		virtual IGW3DRasterLayerCollection* get_IGW3DRasterLayerCollection(const char* raster_driver_name, const char* data_source_name, bool create = true) = 0;

		virtual IGW3DRasterRepresentationDriverCollection* get_IGW3DRasterRepresentationDriverCollection() = 0;

		virtual IGW3DRasterDataSourceWPtr load_ElevationDataSource(const char* vector_driver_name, const char* data_source_name, bool create = false, IGW3DRasterPipelineCallbacks* cb = 0) = 0;

		// forces the dataset to go active|inactive to force a reload.
		virtual void HackCoverageUpdate() = 0;

	};
}

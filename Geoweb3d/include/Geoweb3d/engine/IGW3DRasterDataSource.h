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
#include "../../Geoweb3dCore/GeometryExports.h"

/*! Primary namespace */
namespace Geoweb3d
{
	extern "C++"
	{
		struct  GW3D_DLL IGW3DRasterPipelineCallbacks
		{
			virtual ~IGW3DRasterPipelineCallbacks() {}

			virtual GW3DEnvelope GW3DTHREADED_RasterPipeline_GetDataSourceBounds() = 0;
			virtual double GW3DTHREADED_RasterPipeline_GetNoDataValue() = 0;
			virtual int GW3DTHREADED_RasterPipeline_GetWidth() = 0;
			virtual int GW3DTHREADED_RasterPipeline_GetHeight() = 0;
			virtual int GW3DTHREADED_RasterPipeline_GetBandCount() = 0;

			virtual double GW3DTHREADED_RasterPipeline_GetXPixelSize() = 0;
			virtual double GW3DTHREADED_RasterPipeline_GetYPixelSize() = 0;

			virtual bool GW3DTHREADED_get_HasDataWithin(double NW_lat, double NW_lon, double SE_lat, double SE_lon) = 0;

			virtual GW3DResult GW3DTHREADED_RasterPipeline_GetElevationAt(double lat, double lon, float& value) = 0;

			// if neighbors is not null then fill neighbors with the 4 neighboring posts (size is requested_count * 4). Otherwise, pack the elevation for the request point into the z component 
			// of the requested point. Hint: data is expected to be interleaved .... 4 neighbors for requested_pts[0], followed by 4 neaghbors for requested_pts[1], etc.
			virtual GW3DResult GW3DTHREADED_RasterPipeline_GetElevationPoints(unsigned int requested_count, GW3DPoint* requested_pts, GW3DPoint* neighbors) = 0;

			virtual GW3DResult GW3DTHREADED_RasterPipeline_GetElevationBlock(double NW_lat, double NW_lon,
				double SE_lat, double SE_lon,
				short number_NS_samples, short number_EW_samples,
				float* pvPointDataArray, double& min_elevation, double& max_elevation) = 0;

			virtual GW3DResult GW3DTHREADED_RasterPipeline_GetMinMaxOfBlock(double NW_lat, double NW_lon,
				double SE_lat, double SE_lon,
				short number_NS_samples, short number_EW_samples,
				double& min_elevation, double& max_elevation) = 0;
		};

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Raster data source. </summary>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		struct  GW3D_DLL IGW3DRasterDataSource
		{
			virtual ~IGW3DRasterDataSource() {}

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the name. </summary>
			///
			/// <remarks>	Gets the name of the datasource (what was used to open or create) </remarks>
			///
			/// <returns>	the name. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual const char* get_Name() const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the driver. </summary>
			///
			/// <remarks>	Raster driver the datasource was opened with. </remarks>
			///
			/// <returns>	The driver. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual IGW3DRasterDriverWPtr get_Driver() = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the Raster data source collection. </summary>
			///
			/// <remarks>	The collection this datasource belongs to (this is the same collection returned by
			/// 			the GW3DRasterDriver). </remarks>
			///
			/// <returns>	the Raster data source collection. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual IGW3DRasterDataSourceCollection* get_RasterDataSourceCollection(bool reset_next_iterator = false) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the Raster layer collection. </summary>
			///
			/// <remarks>	Gets the collection of all Raster layers that were created or opened using this
			/// 			driver. </remarks>
			///
			/// <returns>	The Raster layer collection. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual IGW3DRasterLayerCollection* get_RasterLayerCollection(bool reset_next_iterator = false) = 0;

		};
	}
}
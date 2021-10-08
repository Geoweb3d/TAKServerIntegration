#ifndef GEOWEB3D_RASTER_TYPE_EXPORTS_H
#define GEOWEB3D_RASTER_TYPE_EXPORTS_H

/*! Primary namespace */
namespace Geoweb3d
{

	/*! Raster namespace */
	namespace Raster
	{		
		struct RasterSourceHandle_;
		typedef RasterSourceHandle_* RasterSourceHandle;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	A raster cache. </summary>
		///
		/// <remarks>	Stores cached informaiton about a raster for fast indexing without reading the file 
		/// 			directly. </remarks>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		struct RasterCache
		{
			int num_bands;

			//currently we max to 4 band for no data
			double nodatavalue[4];
			bool nodatavalue_valid[4];	

			bool has_subdatasets;
			bool do_reprojection;

			const char* source_driver_long;
			const char* source_projection;

			double bounds_origin_x;
			double bounds_origin_y;
			double bounds_end_x;
			double bounds_end_y;

			int width;
			int height;

			double pixel_size_x;
			double pixel_size_y;

			//OPTIONAL-- pixel size in meters, not required for loading in SDK
			double pixel_size_meters_x;
			double pixel_size_meters_y;
		};
	}
}

#endif
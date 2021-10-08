//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2018, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// Geoweb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef GEOWEB_DEM_EXPORTS_H
#define GEOWEB_DEM_EXPORTS_H

#include "Geoweb3dExports.h"
#include "Geoweb3dTypes.h"

/*! @file DemExports.h */

/*! Primary namespace */
namespace Geoweb3d
{
	class GW3DGeometry;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Dem Namespace </summary>
	///
	/// <remarks>	Interfaces in the Dem namespace are part of the legacy C-like namespace. 
	///				Note: The C++ raster API has more capabilities than the legacy C-style API, however
	///				in other capabilities it does not yet have equivilancy.  See 
	/// 			IGW3DRasterDriverCollection to evaluate which capabilities are important to
	///				your use case before selecting which raster API to use. </remarks>
	///
	/// <see cref="IGW3DRasterDriverCollection"/>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	namespace Dem
	{

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Dem query details. </summary>
///
/// <see cref="QueryDem"/>
////////////////////////////////////////////////////////////////////////////////////////////////////

struct DemQuery
{
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	DemQuery() : 
		min_lon( 0.0 ), min_lat( 0.0 ),
		max_lon( 0.0 ), max_lat( 0.0 ),
		x_pixel_size( 0.0 ), y_pixel_size( 0.0 ),
		width( 0 ), height( 0 ),
		driver_long_name( 0 )
		{ }

	/// <summary>	Minimum longitude of the file in WGS84 </summary>
	double min_lon;

	/// <summary>	Minimum latitude of the file in WGS84. </summary>
	double min_lat;

	/// <summary>	Maximum longitude of the file in WGS84. </summary>
	double max_lon;

	/// <summary>	Maximum latitude of the file in WGS84 </summary>
	double max_lat;

	/// <summary>	X pixel size (resolution) in the file's native pixel format. </summary>
	double x_pixel_size;

	/// <summary>	Y pixel size (resolution) in the file's native pixel format. </summary>
	double y_pixel_size;

	/// <summary>	The width in pixels. </summary>
	int width;

	/// <summary>	The height in pixels. </summary>
	int height;

	/// <summary>	Detailed name of the driver that loaded the DEM (digital elevation model). </summary>
	const char* driver_long_name;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	DEM loading properties. </summary>
///
/// <remarks>	Parameters for configuring the DEM file at load time. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

struct DemLoadProperties
{
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Comparison function for invalid elevation values. </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	enum OpType
	{
		/// <summary>	An enum constant representing the option for discarding elevation values equal 
		/// 			to the value invalid_elevation_value. </summary>
		DEM_EQ = 0,
		/// <summary>	An enum constant representing the option for discarding elevation values equal
		/// 			or less than the value invalid_elevation_value. </summary>
		DEM_LEQ = 1	
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	DemLoadProperties() : priority(0),
		override_dataset( false ), 
		invalid_elevation_value( -10000 ), 
		op( DEM_LEQ ), 
		vertical_exaggeration( 1.0 ),
		page_level( 11 ),
		projection_error_threshold( 0.f ),
		activity( true )
	{ }

	/// <summary>	true to override any invalid elevation values in the dataset </summary>
	bool override_dataset;

	/// <summary>	The invalid elevation value.</summary>
	float invalid_elevation_value;
	
	/// <summary>	The comparison operator to determine invalid values. </summary>
	OpType op;

	/// <summary>	Vertical exaggeration of the dataset. </summary>
	double vertical_exaggeration;
	
	/// <summary>	The priority of this file over others (not yet implimented). </summary>
	int priority;


	/// <summary>	The page level. </summary>
	/// <remarks>	Level of the terrain to start bringing in the file, ranges from 1 - 20 or so, with lower numbers 
	/// 			bringing in the dataset quicker.  While this can be advantagous for some resolutions of data, 
	/// 			for fine resolutions it is usually unnecessary to bring the data in before level 11+.  Bringing 
	/// 			in high resolution data preemptively will just spike memory overhead. To match a page level to 
	///				a real-world distance in meters, call PageLevelToMeterRadius. </remarks>
	unsigned page_level;

	/// <summary>	The projection error threshold. </summary>
	float projection_error_threshold;

	/// <summary>	true for layer to be active on constructio. </summary>
	bool activity;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Loads a DEM (digital elevation mode). </summary>
///
/// <remarks>	Note: this API will be depricated.  See IGW3DRasterDriverCollection for the future 
/// 			interface. </remarks>
///
/// <param name="url">			  	Location of the DEM. </param>
/// <param name="projection_file">	The projection file. </param>
/// <param name="load_props">	  	The load properties. </param>
/// <param name="handle">		  	[out] A unique identifier for the DEM</param>
///
/// <returns>	GW3D_sOk if succeeded. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API GW3DResult LoadDEM( const char* url, const char* projection_file, DemLoadProperties const& load_props,Raster::RasterSourceHandle & handle );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Removes the dem described by handle. </summary>
///
/// <remarks>	remove a DEM. </remarks>
///
/// <param name="handle">	The unique identifier for the DEM. </param>
///
/// <returns>	GW3D_sOk if succeeded. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API GW3DResult RemoveDEM(Raster::RasterSourceHandle & handle );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets elevation at a given latitude and longitude. </summary>
///
/// <param name="longitude">  	The longitude. </param>
/// <param name="latitude">   	The latitude. </param>
/// <param name="interpolate">	(optional) Whether or not to apply the interpolation we use 
/// 							internally, versus just the pixel value.. </param>
///
/// <returns>	The elevation at point (longitude, latitude) or zero if no data/invalid data 
/// 			is found. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API float GetElevationAt( double longitude, double latitude, bool interpolate = true );


////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets elevation at a given latitude and longitude. </summary>
///
/// <param name="GW3DGeometry">  	The longitude, latitude points. </param>
///// <param name="interpolate">	(optional) Whether or not to apply the interpolation we use 
/// 							internally, versus just the pixel value.. </param>
///
/// <returns>	Fills in the elevation (Z) at each point of the geometry. This API is not flushed out
///				as in today, GeometryType of the geometry will not be modified.  This may change when 
///				when we release the API	
////////////////////////////////////////////////////////////////////////////////////////////////////
//GEOWEB3DENGINE_API GW3DResult FillElevations( GW3DGeometry &geometry, bool interpolate = true);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets elevation at a given latitude and longitude. </summary>
///
/// <param name="GW3DGeometry">  	The longitude, latitude points. </param>
///// <param name="interpolate">	(optional) Whether or not to apply the interpolation we use 
/// 							internally, versus just the pixel value.. </param>
///
/// <returns>	will clone your input GW3DGeometry and ensure return is 2.5, elevation(Z)
///				will be filled in.
////////////////////////////////////////////////////////////////////////////////////////////////////
//GEOWEB3DENGINE_API GW3DGeometryPtr GetElevations(GW3DGeometry &geometry, bool interpolate = true);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Queries information about a DEM. </summary>
///
/// <param name="raster">	The raster to query. </param>
/// <param name="query">	[out] The DEM query results. </param>
///
/// <returns>	GW3D_sOk if succeeded. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API GW3DResult QueryDem(Raster::RasterSourceHandle raster, DemQuery& query );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets the dem activity. </summary>
///
/// <remarks>	This function should only fail if handle does not point at a valid DEM.  Even upon 
/// 			success, though, your DEM will not necessarily appear, since that also depends on 
/// 			your location in the world and whether there is another DEM with greater priority covering the DEM associated with handle. </remarks>
///
/// <param name="handle">	The unique identifier for the DEM. </param>
/// <param name="activity">  The activity state. </param>
///
/// <returns>	GW3D_sOk is succeeded. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API GW3DResult SetDemActivity(Raster::RasterSourceHandle handle, const bool activity );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets a user data pointer. </summary>
///
/// <remarks>	Associates a pointer to user data with the DEM handle, so it can be retrived later 
/// 			via . </remarks>
///
/// <param name="raster">	The unique identifier for the DEM. </param>
/// <param name="p">		 	[in,out] If non-null, the void * to process. </param>
///
/// <returns>	. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API GW3DResult SetUserDataPtr(Raster::RasterSourceHandle raster, void *p );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the pointer set by SetUserDataPtr. </summary>
///
/// <remarks>	Used for referencing custom data to raster datasources. </remarks>
///
/// <param name="raster">	The raster datasource. </param>
///
/// <returns>	null if it fails, else the user data pointer. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API void* GetUserDataPtr(Raster::RasterSourceHandle raster );



	}
}


#endif
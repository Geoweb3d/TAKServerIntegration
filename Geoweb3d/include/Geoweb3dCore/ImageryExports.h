//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2018, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// Geoweb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef GEOWEB_IMAGERY_EXPORTS_H
#define GEOWEB_IMAGERY_EXPORTS_H


#include "Geoweb3dTypes.h"
#include "Geoweb3dExports.h"
#include "GeometryExports.h"
#include "../Geoweb3d/common/IGW3DDefinitionCollection.h"
/*! @file ImageryExports.h */

/*! Primary namespace */
namespace Geoweb3d
{

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Imagery Namespace </summary>
	///
	/// <remarks>	Interfaces in the Imagery namespace are part of the legacy C-like namespace. 
	///				Note: The C++ raster API has more capabilities than the legacy C-style API, however
	///				in other capabilities it does not yet have equivilancy.  See 
	/// 			IGW3DRasterDriverCollection to evaluate which capabilities are important to
	///				your use case before selecting which raster API to use. </remarks>
	///
	/// <see cref="IGW3DRasterDriverCollection"/>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	namespace Imagery
	{

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	An imagery query. </summary>
///
/// <remarks>	Query the extents and resolution of an imagery datasource. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

struct ImageryQuery
{
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	ImageryQuery() : 
		x_pixel_size( 0.0 ), y_pixel_size( 0.0 ),
		width( 0 ), height( 0 ),
		driver_long_name( 0 )
		{ }

	/// <summary>	X Resolution of the image in degrees. </summary>
	double x_pixel_size;
	/// <summary>	Y Resolution of the image in degrees. </summary>
	double y_pixel_size;

	/// <summary>	The width in pixels. </summary>
	int width;
	/// <summary>	The height in pixels. </summary>
	int height;

	/// <summary>	The envelope representing the imagery extents. </summary>
	GW3DEnvelope envelope;
 
	/// <summary>	Detailed name of the driver that loaded the imagery. </summary>
	const char* driver_long_name;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Imagery load properties. </summary>
///
/// <remarks>	Properties for configuring the Imagery file at load time </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

struct ImageryLoadProperties
{
	ImageryLoadProperties() 
		: priority( 0 )
		, use_image_invalid_color_( true )
		, user_defined_invalid_color_( false )
		, use_invalid_range_( false )
		, tolerance_range_( 0.f )
		, invalid_red_( 0.f )
		, invalid_blue_( 0.f )
		, invalid_green_( 0.f )
		, projection_error_threshold_( 0.f )
		, page_level_( 0 )
		, overlay_mode_(false)
		, resolution_mapping_(4)
		, activity(true)
	{}

	/// <summary>	The imagery priority (images with higher values display on top of lower priority images). </summary>
	int priority;

	/// <summary>	If the image supplies invalid values, pay attention to those as well. </summary>
	bool use_image_invalid_color_;

	/// <summary>	Use the invalid red, blue, green channels on top of use_image_invalid_color_ </summary>
	bool user_defined_invalid_color_;

	/// <summary>	Put in a range for invalid color </summary>
	bool use_invalid_range_;

	/// <summary>	Amount from invalid_red/green/blue a color can vary and will still be considered invalid. </summary>
	float tolerance_range_;

	/// <summary>	Normalized invalid red value (range 0 - 1). </summary>
	float invalid_red_;

	/// <summary>	Normalized invalid blue value (range 0 - 1) </summary>
	float invalid_blue_;

	/// <summary>	Normalized invalid green value (range 0 - 1) </summary>
	float invalid_green_;

	/// <summary>	Error tolerance for imagery reprojection. </summary>
	float projection_error_threshold_;

	/// <summary>	The page level. </summary>
	unsigned page_level_;

	/// <summary> Raster resolution mode.	false - fixed size texture for each node in the terrain tree.
	///										true - node texture resolution based on screen space error. </summary>
	bool overlay_mode_;

	/// <summary>	resolution mapping takes effect only if the overlay mode is set to true. 
	///				The value is a metric to determine a ratio between screen resolutions to native raster resolutions.
	///				Meaningful values may be [1 to 64]
	///				This value attempts to represents a worst case up-sampling from raster resoltuion to 
	///				screen resolution: [1 : auto_resolution_] pixel mapping.
	///				default is 4.				</summary>
	unsigned resolution_mapping_;
	/// <summary>	Initial activity state. </summary>
	bool activity;
	/// <summary>	world file details are provided in this propery, use them if this is true. </summary>
};


////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Falcoview POC/ProtoType.  Use at your own risk at this point. </summary>
////////////////////////////////////////////////////////////////////////////////////////////////////
enum GW3DMapScaleResolutionUnitsEnum
{

    GW3D_MAP_SCALE_DENOMINATOR = 0,
    GW3D_MAP_SCALE_NM = 1,
    GW3D_MAP_SCALE_MILE = 2,
    GW3D_MAP_SCALE_KILOMETER = 3,
    GW3D_MAP_SCALE_METERS = 4,
    GW3D_MAP_SCALE_YARDS = 5,
    GW3D_MAP_SCALE_FEET = 6,
    GW3D_MAP_SCALE_INCHES = 7,
    GW3D_MAP_SCALE_ARC_DEGREES = 8,
    GW3D_MAP_SCALE_ARC_MINUTES = 9,
    GW3D_MAP_SCALE_ARC_SECONDS = 10,
    GW3D_MAP_SCALE_WORLD = 11,
	GW3D_MAP_SCALE_MAX = 0xFFFF
};


GEOWEB3DENGINE_API GW3DResult SetMap(/*in*/ const char* map_source, /*in*/ const char* map_series, /*in*/ double scale_resolution, double resolution_for_cib, /*in*/GW3DMapScaleResolutionUnitsEnum scale_resolution_units, /*out*/Raster::RasterSourceHandle& ret_handle);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Invalidates coverage image cache. </summary>
///
/// <remarks>	Image cache is marked as invalid and coverage images are recreated as needed
/// 			on subsequent calls to SetMap. Cached images are not deleted from disk as a
/// 			result of this call. </remarks>
///
/// <returns>	GW3D_sOk if successful, an error code if not. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API GW3DResult InvalidateCoverageImageCache();

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets supported raster extension string. </summary>
///
/// <remarks>	should be able to pass this into a dialog box filter to load have it filter out 
/// 			rasters on the filesystem.  Note || is the delimiter used for MFC's browswer dialog 
/// 			class to filter extensions.</remarks>
///
/// <param name="delimiterstring">	(Optional) the delimiter string. </param>
///
/// <returns>	null if it fails, else the supported raster extension string. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API const char* GetSupportedRasterExtensionString( const char * delimiterstring = "||" );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets the 'no imagery' color. </summary>
///
/// <remarks>	Set the color used to detect that no imagery is detected in a specific area. For
/// 			example, an imagery file may have a black border where no data exists.	</remarks>
///
/// <param name="red">  	red. </param>
/// <param name="green">	green. </param>
/// <param name="blue"> 	blue. </param>
/// <param name="alpha">	alpha. </param>
///
/// <returns>	GW3D_sOk if successful, an error code if not. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API GW3DResult SetNoImageryColor(/*in*/ float red, /*in*/float green, /*in*/float blue, /*in*/float alpha );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Loads an imagery datasource. </summary>
///
/// <remarks>	Note that if this is called on the same file multiple times, GW3D_sAlreadyOpened 
/// 			will be returned, but handle will be valid.  The image will be considered active 
/// 			after being inserted.. </remarks>
///
/// <param name="url">			  	URL of the imagery file. </param>
/// <param name="projection_file">	The projection file. </param>
/// <param name="load_props">	  	The load properties. </param>
/// <param name="handle">		  	[out] The handle. </param>
///
/// <returns>	GW3D_sOk if successful, an error code if not. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API GW3DResult LoadImagery(/*in*/ const char* url, /*in*/ const char* projection_file, ImageryLoadProperties const& load_props, /*out*/ Raster::RasterSourceHandle& handle );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Queries a file. </summary>
///
/// <remarks>	Get information about an image. </remarks>
///
/// <param name="filename">	Filename of the file. </param>
/// <param name="query">   	[in,out] The query. </param>
///
/// <returns>	GW3D_sOk if successful, the appropriate error code otherwise. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API GW3DResult QueryFile( /*in*/const char* filename,		/*out*/Geoweb3d::Imagery::ImageryQuery& query );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Queries a file. </summary>
///
/// <remarks>	Get information about an image. </remarks>
///
/// <param name="file_handle">	Handle of the file. </param>
/// <param name="query">	  	[in,out] The query. </param>
///
/// <returns>	GW3D_sOk if successful, the appropriate error code otherwise. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API GW3DResult QueryFile( /*in*/Raster::RasterSourceHandle file_handle,	/*out*/Geoweb3d::Imagery::ImageryQuery& query );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Removes the imagery described by file_handle. </summary>
///
/// <remarks>	Unregisters an image with the engine SDK. </remarks>
///
/// <param name="file_handle">	[in,out] Handle of the file. </param>
///
/// <returns>	A GW3DResult. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API GW3DResult RemoveImagery(Raster::RasterSourceHandle &file_handle );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets image activity. </summary>
///
/// <remarks>	Deactivates or activates imagery for display.  
/// 			
/// 			This function should only fail if handle does not point at a valid image.  Even 
/// 			upon success, though, your imagery will not necessarily appear, since that also 
/// 			depends on your location in the world and whether there is another image with
///				greater priority covering the imagery associated with handle. </remarks>
///
/// <param name="handle">  	The handle. </param>
/// <param name="activity">	true to enable, false to disable. </param>
///
/// <returns>	A GW3DResult. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API GW3DResult SetImageActivity(Raster::RasterSourceHandle handle, const bool activity );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets user data pointer. </summary>
///
/// <remarks>	Ability to set a pointer to your own datastructure </remarks>
///
/// <param name="handle">	The handle. </param>
/// <param name="p">	 	The pointer. </param>
///
/// <returns>	A GW3DResult. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API GW3DResult SetUserDataPtr(Raster::RasterSourceHandle handle, void *p );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets user data pointer. </summary>
///
/// <remarks>	Gets the pointer set in SetUserDataPtr. </remarks>
///
/// <param name="handle">	The handle. </param>
///
/// <returns>	null if it fails, else the user data pointer. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API void* GetUserDataPtr( Raster::RasterSourceHandle  handle );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets image as overlay display mode. </summary>
///
/// <remarks>	Overlay mode causes the image to use better resolution choices internally, for 
/// 			example for map data. </remarks>
///
/// <param name="handle">   	The handle. </param>
/// <param name="isoverlay">	true to set image ot overlay mode, false for standard. </param>
///
/// <returns>	A GW3DResult. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API GW3DResult SetImageQuality(Raster::RasterSourceHandle handle, const bool quality );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets image's page level. </summary>
///
/// <remarks>	Page level determines when the image data is retrieved  relative to the view. </remarks>
///
/// <param name="handle">   	The handle. </param>
/// <param name="page_level">	page level </param>
///
/// <returns>	A GW3DResult. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API GW3DResult SetPageLevel(Raster::RasterSourceHandle handle, const unsigned page_level);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets image priority. </summary>
///
/// <remarks>	Image priority determines the rendering order of multiple raster images.  </remarks>
///
/// <param name="handle">   The handle. </param>
/// <param name="quality">	quality </param>
///
/// <returns>	A GW3DResult. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API GW3DResult SetPriority(Raster::RasterSourceHandle handle, const int quality);

}
}

#endif
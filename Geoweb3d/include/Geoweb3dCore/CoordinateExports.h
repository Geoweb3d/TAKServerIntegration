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

#include "Geoweb3dExports.h"

/*! @file CoordinateExports.h */

/*! Primary namespace */
namespace Geoweb3d
{
	/*! Coordinate namespace */
	namespace Coordinates
	{

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Cartesian to polar conversion. </summary>
///
/// <remarks>	The Geoweb3d Engine's internal mechanism from moving to Cartesian space into Polar 
/// 			coordinates. </remarks>
///
/// <param name="x">			 	The cartesian x coordinate. </param>
/// <param name="y">			 	The cartesian y coordinate. </param>
/// <param name="z">			 	The cartesian z coordinate. </param>
/// <param name="alpha">		 	[out] The alpha (Polar coordinate equal to geodetic longitude). </param>
/// <param name="beta">			 	[out] The beta (Polar coordinate equal to 90 degrees - geodetic 
/// 								latitude). </param>
/// <param name="r">			 	[out] The radius. </param>
/// <param name="target_radians">	(optional) If true, then alpha & beta will be in radians, else 
/// 								in degrees. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API void CartesianToPolar( const double &x, const double &y, const double &z, double& alpha, double& beta, double& r, bool target_radians = true );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Cartesian to geodetic conversion. </summary>
///
/// <remarks>	The Geoweb3d Engine's internal mechanism from moving to Cartesian space into 
/// 			Geodetic coordinates. </remarks>
///
/// <param name="x">			 	The cartesian x coordinate. </param>
/// <param name="y">			 	The cartesian y coordinate. </param>
/// <param name="z">			 	The cartesian z coordinate. </param>
/// <param name="longitude">	 	[out] The geodetic longitude. </param>
/// <param name="latitude">		 	[out] The geodetic latitude. </param>
/// <param name="r">			 	[out] The radius. </param>
/// <param name="target_radians">	(optional) If true, then longitude & latitude will be in radians, else in degrees. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API void CartesianToGeodetic( const double &x, const double &y, const double &z, double& longitude, double& latitude, double& r, bool target_radians = true );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Polar to cartesian conversion. </summary>
///
/// <remarks>	The Geoweb3d Engine's internal mechanism for moving from Polar coordinates into 
/// 			Cartesian space. </remarks>
///
/// <param name="alpha">		 	The alpha. </param>
/// <param name="beta">			 	The beta. </param>
/// <param name="r">			 	The radius. </param>
/// <param name="x">			 	[out] The cartesian X. </param>
/// <param name="y">			 	[out] The cartesian Y. </param>
/// <param name="z">			 	[out] The cartesian Z. </param>
/// <param name="source_radians">	(optional) If true, then alpha & beta are expected to be in 
/// 								radians, else degrees. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API void PolarToCartesian( const double &alpha, const double &beta, const double &r, double& x, double& y, double& z, bool source_radians = true );


////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Geodetic to cartesian. </summary>
///
/// <param name="lon">			 	The geodetic longitude. </param>
/// <param name="lat">			 	The geodetic latitude. </param>
/// <param name="r">			 	The radius. </param>
/// <param name="x">			 	[out] The cartesian X. </param>
/// <param name="y">			 	[out] The cartesian Y. </param>
/// <param name="z">			 	[out] The cartesian Z. </param>
/// <param name="source_radians">	(optional) If true, then lon & lat are expected to be in 
/// 								radians, else degrees </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API void GeodeticToCartesian( const double &lon, const double &lat, const double &r, double& x, double& y, double& z, bool source_radians = true );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets a quaternion. </summary>
///
/// <remarks>	Convenience function to convert a geodetic position and hpr into a quaternion.
/// 			
/// 			Given the usual parameterization of a quaternion, we keep the notation: 
/// 			w + xi + yj + zk
/// 			
/// 			Note that this function will automatically correct the rotation to the tangent 
/// 			plane of the sphere at the position specified. </remarks>
///
/// <param name="lon">	  	Geodetic longitude in degrees. </param>
/// <param name="lat">	  	Geodetic latitude in degrees. </param>
/// <param name="elev">   	Height above the terrain. </param>
/// <param name="heading">	Heading, in degrees. </param>
/// <param name="pitch">  	Pitch, in degrees. </param>
/// <param name="roll">   	Roll, in degrees </param>
/// <param name="qx">	  	[out] X parameter of the quat </param>
/// <param name="qy">	  	[out] Y parameter of the quat </param>
/// <param name="qz">	  	[out] Z parameter of the quat </param>
/// <param name="qw">	  	[out] W parameter of the quat </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API void GetQuaternion
			( 
				const double &lon, const double& lat, const double &elev,
				const double &heading, const double &pitch, const double &roll,
				double& qx, double& qy, double& qz, double& qw
			);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the major radius of the earth. </summary>
///
/// <remarks>	Note: currently in Geoweb3d, the earth is a sphere. </remarks>
///
/// <returns>	The radius of the earth sphere. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API double MajorRadius();

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Page level to meter radius. </summary>
///
/// <remarks>	Convert the paging level used for DEM and Vector data into a useful, real world 
/// 			metric. 
/// 			
/// 			Note that depending on the configuration of the maximum terrain LOD depth in 
/// 			Geoweb3d::IGW3DInitializationConfiguration, the value returned for a given page 
/// 			level can vary.</remarks>
///
/// <param name="page_level">	The page level. </param>
///
/// <returns>	The distance in meters at which data will begin ot become visible. </returns>
/// 
/// <see cref="Geoweb3d::IGW3DInitializationConfiguration::put_TerrainMaxLODDepth"/>
////////////////////////////////////////////////////////////////////////////////////////////////////

GEOWEB3DENGINE_API double PageLevelToMeterRadius( int page_level );

	}
}

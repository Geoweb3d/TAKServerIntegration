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

namespace Geoweb3d
{
	 ////////////////////////////////////////////////////////////////////////////////////////////////////
	 /// <summary>	An elevation parameters. </summary>
	 ///
	 /// <remarks>	Ignore - Not used in external SDK. </remarks>
	 ////////////////////////////////////////////////////////////////////////////////////////////////////

	 struct GW3D_DLL ElevationParameters
	{
		 virtual  ~ElevationParameters() {}
		/*! Comparison function for invalid elevation values (INVALID_VALUE) */
		enum OpType
		{
			DEM_EQ = 0, /*! if( point == invalid_elevation_value ) discard; */
			DEM_LEQ	=1	/*! if( point <= invalid_elevation_value ) discard; */
		};
			
		enum IndividualParameters
		{
			DEM_BAND	       = 0,
			INVALID_VALUE      = 1,
			INVALID_COMPARITOR = 2,
			VERTICAL_SCALE	   = 3,
			ENOUSE_MAX= 0xff
		};
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	An imagery parameters. </summary>
	///
	/// <remarks>	Ignore - Not used in external SDK. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	struct GW3D_DLL ImageryParameters
	{
		virtual  ~ImageryParameters() {}

		enum IndividualParameters
		{
			R_BAND	= 0,
			G_BAND	= 1,
			B_BAND	= 2,
			INOUSE_MAX	= 0xff
		};
	};
}

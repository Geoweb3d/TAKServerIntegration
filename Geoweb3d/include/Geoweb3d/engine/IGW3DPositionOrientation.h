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

/*! Primary namespace */
namespace Geoweb3d
{
	extern "C++"
	{
		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Position controller. </summary>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		struct  GW3D_DLL IGW3DPositionOrientation
		{
			virtual ~IGW3DPositionOrientation() {}

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Enum of possible elevation modes for a position. </summary>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			enum AltitudeMode
			{
				//<summary> What you set the elevation to will be the final elevation in MSL.</summary>
				Absolute = 0,
				//<summary> The elevation you set will be an offset from the terrain elevation.</summary>
				Relative = 1,
				//SKIP-CODE-BEGIN
						//First_Surface_Relative * Not Yet Implimented*
						//The elevation you set will be an offset from the highest first surface detected.
						// Q: Should we add an API to give a collection of points or envolopes for this mode?
						//    This mode(if we give multiple points), will probably need to also
						//	  control HPR as well (Think of a boat on water with waves)
						//First_Surface_Relative = 2,
				//SKIP-CODE-END
				MAX_MODE = 0xFFFF
			};

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Enum of possible navigation restriction modes. </summary>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			enum NavigationRestrictionMode
			{
				//<summary> free to move everywhere </summary>
				UNRESTRICTED = 0,		//default
				//<summary> values set put_elevation will be altered for conformance</summary>
				ABOVE_GROUND_ONLY = 1,

				NAVIGATION_RESTRICTION_MODE_MAX_MODE = 0xFFFF
			};

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets the Navigation Restriction Mode. </summary>
			///
			///
			/// <param name="nav_mode"> the navigation mode </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void put_NavigationRestrictionMode(NavigationRestrictionMode nav_mode) = 0; //UNRESTRICTED by default

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary> Gets the Navigation Restriction Mode. </summary>
			///
			///
			/// <returns>	the navigation mode  </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual NavigationRestrictionMode get_NavigationRestrictionMode() const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets the location. </summary>
			///
			/// <param name="longitude">	The longitude. </param>
			/// <param name="latitude"> 	The latitude. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void put_Location(const double& longitude, const double& latitude) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the location. </summary>
			///
			/// <param name="longitude">	[out] The longitude. </param>
			/// <param name="latitude"> 	[out] The latitude. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void get_Location(double& longitude, double& latitude) const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets the elevation. </summary>
			///
			///	 <remarks> Note: If there is a NavigationRestrictionMode set your value may be altered for proper
			///				conformance based on the current or future elevation at this location. </remarks>
			///
			/// <param name="elevation">	The elevation. </param>
			/// <param name="mode">			(Optional) the elevation mode. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void put_Elevation(const double& elevation, AltitudeMode mode = Absolute) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the elevation. </summary>
			///
			/// <param name="elevation">	[out] The elevation. </param>
			/// <param name="mode">			[out] The mode. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void get_Elevation(double& elevation, AltitudeMode& mode) const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the location. </summary>
			///
			/// <remarks>	get_Location will return the real position the camera is in the real world. It's
			///				valid at the point in time you query it.  Note, this is not a cached value inside
			///				the sdk.  Everytime you call get_Location it does work.  Thus, if you need to
			///				call into this api a few times each frame, its better you cache your value
			///				and use it to avoid the extra CPU overhead. </remarks>
			///
			/// <returns>	the location. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual  const GW3DPoint* get_Location() = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Enum of possible pitch clamp conventions. </summary>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			enum PitchClampMode
			{
				//<summary> Pitch will be clamped to within -90 and 90. </summary>
				PITCH_90 = 0,
				//<summary> No pitch clamp applied. </summary>
				NO_PTICH_CLAMP = 1,
			};

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets the pitch clamp convention. </summary>	
			///
			/// <param name="pitch_clamp_mode">	See PitchClampMode. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void put_PitchClamp(PitchClampMode pitch_clamp_mode = PitchClampMode::NO_PTICH_CLAMP) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets the pitch clamp convention. </summary>	
			///
			/// <param name="pitch_clamp_mode">	See PitchClampMode. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual PitchClampMode get_PitchClamp() const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets the rotation. </summary>	
			///
			/// <param name="heading">	The heading. </param>
			/// <param name="pitch">  	The pitch. </param>
			/// <param name="roll">   	The roll. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void put_Rotation(float heading, float pitch, float roll) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the rotation. </summary>
			///
			/// <param name="heading">	[out] The heading. </param>
			/// <param name="pitch">  	[out] The pitch. </param>
			/// <param name="roll">   	[out] The roll. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void get_Rotation(float& heading, float& pitch, float& roll) const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets the heading. </summary>
			///
			/// <param name="heading">	The heading. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void put_Heading(float heading) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the heading. </summary>
			///
			/// <returns>	The heading. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual float get_Heading() const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets the pitch. </summary>
			///
			/// <param name="pitch">  	The pitch. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void put_Pitch(float pitch) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the pitch. </summary>
			///
			/// <returns>  	The pitch. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual float get_Pitch() const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets the roll. </summary>
			///
			/// <param name="roll">   	The roll. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void put_Roll(float roll) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the roll. </summary>
			///
			/// <returns>   	The roll. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual float get_Roll() const = 0;
		};

		struct  GW3D_DLL IGW3DOffsetPositionOrientation
		{
			virtual ~IGW3DOffsetPositionOrientation() {}

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets the location. </summary>
			///
			/// <param name="forward">	The forward offset. </param>
			/// <param name="up"> 	The up offset. </param>
			/// <param name="right"> 	The right offset. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void put_Location(const double& forward, const double& up, const double& right) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the location. </summary>
			///
			/// <param name="forward">	[out] The forward offset. </param>
			/// <param name="up"> 	[out] The up offset. </param>
			/// <param name="right"> 	[out] The right offset. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void get_Location(double& forward, double& up, double& right) const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the location. </summary>
			///
			/// <remarks>	get_Location will return then cartesian coordinate offset. </remarks>
			///
			/// <returns>	the location. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual  const GW3DPoint* get_Location() = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets the rotation. </summary>	
			///
			/// <param name="heading">	The heading. </param>
			/// <param name="pitch">  	The pitch. </param>
			/// <param name="roll">   	The roll. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void put_Rotation(float heading, float pitch, float roll) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the rotation. </summary>
			///
			/// <param name="heading">	[out] The heading. </param>
			/// <param name="pitch">  	[out] The pitch. </param>
			/// <param name="roll">   	[out] The roll. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void get_Rotation(float& heading, float& pitch, float& roll) const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets the heading. </summary>
			///
			/// <param name="heading">	The heading. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void put_Heading(float heading) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the heading. </summary>
			///
			/// <returns>	The heading. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual float get_Heading() const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets the pitch. </summary>
			///
			/// <param name="pitch">  	The pitch. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void put_Pitch(float pitch) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the pitch. </summary>
			///
			/// <returns>  	The pitch. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual float get_Pitch() const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets the roll. </summary>
			///
			/// <param name="roll">   	The roll. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void put_Roll(float roll) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the roll. </summary>
			///
			/// <returns>   	The roll. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual float get_Roll() const = 0;
		};
	}
}
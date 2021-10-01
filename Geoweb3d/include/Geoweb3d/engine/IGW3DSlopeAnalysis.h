//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2016, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// Geoweb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////

#pragma once

#include "IGW3DRegionOfInterest.h"
#include "IGW3DAnalysis.h"

/*! Primary namespace */
namespace Geoweb3d
{
	extern "C++"
	{
		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	A slope analysis. </summary>
		///
		/// <remarks>	The Geoweb3d slope analysis provides a visual display of surface slopes. </remarks>
		////////////////////////////////////////////////////////////////////////////////////////////////////
		struct  IGW3DSlopeAnalysis : public IGW3DRegionOfInterest, public IGW3DAnalysis
		{
			virtual ~IGW3DSlopeAnalysis() {}
			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the inner radius for the slope analysis. </summary>
			///
			/// <returns>	 </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual double get_InnerRadius() const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets the inner radius for the slope analysis.	 </summary>
			///
			/// <remarks>	 </remarks>
			///
			/// <param name="inRad"> </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual GW3DResult put_InnerRadius(const double& inRad) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the outer radius for the slope analysis.	 </summary>
			///
			/// <returns>	 </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual double get_OuterRadius() const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets the outerradius for the slope analysis.	 </summary>
			///
			/// <remarks>	 </remarks>
			///
			/// <param name="outRad">  </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual GW3DResult put_OuterRadius(const double& outRad) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Assign a color lookup table finalization token. </summary>
			///
			/// <remarks>	This function assigns a color lookup table finalization token as the color lookup 
			///				table that is utilized by this IGW3DSlopeAnalysis. A color lookup finalization
			///				token is a finalized configuration of an IGW3DColorLookupTablePtr, which is created 
			///				using the IGW3DSceneGraphContext interface. Needs to be assigned in order to visualize
			///				the test. </remarks>
			///
			/// <param name="color_lut">	The color lookup table. </param>
			/// 
			/// <see cref="IGW3DSceneGraphContext, IGW3DColorLookupTablePtr"/>
			///
			/// <returns>	GW3D_sOk if succeeded. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual GW3DResult put_GW3DFinalizationToken(IGW3DColorLookupTableFinalizationTokenPtr color_lut) = 0;
		};
	}
}

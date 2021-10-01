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

/*! Primary namespace */
namespace Geoweb3d
{
	struct  GW3D_DLL IGW3DBridgedIdentityTest
	{
		virtual bool get_IsValidToCheckAnyResults() = 0;

		virtual IGW3DLineSegmentIntersectionDetailCollection *get_LineSegmentIntersectionDetailCollection(IGW3DVectorRepresentationWPtr &rep_of_interest) = 0;
	};
}
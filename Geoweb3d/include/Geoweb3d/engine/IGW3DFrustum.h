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
		/// <summary>	A frustum </summary>
		////////////////////////////////////////////////////////////////////////////////////////////////////
		struct  GW3D_DLL IGW3DFrustum
		{
			virtual ~IGW3DFrustum(){}
			virtual void put_LeftPlane(const double& lp) = 0;
			virtual double get_LeftPlane() const = 0;

			virtual void put_RightPlane(const double& rp) = 0;
			virtual double get_RightPlane() const = 0;

			virtual void put_BottomPlane(const double& bp) = 0;
			virtual double get_BottomPlane() const = 0;

			virtual void put_TopPlane(const double& tp) = 0;
			virtual double get_TopPlane() const = 0;

			virtual GW3DResult put_NearPlane(const double& np) = 0;
			virtual double get_NearPlane() const = 0;

			virtual GW3DResult put_FarPlane(const double& fp) = 0;
			virtual double get_FarPlane() const = 0;

			//<summary put_FrustumHelper will fill in the plane settings, making it so
			// you don't have to figure out the top/bottom,right, and left plane
			// <summary> FieldOfView: field of view angle (degrees) </summary>
			// <summary> AspectRatio: of width/height </summary>
			// <summary> NearPlane: near plane distance from origin point (meters) </summary>
			// <summary> FarPlane: far plane distance from origin point (meters)  </summary>
			virtual GW3DResult put_FrustumHelper(const double& FieldOfView, const double& AspectRatio, const double& NearPlane, const double& FarPlane) = 0;
		};
	}
}
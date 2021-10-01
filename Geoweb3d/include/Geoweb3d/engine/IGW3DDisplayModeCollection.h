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
#include "../core/IGW3DCollection.h"
#include "IGW3DPositionOrientation.h"

/*! Primary namespace */
namespace Geoweb3d
{
	extern "C++"
	{
		struct GW3D_DLL IGW3DDisplayModeCollection : public IGW3DCollection< IGW3DDisplayModePtr >
		{
			virtual ~IGW3DDisplayModeCollection() {}
		};
	}
}
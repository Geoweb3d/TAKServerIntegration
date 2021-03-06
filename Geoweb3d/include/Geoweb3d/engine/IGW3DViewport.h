//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2019, all rights reserved.
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
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	A Viewport </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	struct IGW3DViewport
	{
		virtual int get_X() const = 0;
		virtual int get_Y() const = 0;
		virtual int get_Width() const = 0;
		virtual int get_Height() const = 0;
	};
}
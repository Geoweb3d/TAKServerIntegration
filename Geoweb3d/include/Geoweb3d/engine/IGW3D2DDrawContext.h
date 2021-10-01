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
		//
		//
		////////////////////////////////////////////////////////////////////////////////////////////////////

		struct GW3D_DLL IGW3D2DDrawContext
		{
			virtual void draw_Text(
				const IGW3DFontWPtr& font,
				int x, int y,
				float r, float g, float b, float a,
				const char* text) = 0; //note, utf-8 might not work with.. aka.. why this is POC
		};

	}
}
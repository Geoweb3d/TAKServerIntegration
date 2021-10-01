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
#include "../core/IGW3DClientUserData.h"
namespace Geoweb3d
{
	extern "C++"
	{
		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	An OpenGLTexture. </summary>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		struct  GW3D_DLL IGW3DOpenGLTexture : public IGW3DClientUserData
		{
			virtual ~IGW3DOpenGLTexture() {}

			virtual int		get_PropertyCollectionID() const = 0;
			virtual int		get_Width() const = 0;
			virtual int		get_Height() const = 0;
			virtual bool	get_IsOwner() const = 0;

			//will preserver the currently bound texture id.
			//will readback mip 0's width and height
			virtual void	put_ReadBackGPUParametersNow() = 0;
		};
	}
}
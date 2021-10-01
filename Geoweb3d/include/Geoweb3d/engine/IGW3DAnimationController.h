//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2020, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// Geoweb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../core/GW3DInterFace.h"
#include <Geoweb3dCore/Geoweb3dTypes.h>
extern "C++"
{
	/*! Primary namespace */
	namespace Geoweb3d
	{
		struct IGW3DAnimationPathPlaybackEventCallback;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	A animation control interface used to create animation paths as well animation play
		///             back object.
		/// </summary>
		////////////////////////////////////////////////////////////////////////////////////////////////////
		struct GW3D_DLL IGW3DAnimationController
		{
		public:

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary> Creates an IGW3DAnimationPath</summary>
			///
			/// <returns>	[out] The IGW3DAnimationPath. </returns>
			///
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual IGW3DAnimationPathPtr create_AnimationPath() = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary> Creates an IGW3DAnimationPath from a tour file.</summary>
			///
			/// <returns>	[out] The IGW3DAnimationPath. </returns>
			///
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual IGW3DAnimationPathPtr create_AnimationPathFromFile(const char* filename) = 0;

			/// <summary> Creates an animation path playback object and associates it with the given path.</summary>
			///
			/// <param name="path"></param>
			/// <param name="pCallback"></param>
			/// <returns>[out] The IGW3DAnimationPathPlayback.</returns>
			virtual IGW3DAnimationPathPlaybackWPtr create_AnimationPathPlayback(const IGW3DAnimationPathPtr& path, IGW3DAnimationPathPlaybackEventCallback* pCallback = 0) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary> Destroys a previously created IGW3DAnimationPath object</summary>
			///
			/// <returns>	[out] True if the path was successfully destroyed, false otherwise. </returns>
			///
			////////////////////////////////////////////////////////////////////////////////////////////////////
			virtual bool destroy_AnimationPath(const IGW3DAnimationPathPtr& path) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary> Destroys a previously created IGW3DAnimationPathPlayback object</summary>
			///
			/// <returns>	[out] True if the playback object was successfully destroyed, false otherwise. </returns>
			///
			////////////////////////////////////////////////////////////////////////////////////////////////////
			virtual bool destroy_AnimationPathPlayback(IGW3DAnimationPathPlaybackWPtr playback) = 0;

		};
	}
}
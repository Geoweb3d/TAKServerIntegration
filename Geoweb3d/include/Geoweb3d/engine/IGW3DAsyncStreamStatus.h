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
#include <Geoweb3dCore/GW3DResults.h>

namespace Geoweb3d
{
	struct IGW3DAsyncStreamStatus
	{
		enum async_task_state
		{
			TSK_RUNNING = 0x00,
			TSK_CANCELED = 0x01,
			TSK_SUCCESS = 0x02,
			TSK_FAILURE = 0x03
		};

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Cancel the Task if still outstanding. </summary>
		///
		/// <remarks>	If you set off an asynchronous operation and no longer want it, this
		///				will try to cancel it. </remarks>
		////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual void cancel_operation() = 0;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary> Checks if the task is complete. </summary>
		///
		/// <returns>	Returns a bool result. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual async_task_state is_finished() = 0;
	};
};

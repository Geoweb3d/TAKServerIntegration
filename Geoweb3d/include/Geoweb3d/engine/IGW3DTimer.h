//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2013, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// GoeWeb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../core/GW3DInterFace.h"
#include <Geoweb3dCore/Geoweb3dTypes.h>

/*! Primary namespace */
namespace Geoweb3d
{
    extern "C++"
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// <summary>	Timer. </summary>
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        struct GW3D_DLL IGW3DTimer
        {
            virtual ~IGW3DTimer() {}

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Starts this timer. </summary>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual void start() = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Pauses this timer. </summary>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual void pause() = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Resets this timer. </summary>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual void reset() = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Gets average time. </summary>
            ///
            /// <returns>	The average time. </returns>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual float get_AverageTime() = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Gets the time. </summary>
            ///
            /// <returns>	The time. </returns>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual float get_Time() = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Creates a timer. </summary>
            ///
            /// <param name="interface_version">	(optional) the interface version. </param>
            ///
            /// <returns>	A Timer. </returns>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            static IGW3DTimerPtr create(unsigned interface_version = GEOWEB3D_INTERFACE_VERSION);
        };
    }
}
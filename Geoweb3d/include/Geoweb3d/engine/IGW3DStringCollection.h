//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2018, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// Geoweb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../core/GW3DInterFace.h"
#include "../core/IGW3DCollection.h"
/*! Primary namespace */
namespace Geoweb3d
{	
struct IGW3DStringCollection : public IGW3DCollection< IGW3DStringPtr >
{
    virtual const IGW3DStringPtr operator[](  unsigned long index ) const = 0;
    virtual const IGW3DStringPtr get_AtIndex( unsigned long index ) const = 0;
};
}

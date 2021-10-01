/**
 * Property of Geoweb3d Inc.
 * --------------------------------
 * Copyright 2008-2011
 * Author: Vincent A. Autieri, Geoweb3d
 * Geoweb3d source code is not free software: you cannot distribute,
 * redistribute, and/or modify it under any terms.
 **/

#pragma once

#include "../core/GW3DInterFace.h"
namespace Geoweb3d
{
struct	IGW3DVec2fBufferObject;
_GW3D_SMARTPTR_TYPEDEF( IGW3DVec2fBufferObject );

struct Vec2fRaw
{
    float x;
    float y;
}

struct IGW3DVec2fBufferObjectCollection : public IGW3DCollection< Vec2fRaw* >, public IGW3DIBaseObject
{

}
struct IGW3DVec2fBufferObject
{
    virtual IGW3DVec2fBufferObjectCollection * get_Collection(  ) = 0;
};
}

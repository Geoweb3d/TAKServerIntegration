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
struct	IGW3DUnsignedIntBufferObject;
_GW3D_SMARTPTR_TYPEDEF( IGW3DUnsignedIntBufferObject );

struct IGW3DUnsignedIntCollection : public IGW3DCollection< unsigned int* >, public IGW3DIBaseObject
{

}

struct IGW3DUnsignedIntBufferObject
{
    virtual IGW3DUnsignedIntCollection * get_Collection(  ) = 0;
};
}



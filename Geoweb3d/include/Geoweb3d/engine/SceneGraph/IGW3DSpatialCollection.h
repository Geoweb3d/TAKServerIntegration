/**
 * Property of Geoweb3d Inc.
 * --------------------------------
 * Copyright 2008-2011
 * Author: Vincent A. Autieri, Geoweb3d
 * Geoweb3d source code is not free software: you cannot distribute,
 * redistribute, and/or modify it under any terms.
 **/

#pragma once

#include "../../core/GW3DInterFace.h"
namespace Geoweb3d
{
//here an not in the interface..as this is not implimented stuff..
struct	IGW3DSpatialCollection;
_GW3D_SMARTPTR_TYPEDEF( IGW3DSpatialCollection );

struct IGW3DSpatialCollection : public IGW3DCollection< IGW3DSpatialPtr >, public IGW3DIBaseObject
{
    //vaa note, use standardized naming.. todo
    int detachChild(IGW3DSpatialPtr child);
    virtual int attachChild(SpatialPtr child);
    virtual void detachChildAt(int index);
    virtual void put_Child(int index, SpatialPtr child);
}

}



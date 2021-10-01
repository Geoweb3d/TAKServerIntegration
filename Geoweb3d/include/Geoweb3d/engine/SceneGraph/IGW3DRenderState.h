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

//SKIP-CODE-BEGIN

struct	IGW3DRenderState;
_GW3D_SMARTPTR_TYPEDEF( IGW3DRenderState );

struct IGW3DRenderState
{
    //maybe just these states for now...use our property object? tbd
    enum StateType
    {
        DEPTH,
        FRONT_FACE,
        CULL_FACE,
        POLYGON_MODE,
        POLYGON_OFFSET,
        COLOR,
        NORMAL,
        MAX_STATE_TYPE
    } ;
}

struct IGW3DRenderState
{

}

//SKIP-CODE-END
}



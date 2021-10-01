/**
 * Property of Geoweb3d Inc.
 * --------------------------------
 * Copyright 2008-2011
 * Author: Vincent A. Autieri, Geoweb3d
 * Geoweb3d source code is not free software: you cannot distribute,
 * redistribute, and/or modify it under any terms.
 **/

#pragma once

#include "Geoweb3d.hpp"

namespace Geoweb3d
{
struct	IGW3DTriangleMesh;
_GW3D_SMARTPTR_TYPEDEF( IGW3DTriangleMesh )

struct IGW3DTriangleMesh : public IGW3DGeometry
{
    IGW3DTriangleMesh();
    IGW3DTriangleMesh(IGW3DVector3BufferObjectPtr vertices, IGW3DVector3BufferObjectPtr normals, IGW3DVector2BufferObjectPtr uvs, IGW3DUnsignedIntBufferObjectPtr indices);
} ;
}



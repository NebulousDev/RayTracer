#pragma once
#include "common.h"
#include "shapes.h"
#include "material.h"
#include "camera.h"

struct Scene
{
    Material*   pMaterials;
    uint32      materialCount;

    Plane*      pPlanes;
    uint32      planeCount;

    Sphere*     pSpheres;
    uint32      sphereCount;

    Camera      camera;
};
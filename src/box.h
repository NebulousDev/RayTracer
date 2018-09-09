#include "common.h"
#include "vector.h"

template<typename T>
struct AABB2
{
    Vec2<T> min, max;
};

template<typename T>
struct AABB3
{
    Vec3<T> min, max;
};

/* Typedefs */

typedef AABB2<float32>  AABB2f;
typedef AABB2<int32>    AABB2i;
typedef AABB2<uint32>   AABB2u;

typedef AABB3<float32>  AABB3f;
typedef AABB3<int32>    AABB3i;
typedef AABB3<uint32>   AABB3u;

/* Useful functions */

AABB2f createAABBFromPoint(const Point2f point)
{
    return AABB2f { Vec2f {0,0}, point };
}

AABB3f createAABBFromPoint(const Point3f point)
{
    return AABB3f { Vec3f {0,0,0}, point };
}
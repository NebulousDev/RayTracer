#pragma once
#include "common.h"
#include "math.h"

// Two element vector
template<typename T>
union Vec2
{
    struct { T x, y; };
    struct { T r, g; };
    struct { T u, v; };
    T elements[3];
};

// Three element vector
template<typename T>
union Vec3
{
    struct { T x, y, z; };
    struct { T r, g, b; };
    struct { T u, v, w; };
    T elements[3];
};

// Four element vector
template<typename T>
union Vec4
{
    struct { T x, y, z, w; };
    struct { T r, g, b, a; };
    T elements[4];
};

// Two element vector with an origin
template<typename T>
union Ray2
{
    struct
    {
        Vec2<T>     origin;
        Vec2<T>     direction;
        mutable T   length;
    };
   
    struct
    {
        T ox, oy, dx, dy;
        mutable T length;
    };
};

// Three element vector with an origin
template<typename T>
struct Ray3
{
    struct
    {
        Vec3<T>     origin;
        Vec3<T>     direction;
        mutable T   length;
    };
   
    struct
    {
        T ox, oy, oz, dx, dy, dz;
        mutable T length;
    };
};

/* Typedefs */

typedef Vec2<int32>     Vec2i;
typedef Vec3<int32>     Vec3i;
typedef Vec4<int32>     Vec4i;

typedef Vec2<uint32>    Vec2u;
typedef Vec3<uint32>    Vec3u;
typedef Vec4<uint32>    Vec4u;

typedef Vec2<float32>   Vec2f;
typedef Vec3<float32>   Vec3f;
typedef Vec4<float32>   Vec4f;

typedef Vec2<int32>     Point2i;
typedef Vec3<int32>     Point3i;
typedef Vec4<int32>     Point4i;

typedef Vec2<uint32>    Point2u;
typedef Vec3<uint32>    Point3u;
typedef Vec4<uint32>    Point4u;

typedef Vec2<float32>   Point2f;
typedef Vec3<float32>   Point3f;
typedef Vec4<float32>   Point4f;

typedef Vec2<float32>   Norm2f;
typedef Vec3<float32>   Norm3f;

typedef Vec3<float32>   Color3f;
typedef Vec4<float32>   Color4f;

typedef Ray2<int32>     Ray2i;
typedef Ray3<int32>     Ray3i;

typedef Ray2<uint32>    Ray2u;
typedef Ray3<uint32>    Ray3u;

typedef Ray2<float32>   Ray2f;
typedef Ray3<float32>   Ray3f;

/* World Definitions */

#define WORLD_FORWARD   Vec3<float32> { 0.0f, 0.0f, 1.0f }
#define WORLD_RIGHT     Vec3<float32> { 1.0f, 0.0f, 0.0f }
#define WORLD_UP        Vec3<float32> { 0.0f, 1.0f, 0.0f }

/* Vec2 Functions */

// Negation //

template<typename T>
inline Vec2<T> operator-(const Vec2<T> v)
{ 
    return Vec2<T> { -v.x, -v.y };
}

// Addition //

template<typename T>
inline Vec2<T> operator+(const Vec2<T> v1, const Vec2<T> v2)
{
    return Vec2<T> { v1.x + v2.x, v1.y + v2.y };
}

template<typename T>
inline Vec2<T>& operator+=(Vec2<T>& v1, const Vec2<T> v2)
{ 
    v1.x += v2.x;
    v1.y += v2.y;
    return v1; 
}

// Subtraction //

template<typename T>
inline Vec2<T> operator-(const Vec2<T> v1, const Vec2<T> v2)
{ 
    return Vec2<T> { v1.x - v2.x, v1.y - v2.y }; 
}

template<typename T>
inline Vec2<T>& operator-=(Vec2<T>& v1, const Vec2<T> v2)
{ 
    v1.x -= v2.x;
    v1.y -= v2.y;
    return v1; 
}

// Multiplication //

template<typename T>
inline Vec2<T> operator*(const Vec2<T> v1, const Vec2<T> v2)
{
    return Vec2<T> { v1.x * v2.x, v1.y * v2.y };
}

template<typename T>
inline Vec2<T> operator*(const Vec2<T> v1, const T val)
{
    return Vec2<T> { v1.x * val, v1.y * val };
}

template<typename T>
inline Vec2<T>& operator*=(Vec2<T>& v1, const Vec2<T> v2)
{ 
    v1.x *= v2.x;
    v1.y *= v2.y;
    return v1; 
}

template<typename T>
inline Vec2<T>& operator*=(Vec2<T>& v1, const T val)
{ 
    v1.x *= val;
    v1.y *= val;
    return v1; 
}

// Division //

template<typename T>
inline Vec2<T> operator/(const Vec2<T> v1, const Vec2<T> v2)
{
    return Vec2<T> { v1.x / v2.x, v1.y / v2.y };
}

template<typename T>
inline Vec2<T> operator/(const Vec2<T> v1, const T val)
{
    return Vec2<T> { v1.x / val, v1.y / val };
}

template<typename T>
inline Vec2<T>& operator/=(Vec2<T>& v1, const Vec2<T> v2)
{ 
    v1.x /= v2.x;
    v1.y /= v2.y;
    return v1; 
}

template<typename T>
inline Vec2<T>& operator/=(Vec2<T>& v1, const T val)
{ 
    float inverse = 1.0f / val;
    v1.x *= inverse;
    v1.y *= inverse;
    return v1; 
}

/* Vec3 Functions */

// Negation //

template<typename T>
inline Vec3<T> operator-(const Vec3<T> v)
{
    return Vec3<T> { -v.x, -v.y, -v.z };
}

// Addition //

template<typename T>
inline Vec3<T> operator+(const Vec3<T> v1, const Vec3<T> v2)
{
    return Vec3<T> { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
}

template<typename T>
inline Vec3<T>& operator+=(Vec3<T>& v1, const Vec3<T> v2)
{ 
    v1.x += v2.x;
    v1.y += v2.y;
    v1.z += v2.z;
    return v1; 
}

// Subtraction //

template<typename T>
inline Vec3<T> operator-(const Vec3<T> v1, const Vec3<T> v2)
{
    return Vec3<T> { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z };
}

template<typename T>
inline Vec3<T>& operator-=(Vec3<T>& v1, const Vec3<T> v2)
{ 
    v1.x -= v2.x;
    v1.y -= v2.y;
    v1.z -= v2.z;
    return v1; 
}

// Multiplication //

template<typename T>
inline Vec3<T> operator*(const Vec3<T> v1, const Vec3<T> v2)
{
    return Vec3<T> { v1.x * v2.x, v1.y * v2.y, v1.z * v2.z };
}

template<typename T>
inline Vec3<T> operator*(const Vec3<T> v1, const T val)
{
    return Vec3<T> { v1.x * val, v1.y *val, v1.z * val };
}

template<typename T>
inline Vec3<T>& operator*=(Vec3<T>& v1, const Vec3<T> v2)
{ 
    v1.x *= v2.x;
    v1.y *= v2.y;
    v1.z *= v2.z;
    return v1; 
}

template<typename T>
inline Vec3<T>& operator*=(Vec3<T>& v1, const T val)
{ 
    v1.x *= val;
    v1.y *= val;
    v1.z *= val;
    return v1; 
}

// Division //

template<typename T>
inline Vec3<T> operator/(const Vec3<T> v1, const Vec3<T> v2)
{
    return Vec3<T> { v1.x / v2.x, v1.y / v2.y, v1.z / v2.z };
}

template<typename T>
inline Vec3<T> operator/(const Vec3<T> v1, const float32 val)
{
    return Vec3<T> { v1.x / val, v1.y / val, v1.z / val };
}

template<typename T>
inline Vec3<T>& operator/=(Vec3<T>& v1, const Vec3<T> v2)
{ 
    v1.x /= v2.x;
    v1.y /= v2.y;
    v1.z /= v2.z;
    return v1; 
}

template<typename T>
inline Vec3<T>& operator/=(Vec3<T>& v1, const T val)
{ 
    float inverse = 1.0f / val;
    v1.x *= inverse;
    v1.y *= inverse;
    v1.z *= inverse;
    return v1; 
}

// SPECIAL //

template<typename T>
inline float32 dot(const Vec3<T> v1, const Vec3<T> v2)
{
    return v1.x * v2.x + v1.y + v2.y + v1.z + v2.z;
}

template<typename T>
inline Vec3<T> cross(const Vec3<T> v1, const Vec3<T> v2)
{
    return Vec3<T>
    { 
        v1.y * v2.z - v1.z * v2.y, 
        v1.z * v2.x - v1.x * v2.z, 
        v1.x * v2.y - v1.y * v2.x, 
    };
}

template<typename T>
inline float32 lengthSquared(const Vec3<T> v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

template<typename T>
inline float32 length(const Vec3<T> v)
{
    return sqrtf32(lengthSquared(v));
}

template<typename T>
inline Vec3<T> normalize(const Vec3<T> v)
{
    float32 len = lengthSquared(v);
    if(len > 0.00001f) return v * (1.0f / sqrtf32(len));
    else return Vec3<T> {};
}

/* Vec4 Functions */

// Negation //

template<typename T>
inline Vec4<T> operator-(const Vec4<T> v)
{
    return Vec4<T> { -v.x, -v.y, -v.z, -v.w };
}

// Addition //

template<typename T>
inline Vec4<T> operator+(const Vec4<T> v1, const Vec4<T> v2)
{
    return Vec4<T> { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w };
}

template<typename T>
inline Vec4<T>& operator+=(Vec4<T>& v1, const Vec4<T> v2)
{ 
    v1.x += v2.x;
    v1.y += v2.y;
    v1.z += v2.z;
    v1.w += v2.w;
    return v1; 
}

// Subtraction //

template<typename T>
inline Vec4<T> operator-(const Vec4<T> v1, const Vec4<T> v2)
{
    return Vec4<T> { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w };
}

template<typename T>
inline Vec4<T>& operator-=(Vec4<T>& v1, const Vec4<T> v2)
{ 
    v1.x -= v2.x;
    v1.y -= v2.y;
    v1.z -= v2.z;
    v1.w -= v2.w;
    return v1; 
}

// Multiplication //

template<typename T>
inline Vec4<T> operator*(const Vec4<T> v1, const Vec4<T> v2)
{
    return Vec4<T> { v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w };
}

template<typename T>
inline Vec4<T> operator*(const Vec4<T> v1, const float32 val)
{
    return Vec4<T> { v1.x * val, v1.y * val, v1.z * val, v1.w * val };
}

template<typename T>
inline Vec4<T>& operator*=(Vec4<T>& v1, const Vec4<T> v2)
{ 
    v1.x *= v2.x;
    v1.y *= v2.y;
    v1.z *= v2.z;
    v1.w *= v2.w;
    return v1; 
}

template<typename T>
inline Vec4<T>& operator*=(Vec4<T>& v1, const T val)
{ 
    v1.x *= val;
    v1.y *= val;
    v1.z *= val;
    v1.w *= val;
    return v1; 
}

// Division //

template<typename T>
inline Vec4<T> operator/(const Vec4<T> v1, const Vec4<T> v2)
{
    return Vec4<T> { v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w };
}

template<typename T>
inline Vec4<T> operator/(const Vec4<T> v1, const float32 val)
{
    return Vec4<T> { v1.x / val, v1.y / val, v1.z / val, v1.w / val };
}

template<typename T>
inline Vec4<T>& operator/=(Vec4<T>& v1, const Vec4<T> v2)
{ 
    v1.x /= v2.x;
    v1.y /= v2.y;
    v1.z /= v2.z;
    v1.w /= v2.w;
    return v1; 
}

template<typename T>
inline Vec4<T>& operator/=(Vec4<T>& v1, const T val)
{ 
    float inverse = 1.0f / val;
    v1.x *= inverse;
    v1.y *= inverse;
    v1.z *= inverse;
    v1.w *= inverse;
    return v1; 
}

/* Other vector functions */

inline void calcCoordsRight(const Vec3f& forward, Vec3f* pRight, Vec3f* pUp)
{
    *pRight = normalize(cross(normalize(forward), WORLD_UP));
    *pUp = normalize(cross(forward, *pRight));
}

inline void calcCoordsLeft(const Vec3f& forward, Vec3f* pRight, Vec3f* pUp)
{
    *pRight = normalize(cross(WORLD_UP, normalize(forward)));
    *pUp = normalize(cross(forward, *pRight));
}

inline Norm3f directNormal(Norm3f& norm, Vec3f& vec)
{
    return (dot(norm, vec) < 0.0f) ? -norm : norm;
}
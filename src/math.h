#include "common.h"

/* Defines */

#define PI32 3.14159265358979323846f
#define PI64 3.141592653589793238462643383279502884L
#define TAO32 (PI32 * 2.0f)
#define TAO64 (PI64 * 2.0L)


/* Trig Functions */


// Returns the sine of the given float value
extern float32 sinf32(const float32 val);

// Returns the cosine of the given float value
extern float32 cosf32(const float32 val);

// Returns the tangent of the given float value
extern float32 tanf32(const float32 val);

// Returns the arc sine of the given float value
extern float32 asinf32(const float32 val);

// Returns the arc cosine of the given float value
extern float32 acosf32(const float32 val);

// Returns the arc tangent of the given float value
extern float32 atanf32(const float32 val);


/* Algebra Functions */


// Returns square root of the given float value
extern float32 sqrtf32(const float32 val);


/* Other Functions */


// Returns the greater value
template<typename T>
inline T max(const T val0, const T val1)
{
    return val0 >= val1 ? val0 : val1;
}

// Returns the lesser value
template<typename T>
inline T min(const T val0, const T val1)
{
    return val0 <= val1 ? val0 : val1;
}
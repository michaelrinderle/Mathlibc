#ifndef CONSTANTS_H
#define CONSTANTS_H

// fundamental mathematical constants
#define MATH_PI                 3.14159265358979323846L
#define MATH_E                  2.71828182845904523536L
#define MATH_EULER_MASCHERONI   0.57721566490153286061L
#define MATH_GOLDEN_RATIO       1.61803398874989484820L

// square roots
#define MATH_SQRT2              1.41421356237309504880L
#define MATH_SQRT3              1.73205080756887729353L
#define MATH_SQRT5              2.23606797749978969640L

// logarithms
#define MATH_LN2                0.69314718055994530942L
#define MATH_LN10               2.30258509299404568402L

// Powers and reciprocals
#define MATH_PI_2               9.86960440108935861883L
#define MATH_SQRTPI             1.77245385090551602730L
#define MATH_1_PI               0.31830988618379067154L
#define MATH_2_PI               0.63661977236758134308L

// trigonometric constants
#define MATH_PI_2               1.57079632679489661923L
#define MATH_PI_4               0.78539816339744830962L
#define MATH_3PI_4              2.35619449019234492884L

// number theory constants
#define MATH_APERY              1.20205690315959428540L
#define MATH_CONWAY             1.30357726903429639126L
#define MATH_KHINCHIN           2.68545200106530644531L
#define MATH_GLAISHER           1.28242712910062263688L

// statistical constants
#define MATH_SQRT_2PI           2.50662827463100050242L
#define MATH_1_SQRT_2PI         0.39894228040143267794L

// calculus constants
#define MATH_BERNOULLI_2        0.16666666666666666667L  // Second Bernoulli number
#define MATH_BERNOULLI_4        -0.03333333333333333333L // Fourth Bernoulli number
#define MATH_BERNOULLI_6        0.02380952380952380952L  // Sixth Bernoulli number
#define MATH_EULER_NUMBER       2.71828182845904523536L  // Base of natural logarithm (same as E)
#define MATH_NAPIER_CONSTANT    1.00000000000000000000L  // Limit of (1 + 1/n)^n as n approaches infinity
#define MATH_EXPONENTIAL_DECAY  0.36787944117144232160L  // e^-1, used in exponential decay
#define MATH_NATURAL_LOG_2      0.69314718055994530942L  // Natural logarithm of 2
#define MATH_NATURAL_LOG_10     2.30258509299404568402L  // Natural logarithm of 10
#define MATH_GAMMA_EULER        0.57721566490153286061L  // Euler-Mascheroni constant (same as EULER_MASCHERONI)
#define MATH_LIOUVILLE_CONSTANT 0.11000100000000000000L  // Liouville's constant

// limits and special values
#define MATH_INFINITY           __builtin_inf()
#define MATH_NAN                __builtin_nan("")
#define MATH_FLT_EPSILON        1.19209290e-07F
#define MATH_DBL_EPSILON        2.22044604925031308085e-16L

// conversion factors
#define MATH_DEGREES_TO_RADIANS 0.01745329251994329577L
#define MATH_RADIANS_TO_DEGREES 57.29577951308232087680L

// limits for integer types
#define MATH_INT_MAX            2147483647
#define MATH_INT_MIN            (-2147483647 - 1)
#define MATH_UINT_MAX           4294967295U

#endif // CONSTANTS_H
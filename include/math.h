#ifndef MATH_H
#define MATH_H

typedef float float_t;
typedef double double_t;

#define M_E 2.71828182845904523536
#define M_LOG2E 1.44269504088896340736
#define M_LOG10E 0.434294481903251827651
#define M_LN2 0.693147180559945309417
#define M_LN10 2.30258509299404568402
#define M_PI 3.14159265358979323846
#define M_PI_2 1.57079632679489661923
#define M_PI_4 0.785398163397448309616
#define M_1_PI 0.318309886183790671538
#define M_2_PI 0.636619772367581343076
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2 1.41421356237309504880
#define M_SQRT1_2 0.707106781186547524401

#define NAN __builtin_nanf("")
#define INFINITY __builtin_inff()

#define HUGE_VALF INFINITY
#define HUGE_VAL (double) INFINITY
#define HUGE_VALL (long double) INFINITY

// #define FP_FAST_FMAF not defined
// #define FP_FAST_FMA not defined
// #define FP_FAST_FMAL not defined

// #define FP_ILOGB0 not defined
// #define FP_ILOGBNAN not defined

// #define math_errhandling not defined
// #define MATH_ERRNO not defined
// #define MATH_ERREXCEPT not defined

// #define FP_NORMAL not defined
// #define FP_SUBNORMAL not defined
// #define FP_ZERO not defined
// #define FP_INFINITE not defined
// #define FP_NAN not defined

float fabsf(float arg);
double fabs(double arg);
long double fabsl(long double arg);

// float fmodf(float x, float y);
// double fmod(double x, double y);
// long double fmodl(long double x, long double y);

// float remainderf(float x, float y);
// double remainder(double x, double y);
// float remainderl(long double x, long double y);

// float remquof(float x, float y, int *quo);
// double remquo(double, double, int *quo);
// long double remquol(long double, long double, int *quo);

// float fmaf(float x, float y, float z);
// double fma(double x, double y, double z);
// long double fmal(long double x, long double y, long double z);

// float fmaxf(float x, float y);
// double fmax(double x, double y);
// long double fmaxl(long double x, long double y);

// float fminf(float x, float y);
// double fmin(double x, double y);
// long double fminl(long double x, long double y);

// float dimf(float x, float y);
// double dim(double x, double y);
// long double diml(long double x, long double y);

// float nanf(const char *arg);
// double nan(const char *arg);
// long double nanl(const char *arg);

// float expf(float arg);
// double exp(double arg);
// long double expl(long double arg);

// float exp2f(float arg);
// double exp2(double arg);
// long double exp2l(long double arg);

// float expm1f(float arg);
// double expm1(double arg);
// long double expm1l(long double arg);

float logf(float arg);
double log(double arg);
long double logl(long double arg);

float log10f(float arg);
double log10(double arg);
long double log10l(long double arg);

float log2f(float arg);
double log2(double arg);
long double log2l(long double arg);

float log1pf(float arg);
double log1p(double arg);
long double log1pl(long double arg);

// float powf(float x, float y);
// double pow(double x, double y);
// long double powl(long double x, long double y);

float sqrtf(float arg);
double sqrt(double arg);
long double sqrtl(long double arg);

// float cbrtf(float arg);
// double cbrt(double arg);
// long double cbrtl(long double arg);

// float hypotf(float x, float y);
// double hypot(double x, double y);
// long double hypotl(long double x, long double y);

float sinf(float arg);
double sin(double arg);
long double sinl(long double arg);

float cosf(float arg);
double cos(double arg);
long double cosl(long double arg);

float tanf(float arg);
double tan(double arg);
long double tanl(long double arg);

float asinf(float arg);
double asin(double arg);
long double asinl(long double arg);

float acosf(float arg);
double acos(double arg);
long double acosl(long double arg);

float atanf(float arg);
double atan(double arg);
long double atanl(long double arg);

float atan2f(float x, float y);
double atan2(double x, double y);
long double atan2l(long double x, long double y);

// float sinhf(float arg);
// double sinh(double arg);
// long double sinhl(long double arg);

// float coshf(float arg);
// double cosh(double arg);
// long double coshl(long double arg);

// float tanhf(float arg);
// double tanh(double arg);
// long double tanhl(long double arg);

// float asinhf(float arg);
// double asinh(double arg);
// long double asinhl(long double arg);

// float acoshf(float arg);
// double acosh(double arg);
// long double acoshl(long double arg);

// float atanhf(float arg);
// double atanh(double arg);
// long double atanhl(long double arg);

// float erff(float arg);
// double erf(float arg);
// long double erfl(long double arg);

// float erfcf(float arg);
// double erfc(double arg);
// long double erfcl(long double arg);

// float tgammaf(float arg);
// double tgamma(double arg);
// long double tgammal(long double arg);

// float lgammaf(float arg);
// double lgamma(double arg);
// long double lgammal(long double arg);

// float ceilf(float arg);
// double ceil(double arg);
// long double ceill(long double arg);

// float floorf(float arg);
// double floor(double arg);
// long double floorl(long double arg);

// float truncf(float arg);
// double trund(double arg);
// long double trunl(long double arg);

// float roundf(float arg);
// double round(double arg);
// long double roundl(long double arg);

// long lroundf(float arg);
// long lround(double arg);
// long lroundl(long double arg);
// long long llroundf(float arg);
// long long llround(double arg);
// long long llroundl(long double arg);

// float nearbyintf(float arg);
// double nearbyint(double arg);
// long double nearbyintl(long double arg);

// float rintf(float arg);
// double rint(double arg);
// long double rintl(long double arg);

// long lrintf(float arg);
// long lrint(double arg);
// long lrintl(long double arg);
// long long llrintf(float arg);
// long long llrint(double arg);
// long long llrintl(long double arg);

// float frexpf(float arg, int *exp);
// double frexp(double arg, int *exp);
// long double frexpl(long double arg, int *exp);

// float ldexpf(float arg, int exp);
// double ldexp(double arg, int exp);
// long double ldexpl(long double arg, int exp);

// float modff(float arg, float *iptr);
// double modf(double arg, double *iptr);
// long double modfl(long double arg, double *iptr);

// float scalbnf(float arg, int exp);
// double scalbn(double arg, int exp);
// long double scalbnl(long double arg, int exp);
// float scalblnf(float arg, long exp);
// double scalbln(double arg, long exp);
// long double scalblnl(long double arg, long exp);

// int ilogbf(float arg);
// int ilogb(double arg);
// int ilogbl(long double arg);
// float logbf(float arg);
// double logb(double arg);
// long double logbl(long double arg);

// float nextafterf(float from, float to);
// double nextafter(double from, double to);
// long double nextafterl(long double from, long double to);
// float nexttowardf(float from, float to);
// double nexttoward(double from, double to);
// long double nexttowardl(long double from, long double to);

// float copysignf(float x, float y);
// double copysign(double x, double y);
// long double copysignl(long double x, long double y);

// #define fpclassify(arg) not defined
// #define isfinite(arg) not defined
// #define isinf(arg) not defined
// #define isnan(arg) not defined
// #define isnormal(arg) not defined
// #define signbit(arg) not defined
// #define isgreater(x, y) not defined
// #define isgreaterequal(x, y) not defined
// #define isless(x, y) not defined
// #define islessequal(x, y) not defined
// #define islessgreater(x, y) not defined
// #define isunordered(x, y) not defined

#endif //MATH_H

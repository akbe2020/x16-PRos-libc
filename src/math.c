#include <math.h>

// helper functions:

float _fyl2xf(float x, float y) {
    float result;
    __asm__ __volatile__ (
        "flds %1\n"
        "flds %2\n"
        "fyl2x\n"
        "fstps %0\n"
        : "=m" (result)
        : "m" (y), "m" (x)
        : "st"
    );
    return result;
}

double _fyl2x(double x, double y) {
    double result;
    __asm__ __volatile__ (
        "fldl %1\n"
        "fldl %2\n"
        "fyl2x\n"
        "fstpl %0\n"
        : "=m" (result)
        : "m" (y), "m" (x)
        : "st"
    );
    return result;
}

long double _fyl2xl(long double x, long double y) {
    long double result;
    __asm__ __volatile__ (
        "fldt %1\n"
        "fldt %2\n"
        "fyl2x\n"
        "fstpt %0\n"
        : "=m" (result)
        : "m" (y), "m" (x)
        : "st"
    );
    return result;
}

float _fyl2xp1f(float x, float y) {
    float result;
    __asm__ __volatile__ (
        "flds %1\n"
        "flds %2\n"
        "fyl2xp1\n"
        "fstps %0\n"
        : "=m" (result)
        : "m" (y), "m" (x)
        : "st"
    );
    return result;
}

double _fyl2xp1(double x, double y) {
    double result;
    __asm__ __volatile__ (
        "fldl %1\n"
        "fldl %2\n"
        "fyl2xp1\n"
        "fstpl %0\n"
        : "=m" (result)
        : "m" (y), "m" (x)
        : "st"
    );
    return result;
}

long double _fyl2xp1l(long double x, long double y) {
    long double result;
    __asm__ __volatile__ (
        "fldt %1\n"
        "fldt %2\n"
        "fyl2xp1\n"
        "fstpt %0\n"
        : "=m" (result)
        : "m" (y), "m" (x)
        : "st"
    );
    return result;
}

// end of helper functions

float fabsf(float arg) {
    float result;
    __asm__ __volatile__ (
        "flds %1\n"
        "fabs\n"
        "fstps %0\n"
        : "=m" (result)
        : "m" (arg)
    );
    return result;
}

double fabs(double arg) {
    double result;
    __asm__ __volatile__ (
        "fldl %1\n"
        "fabs\n"
        "fstpl %0\n"
        : "=m" (result)
        : "m" (arg)
    );
    return result;
}

long double fabsl(long double arg) {
    long double result;
    __asm__ __volatile__ (
        "fldt %1\n"
        "fabs\n"
        "fstpt %0\n"
        : "=m" (result)
        : "m" (arg)
    );
    return result;
}

float logf(const float arg) {
    return _fyl2xf(arg, 1.0f / log2f(M_E));
}

double log(const double arg) {
    return _fyl2x(arg, 1.0 / log2(M_E));
}
long double logl(const long double arg) {
    return _fyl2xl(arg, 1.0L / log2l(M_E));
}

float log10f(const float arg) {
    return _fyl2xf(arg, 1.0f / log2f(10.0f));
}

double log10(const double arg) {
    return _fyl2x(arg, 1.0 / log2(10.0));
}

long double log10l(const long double arg) {
    return _fyl2xl(arg, 1.0L / log2l(10.0L));
}

float log2f(const float arg) {
    return _fyl2xf(arg, 1.0f);
}

double log2(const double arg) {
    return _fyl2x(arg, 1.0);
}

long double log2l(const long double arg) {
    return _fyl2xl(arg, 1.0L);
}

float log1pf(const float arg) {
    return _fyl2xp1f(arg, 1.0f);
}

double log1p(const double arg) {
    return _fyl2xp1(arg, 1.0);
}

long double log1pl(const long double arg) {
    return _fyl2xp1l(arg, 1.0L);
}

float sqrtf(float arg) {
    float result;
    __asm__ __volatile__ (
        "flds %1\n"
        "fsqrt\n"
        "fstps %0\n"
        : "=m" (result)
        : "m" (arg)
    );
    return result;
}

double sqrt(double arg) {
    double result;
    __asm__ __volatile__ (
        "fldl %1\n"
        "fsqrt\n"
        "fstpl %0\n"
        : "=m" (result)
        : "m" (arg)
    );
    return result;
}

long double sqrtl(long double arg) {
    long double result;
    __asm__ __volatile__ (
        "fldt %1\n"
        "fsqrt\n"
        "fstpt %0\n"
        : "=m" (result)
        : "m" (arg)
    );
    return result;
}

float sinf(float arg) {
    float result;
    __asm__ __volatile__ (
        "flds %1\n"
        "fsin\n"
        "fstps %0\n"
        : "=m" (result)
        : "m" (arg)
    );
    return result;
}

double sin(double arg) {
    double result;
    __asm__ __volatile__ (
        "fldl %1\n"
        "fsin\n"
        "fstpl %0\n"
        : "=m" (result)
        : "m" (arg)
    );
    return result;
}

long double sinl(long double arg) {
    long double result;
    __asm__ __volatile__ (
        "fldt %1\n"
        "fsin\n"
        "fstpt %0\n"
        : "=m" (result)
        : "m" (arg)
    );
    return result;
}

float cosf(float arg) {
    float result;
    __asm__ __volatile__ (
        "flds %1\n"
        "fcos\n"
        "fstps %0\n"
        : "=m" (result)
        : "m" (arg)
    );
    return result;
}

double cos(double arg) {
    double result;
    __asm__ __volatile__ (
        "fldl %1\n"
        "fcos\n"
        "fstpl %0\n"
        : "=m" (result)
        : "m" (arg)
    );
    return result;
}

long double cosl(long double arg) {
    long double result;
    __asm__ __volatile__ (
        "fldt %1\n"
        "fcos\n"
        "fstpt %0\n"
        : "=m" (result)
        : "m" (arg)
    );
    return result;
}

float tanf(float arg) {
    float result;
    __asm__ __volatile__ (
        "flds %1\n"
        "fptan\n"
        "fxch %%st(1)\n"
        "fstps %0\n"
        "fstp %%st(0)\n"
        : "=m" (result)
        : "m" (arg)
        : "st"
    );
    return result;
}

double tan(double arg) {
    double result;
    __asm__ __volatile__ (
        "fldl %1\n"
        "fptan\n"
        "fxch %%st(1)\n"
        "fstpl %0\n"
        "fstp %%st(0)\n"
        : "=m" (result)
        : "m" (arg)
        : "st"
    );
    return result;
}

long double tanl(long double arg) {
    long double result;
    __asm__ __volatile__ (
        "fldt %1\n"
        "fptan\n"
        "fxch %%st(1)\n"
        "fstpt %0\n"
        "fstp %%st(0)\n"
        : "=m" (result)
        : "m" (arg)
        : "st"
    );
    return result;
}

float asinf(const float arg) {
    return atanf(arg / sqrtf(1.0f - arg * arg));
}

double asin(const double arg) {
    return atan(arg / sqrt(1.0 - arg * arg));
}

long double asinl(const long double arg) {
    return atanl(arg / sqrtl(1.0L - arg * arg));
}

float acosf(const float arg) {
    return atanf(sqrtf(1.0f - arg * arg) / arg);
}

double acos(const double arg) {
    return atan(sqrt(1.0 - arg * arg) / arg);
}

long double acosl(const long double arg) {
    return atanl(sqrtl(1.0L - arg * arg) / arg);
}

float atanf(const float arg) {
    return atan2f(1.0f / arg, 1.0f);
}

double atan(const double arg) {
    return atan2(1.0f / arg, 1.0f);
}

long double atanl(const long double arg) {
    return atan2l(1.0L / arg, 1.0L);
}

float atan2f(float x, float y) {
    float result;
    __asm__ __volatile__ (
        "flds %1\n"
        "flds %2\n"
        "fpatan\n"
        "fstps %0\n"
        : "=m" (result)
        : "m" (y), "m" (x)
        : "st"
    );
    return result;
}

double atan2(double x, double y) {
    double result;
    __asm__ __volatile__ (
        "fldl %1\n"
        "fldl %2\n"
        "fpatan\n"
        "fstpl %0\n"
        : "=m" (result)
        : "m" (y), "m" (x)
        : "st"
    );
    return result;
}

long double atan2l(long double x, long double y) {
    long double result;
    __asm__ __volatile__ (
        "fldt %1\n"
        "fldt %2\n"
        "fpatan\n"
        "fstpt %0\n"
        : "=m" (result)
        : "m" (y), "m" (x)
        : "st"
    );
    return result;
}

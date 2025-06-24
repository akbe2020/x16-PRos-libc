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

// Rounding modes:
// 0x0000 - to nearest, tie to even
// 0x0400 - down
// 0x0800 - up
// 0x0c00 - truncate (toward 0)
// other values will lead to undefined behavior

float _round_using_modef(float arg, unsigned short mode) {
    float result;
    unsigned short original_cw, modified_cw;

    __asm__ __volatile__ (
        "fstcw %0\n"
        : "=m" (original_cw)
    );

    modified_cw = original_cw;
    modified_cw &= ~0x0c00;
    modified_cw |= mode;

    __asm__ __volatile__ (
        "fldcw %0\n"
        :
        : "m" (modified_cw)
    );

    __asm__ __volatile__ (
        "flds %1\n"
        "frndint\n"
        "fstps %0\n"
        : "=m" (result)
        : "m" (arg)
    );

    __asm__ __volatile__ (
        "fldcw %0"
        :
        : "m" (original_cw)
    );

    return result;
}

double _round_using_mode(double arg, unsigned short mode) {
    double result;
    unsigned short original_cw, modified_cw;

    __asm__ __volatile__ (
        "fstcw %0\n"
        : "=m" (original_cw)
    );

    modified_cw = original_cw;
    modified_cw &= ~0x0c00;
    modified_cw |= mode;

    __asm__ __volatile__ (
        "fldcw %0\n"
        :
        : "m" (modified_cw)
    );

    __asm__ __volatile__ (
        "fldl %1\n"
        "frndint\n"
        "fstpl %0\n"
        : "=m" (result)
        : "m" (arg)
    );

    __asm__ __volatile__ (
        "fldcw %0"
        :
        : "m" (original_cw)
    );

    return result;
}

long double _round_using_model(long double arg, unsigned short mode) {
    long double result;
    unsigned short original_cw, modified_cw;

    __asm__ __volatile__ (
        "fstcw %0\n"
        : "=m" (original_cw)
    );

    modified_cw = original_cw;
    modified_cw &= ~0x0c00;
    modified_cw |= mode;

    __asm__ __volatile__ (
        "fldcw %0\n"
        :
        : "m" (modified_cw)
    );

    __asm__ __volatile__ (
        "fldt %1\n"
        "frndint\n"
        "fstpt %0\n"
        : "=m" (result)
        : "m" (arg)
    );

    __asm__ __volatile__ (
        "fldcw %0"
        :
        : "m" (original_cw)
    );

    return result;
}

float _f2xm1f(float arg) {
    float result;
    __asm__ __volatile__ (
        "flds %1\n"
        "f2xm1\n"
        "fstps %0\n"
        : "=m" (result)
        : "m" (arg)
    );
    return result;
}

double _f2xm1(double arg) {
    double result;
    __asm__ __volatile__ (
        "fldl %1\n"
        "f2xm1\n"
        "fstpl %0\n"
        : "=m" (result)
        : "m" (arg)
    );
    return result;
}

long double _f2xm1l(long double arg) {
    long double result;
    __asm__ __volatile__ (
        "fldt %1\n"
        "f2xm1\n"
        "fstpt %0\n"
        : "=m" (result)
        : "m" (arg)
    );
    return result;
}

float _fscalef(float x, float y) {
    float result;
    __asm__ __volatile__ (
        "flds %1\n"
        "flds %2\n"
        "fscale\n"
        "fstps %0\n"
        "fstp %%st(0)\n"
        : "=m" (result)
        : "m" (x), "m" (y)
    );
    return result;
}

double _fscale(double x, double y) {
    double result;
    __asm__ __volatile__ (
        "fldl %1\n"
        "fldl %2\n"
        "fscale\n"
        "fstpl %0\n"
        "fstp %%st(0)\n"
        : "=m" (result)
        : "m" (x), "m" (y)
    );
    return result;
}

long double _fscalel(long double x, long double y) {
    long double result;
    __asm__ __volatile__ (
        "fldt %1\n"
        "fldt %2\n"
        "fscale\n"
        "fstpt %0\n"
        "fstp %%st(0)\n"
        : "=m" (result)
        : "m" (x), "m" (y)
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

float fmodf(const float x, const float y) {
    return x - roundf(x / y) * y;
}

double fmod(const double x, const double y) {
    return x - round(x / y) * y;
}

long double fmodl(long const double x, const long double y) {
    return x - roundl(x / y) * y;
}

float remainderf(const float x, const float y) {
    return x - truncf(x / y) * y;
}

double remainder(const double x, const double y) {
    return x - trunc(x / y) * y;
}

long double remainderl(const long double x, const long double y) {
    return x - truncl(x / y) * y;
}

float expf(const float arg) {
    return exp2f(arg / (float) M_LN2);
}

double exp(const double arg) {
    return exp2(arg / M_LN2);
}

long double expl(const long double arg) {
    return exp2l(arg / (long double) M_LN2);
}

float exp2f(const float arg) {
    const float n = floorf(arg);
    return _fscalef(n, 1.0f) * (_f2xm1f(arg - n) + 1.0f);
}

double exp2(const double arg) {
    const double n = floor(arg);
    return _fscale(n, 1.0) * (_f2xm1(arg - n) + 1.0);
}

long double exp2l(const long double arg) {
    const long double n = floorl(arg);
    return _fscalel(n, 1.0L) * (_f2xm1l(arg - n) + 1.0L);
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

float powf(const float x, const float y) {
    if (x == 0.0f) {
        return 1.0f;
    }

    float sign = 1.0f;

    if (x < 0.0f) {
        if (y != floorf(y)) {
            return NAN;
        }

        if (fmodf(y, 2.0f) != 0.0f) {
            sign = -1.0f;
        }
    }

    return sign * exp2f(y * log2f(fabsf(x)));
}

double pow(const double x, const double y) {
    if (x == 0.0) {
        return 1.0;
    }

    double sign = 1.0;

    if (x < 0.0) {
        if (y != floor(y)) {
            return NAN;
        }

        if (fmod(y, 2.0) != 0.0) {
            sign = -1.0;
        }
    }

    return sign * exp2(y * log2(fabs(x)));
}

long double powl(const long double x, const long double y) {
    if (x == 0.0L) {
        return 1.0L;
    }

    long double sign = 1.0L;

    if (x < 0.0L) {
        if (y != floorl(y)) {
            return NAN;
        }

        if (fmodl(y, 2.0L) != 0.0L) {
            sign = -1.0;
        }
    }

    return sign * exp2l(y * log2l(fabsl(x)));
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

float cbrtf(const float arg) {
    return powf(arg, 1.0f / 3.0f);
}

double cbrt(const double arg) {
    return pow(arg, 1.0 / 3.0);
}

long double cbrtl(const long double arg) {
    return powl(arg, 1.0L / 3.0L);
}

float hypotf(const float x, const float y) {
    return sqrtf(x * x + y * y);
}

double hypot(const double x, const double y) {
    return sqrt(x * x + y * y);
}

long double hypotl(const long double x, const long double y) {
    return sqrtl(x * x + y * y);
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

float ceilf(const float arg) {
    return _round_using_modef(arg, 0x0800);
};

double ceil(const double arg) {
    return _round_using_mode(arg, 0x0800);
};

long double ceill(const long double arg) {
    return _round_using_model(arg, 0x0800);
};

float floorf(const float arg) {
    return _round_using_modef(arg, 0x0400);
}

double floor(const double arg) {
    return _round_using_mode(arg, 0x0400);
}

long double floorl(const long double arg) {
    return _round_using_model(arg, 0x0400);
}

float truncf(const float arg) {
    return _round_using_modef(arg, 0x0c00);
}

double trunc(const double arg) {
    return _round_using_mode(arg, 0x0c00);
}

long double truncl(const long double arg) {
    return _round_using_model(arg, 0x0c00);
}

float roundf(const float arg) {
    return _round_using_modef(arg, 0x0000);
}

double round(const double arg) {
    return _round_using_mode(arg, 0x0000);
}

long double roundl(const long double arg) {
    return (long) _round_using_model(arg, 0x0000);
}

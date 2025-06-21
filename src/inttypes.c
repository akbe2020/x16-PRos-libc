#include <inttypes.h>

intmax_t imaxabs(const intmax_t x) {
    return x < 0 ? -x : x;
}

imaxdiv_t imaxdiv(const intmax_t num, const intmax_t den) {
    return (imaxdiv_t) {
        num / den, num % den
    };
}

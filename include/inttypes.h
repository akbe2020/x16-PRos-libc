#ifndef INTTYPES_H
#define INTTYPES_H

#include <stdint.h>

// missing constants for the fprintf family of functions
// missing constants for the fscanf family of functions

typedef struct {
    intmax_t quot;
    intmax_t rem;
} imaxdiv_t;

intmax_t imaxabs(intmax_t);
imaxdiv_t imaxdiv(intmax_t, intmax_t);

// intmax_t strtoimax(const char *restrict nptr, const char **restrict endptr, int base);
// uintmax_t strtoumax(const char *restrict nptr, const char **restrict endptr, int base);

// intmax_t strtoimax(const wchar_t *restrict nptr, const wchar_t **restrict endptr, int base);
// uintmax_t strtoumax(const wchar_t *restrict nptr, const wchar_t **restrict endptr, int base);

#endif //INTTYPES_H

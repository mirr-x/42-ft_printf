#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>

int main(void) {
    int result;

    // result = ft_printf(" %d ", -1);
    // printf("Test 2: expected 4, got %d\n", result);

    // result = ft_printf(" %d ", -9);
    // printf("Test 13: expected 5, got %d\n", result);

    // result = ft_printf(" %d ", -10);
    // printf("Test 14: expected 6, got %d\n", result);

    // result = ft_printf(" %d ", -11);
    // printf("Test 15: expected 6, got %d\n", result);

    // result = ft_printf(" %d ", -14);
    // printf("Test 16: expected 6, got %d\n", result);

    // result = ft_printf(" %d ", -15);
    // printf("Test 17: expected 6, got %d\n", result);

    // result = ft_printf(" %d ", -16);
    // printf("Test 18: expected 6, got %d\n", result);

    // result = ft_printf(" %d ", -99);
    // printf("Test 19: expected 6, got %d\n", result);

    // result = ft_printf(" %d ", -100);
    // printf("Test 20: expected 7, got %d\n", result);

    // result = ft_printf(" %d ", -101);
    // printf("Test 21: expected 7, got %d\n", result);

    // result = ft_printf(" %d ", INT_MIN);
    // printf("Test 23: expected 13, got %d\n", result);

    // result = ft_printf(" %d ", LONG_MAX);
    // printf("Test 24: expected 21, got %d\n", result);

    // result = ft_printf(" %d ", UINT_MAX);
    // printf("Test 26: expected 11, got %d\n", result);

    // result = ft_printf(" %d ", ULONG_MAX);
    // printf("Test 27: expected 21, got %d\n", result);

    // result = ft_printf(" %d ", 9223372036854775807LL);
    // printf("Test 28: expected 21, got %d\n", result);

    // result = ft_printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    // printf("Test 29: expected 87, got %d\n", result);

    ft_printf("he %u", 123);

    return 0;
}
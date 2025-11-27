#include "ft_printf.h"
#include <stdio.h>
// #include <limits>

int main()
{
    int i = ft_printf(" % d \n", 0);
    int j = printf(" % d \n", 0);

    // int i = printf("%+d ", LONG_MIN);

    printf("%d\n", i);
    printf("%d\n", j);
}
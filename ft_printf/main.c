#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(void)
{
    int result;

    result = ft_printf("%x", 90);
    printf("%d\n", result);

    result = printf("%x", 90);
    printf("%d\n", result);

    return 0;
}
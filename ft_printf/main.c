#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(void)
{
    int result;

    result = ft_printf("\001\002\007\v\010\f\r\n");
    printf("\n%d\n", result);

    result = ft_printf("\001\002\007\v\010\f\r\n");
    printf("\n%d\n", result);

    return 0;
}
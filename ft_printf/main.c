#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(void)
{
    int result;

    result = ft_printf("hel%yeah");
    printf("\n%d\n", result);

    result = printf("hel%yeah");
    printf("\n%d\n", result);

    return 0;
}
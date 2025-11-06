/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:08:53 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/06 09:59:50 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

int ft_printf(const char *s, ...)
{
	va_list args;
	int i;
	char c;
	int cn = 0;

	if (!s)
		return (-1);
	va_start(args, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '\0' && s[i + 1] == 'c')
		{
			i += 2;
			cn += 1;
			c = va_arg(args, int);
			write(1, &c, 1);
		}
		else if (s[i] == '%' && s[i + 1] != '\0' && s[i + 1] == 's')
		{
			i += 2;
			char *s2 = va_arg(args, char *);
			cn += strlen(s2); // ft_strlen
			ft_putstr_fd(s2, 1);
		}
		else if (s[i] == '%' && s[i + 1] != '\0' && s[i + 1] == 'p')
		{
			i += 2;
			char *s2 = va_arg(args, char *);
			cn += strlen(s2); // ft_strlen
			ft_putstr_fd(s2, 1);
		}
		else
		{
			write(1, &s[i], 1);
			i++;
			cn++;
		}
	}
	return (cn);
}

int main()
{
	int x = ft_printf("hello %c and -> %s\n", 'B', "ZZZ");

	int *o = &x;

	printf("\n_%d_\n", x);
}
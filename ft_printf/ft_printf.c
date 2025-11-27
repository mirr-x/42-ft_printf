/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:08:53 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/27 15:01:01 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	get_correct_format_parameter(va_list args, char c, size_t *cn, int fd)
{
	if (c == 'c')
		*cn += ft_putchar_fd(va_arg(args, int), fd);
	else if (c == 's')
		*cn += ft_putstr_fd(va_arg(args, char *), fd);
	else if (c == 'p')
		*cn += ft_puthex_ptr_fd((size_t)va_arg(args, void *), fd);
	else if (c == 'd' || c == 'i')
		*cn += ft_putnbr_fd(va_arg(args, int), fd);
	else if (c == 'u')
		*cn += ft_putunsignd_fd(va_arg(args, unsigned int), fd);
	else if (c == 'x')
		*cn += ft_puthex_dec_fd(va_arg(args, unsigned int), fd, 0);
	else if (c == 'X')
		*cn += ft_puthex_dec_fd(va_arg(args, unsigned int), fd, 1);
	else if (c == '%')
		*cn += ft_putchar_fd('%', fd);
	else
		*cn += ft_putchar_fd(c, fd);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	i;
	size_t	cn;

	va_start(args, s);
	cn = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '\0')
				return (cn);
			get_correct_format_parameter(args, s[i++], &cn, 1);
		}
		else
		{
			ft_putchar_fd(s[i++], 1);
			cn++;
		}
	}
	return ((va_end(args)), cn);
}

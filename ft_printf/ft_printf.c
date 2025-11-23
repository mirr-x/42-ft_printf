/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:08:53 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/23 18:54:18 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	get_correct_format_parameter(va_list args, char c, size_t *cn)
{
	if (c == 'c')
		*cn += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		*cn += ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		*cn += ft_puthex((size_t)va_arg(args, void *), 1);
	else if (c == 'd' || c == 'i')
		*cn += ft_putnbr_fd(va_arg(args, int), 1);
	else
		*cn += ft_putchar_fd(c, 1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	i;
	size_t	cn;

	if (!s)
		return (-1);
	va_start(args, s);
	cn = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			get_correct_format_parameter(args, s[i++], &cn);
			continue ;
		}
		ft_putchar_fd(s[i++], 1);
		cn++;
	}
	va_end(args);
	return (cn);
}

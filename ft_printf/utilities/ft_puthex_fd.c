/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:35:59 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/22 07:35:26 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	rec_hx(size_t num, int fd, size_t *counter)
{
	char	*hex_range;
	int		n;

	hex_range = "0123456789abcdef";
	if (num / 16 == 0)
	{
		n = num % 16;
		(*counter)++;
		ft_putchar_fd(hex_range[n], fd);
		return ;
	}
	rec_hx(num / 16, fd, counter);
	n = num % 16;
	(*counter)++;
	ft_putchar_fd(hex_range[n], fd);
}

size_t	ft_puthex(size_t num, int fd)
{
	size_t	counter;

	counter = 2;
	ft_putstr_fd("0x", fd);
	rec_hx(num, fd, &counter);
	return (counter);
}

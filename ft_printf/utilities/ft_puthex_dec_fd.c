/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_dec_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:15:09 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/24 15:28:39 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	rec_hx_dec(size_t num, int fd, size_t *counter, char *hex_range)
{
	int		n;

	if (num / 16 == 0)
	{
		n = num % 16;
		(*counter)++;
		ft_putchar_fd(hex_range[n], fd);
		return ;
	}
	rec_hx_dec(num / 16, fd, counter, hex_range);
	n = num % 16;
	(*counter)++;
	ft_putchar_fd(hex_range[n], fd);
}

size_t	ft_puthex_dec_fd(unsigned int num, int fd, int sig)
{
	char	*hex_range;
	size_t	counter;

	hex_range = "0123456789abcdef";
	if (sig == 1)
		hex_range = "0123456789ABCDEF";
	counter = 0;
	rec_hx_dec(num, fd, &counter, hex_range);
	return (counter);
}

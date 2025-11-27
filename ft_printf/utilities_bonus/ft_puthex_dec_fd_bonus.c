/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_dec_fd_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:15:09 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/27 21:06:44 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

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

size_t	ft_puthex_dec_fd(unsigned int num, int fd, int sig, t_flags_bonus *flag)
{
	char	*hex_range;
	size_t	counter;

	counter = 0;
	hex_range = "0123456789abcdef";
	if (flag->hashtag == 1 && num != 0)
	{
		if (sig)
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
		counter += 2;
	}
	if (num == 0)
		return (write(fd, "0", 1));
	if (sig == 1)
		hex_range = "0123456789ABCDEF";
	rec_hx_dec(num, fd, &counter, hex_range);
	return (counter);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:29:35 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/22 07:30:54 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	rec(long n, int fd)
{
	char	c;

	if (n == 0)
		return ;
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	rec(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

int	ft_intlen(int n)
{
	int	len;

	len = 0;
	while (n != 0)
		n = n / 10, (len++);
	return (len);
}

/* Outputs the integer 'n' to the given file descriptor 'fd'. */
int	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	rec((long)n, fd);
	return (ft_intlen(n));
}

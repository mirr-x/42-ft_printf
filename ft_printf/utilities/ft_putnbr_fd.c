/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:29:35 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/24 10:57:21 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	rec(long n, int fd)
{
	char	c;

	if (n == 0)
		return ;
	rec(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

int	ft_intlen(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		(n *= -1);
	}
	while (n != 0)
		n = n / 10, (len++);
	return (len);
}

/* Outputs the integer 'n' to the given file descriptor 'fd'. */
int	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		len;

	num = n;
	len = ft_intlen(num);
	if (n == 0)
		return ((write(fd, "0", 1)), 1);
	else if (n < 0)
	{
		num *= -1;
		write(fd, "-", 1);
	}
	rec(num, fd);
	return (ft_intlen(n));
}

int	ft_putunsignd_fd(int n, int fd)
{
	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:29:35 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/02 12:52:52 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/* Outputs the integer 'n' to the given file descriptor 'fd'. */
void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	rec((long)n, fd);
}

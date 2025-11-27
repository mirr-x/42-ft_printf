/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:29:35 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/27 20:47:04 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

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
    {
        n = n / 10;
        len++;
    }
    return (len);
}

/* Outputs the integer 'n' to the given file descriptor 'fd'. */
size_t	ft_putnbr_fd(int n, int fd, t_flags_bonus *flag)
{
    long	num;
    size_t	len;

    num = n;
    len = ft_intlen(num);
        if (flag->plus && n >= 0)
    {
        write(fd, "+", 1);
        len++;
    }
    else if (flag->space && n >= 0)
    {
        write(fd, " ", 1);
        len++;
    }
    if (n == 0)
        return ((write(fd, "0", 1)), 1);
    else if (n < 0)
    {
        num *= -1;
        write(fd, "-", 1);
    }
    rec(num, fd);
    return (len);
}

size_t	ft_putunsignd_fd(unsigned int n, int fd)
{
    char	c;
    size_t	len;

    if (n == 0)
        return (write(fd, "0", 1));
    len = 0;
    if (n / 10 == 0)
        return ((c = (n % 10) + '0'), write(fd, &c, 1));
    len += ft_putunsignd_fd(n / 10, fd);
    c = (n % 10) + '0';
    write(fd, &c, 1);
    return (len + 1);
}

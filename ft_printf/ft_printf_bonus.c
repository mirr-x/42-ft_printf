/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:08:53 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/27 21:04:09 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void init(t_flags_bonus *flags)
{
	flags->hashtag = 0;
	flags->space = 0;
	flags->plus = 0;
}

int check_flags_bonus(const char *s, t_flags_bonus *flags)
{
    int consumed = 0;
    while (s[consumed] == '#' || s[consumed] == ' ' || s[consumed] == '+')
    {
        if (s[consumed] == '#')
            flags->hashtag = 1;
        else if (s[consumed] == ' ')
            flags->space = 1;
        else if (s[consumed] == '+')
            flags->plus = 1;
        consumed++;
    }
    return consumed;
}

int	get_correct_format_parameter(va_list args, const char *s, size_t *cn, int fd, t_flags_bonus *flag)
{
	int		consumed;

	consumed = check_flags_bonus(s, flag);
	if (s[consumed] == 'c')
		*cn += ft_putchar_fd(va_arg(args, int), fd);
	else if (s[consumed] == 's')
		*cn += ft_putstr_fd(va_arg(args, char *), fd);
	else if (s[consumed] == 'p')
		*cn += ft_puthex_ptr_fd((size_t)va_arg(args, void *), fd);
	else if (s[consumed] == 'd' || s[consumed] == 'i')
		*cn += ft_putnbr_fd(va_arg(args, int), fd, flag);
	else if (s[consumed] == 'u')
		*cn += ft_putunsignd_fd(va_arg(args, unsigned int), fd);
	else if (s[consumed] == 'x')
		*cn += ft_puthex_dec_fd(va_arg(args, unsigned int), fd, 0, flag);
	else if (s[consumed] == 'X')
		*cn += ft_puthex_dec_fd(va_arg(args, unsigned int), fd, 1, flag);
	else if (s[consumed] == '%')
		*cn += ft_putchar_fd('%', fd);
	else
		*cn += ft_putchar_fd(s[consumed], fd);
	return (consumed + 1);
}

// if (stdout->_file == -1)
// 	return (-1);
int	ft_printf(const char *s, ...)
{
	va_list			args;
	size_t			i;
	size_t			cn;
	t_flags_bonus	flags;

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
			init(&flags);
            i += get_correct_format_parameter(args, &s[i], &cn, 1, &flags);
		}
		else
		{
			ft_putchar_fd(s[i++], 1);
			cn++;
		}
	}
	return ((va_end(args)), cn);
}

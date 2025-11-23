/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:19:54 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/12 11:15:45 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*null_error(void)
{
	return (NULL);
}

/* Outputs the string 's' to the given file descriptor 'fd'. */
size_t	ft_putstr_fd(char *s, int fd)
{
	int		i;

	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &(s)[i], 1);
		i++;
	}
	return (ft_strlen(s));
}

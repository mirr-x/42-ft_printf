/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:33:10 by molahrac          #+#    #+#             */
/*   Updated: 2025/10/31 10:33:43 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies 'src' into n 'dst',
 * adds '\0', and returns 'src' length
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		srclen;
	size_t		i;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	i = 0;
	while (i != (dstsize - 1) && *(src + i) != '\0')
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (srclen);
}
// | | | | | |  | <- dst  dst_size = 6
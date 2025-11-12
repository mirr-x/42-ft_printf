/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:28:04 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/01 18:34:23 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	copy_src_to_dst(char const *src, char *dst, size_t *i)
{
	size_t	j;

	j = 0;
	while (src[j] != '\0')
	{
		dst[*i] = src[j];
		(*i)++;
		j++;
	}
}

/**
 * Joins 's1' and 's2' into a new string. 
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = (char *)malloc(s1_len + s2_len + 1);
	if (!dst)
		return (NULL);
	i = 0;
	copy_src_to_dst(s1, dst, &i);
	copy_src_to_dst(s2, dst, &i);
	dst[i] = '\0';
	return (dst);
}

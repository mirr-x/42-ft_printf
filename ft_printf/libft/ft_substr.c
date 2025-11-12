/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:30:39 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/04 09:36:09 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * extract a substring from 's', starting at 'start' into the 'len' 
 * characters.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	remain;
	size_t	i;
	size_t	slen;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	remain = slen - (start);
	if (len > remain)
		len = remain;
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}

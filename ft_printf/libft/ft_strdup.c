/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:17:38 by molahrac          #+#    #+#             */
/*   Updated: 2025/10/29 12:05:10 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Duplicates the string 's1' by allocating memory and copying its content.
 *  Returns a pointer to the new string or NULL if allocation fails
 */
char	*ft_strdup(const char *s1)
{
	size_t	len_s1;
	char	*ptr;

	len_s1 = ft_strlen(s1);
	ptr = (char *)malloc((len_s1 * sizeof(char)) + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, len_s1 + 1);
	return (ptr);
}

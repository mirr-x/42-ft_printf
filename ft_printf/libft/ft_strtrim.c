/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:59:00 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/01 18:36:31 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	c_is_set(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

void	remove_from_strat(char *s1, char *set, size_t *start)
{
	while (s1[*start] != '\0' && c_is_set(s1[*start], (char *)set) == 1)
		(*start)++;
}

void	remove_from_end(char *s1, char *set, size_t *start, size_t *end)
{
	while (*end > *start && c_is_set(s1[*end - 1], (char *)set) == 1)
		(*end)--;
}

/**
 * Removes characters in 'set' from the start and end of 's1'.
 *  Returns the new string or NULL if it fails
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	total_valid;
	size_t	start;
	size_t	end;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	remove_from_strat((char *)s1, (char *)set, &start);
	end = ft_strlen(s1);
	remove_from_end((char *)s1, (char *)set, &start, &end);
	if (start == end)
		return (ft_strdup(""));
	total_valid = end - start;
	ptr = (char *)malloc(total_valid + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (start != end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}

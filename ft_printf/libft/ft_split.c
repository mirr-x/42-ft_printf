/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:14:18 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/01 18:33:36 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			counter++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (counter);
}

void	free_the_remain(char **arr2d, int num)
{
	int		i;

	i = 0;
	while (i != num)
		free(arr2d[i++]);
	free(arr2d);
}

char	**extact_wrds_to_2d_arr(char **arr2d, char const *s, char c, int n_wrds)
{
	int		i;
	int		j;
	int		start;
	int		end;

	i = 0;
	j = 0;
	while (n_wrds != i)
	{
		while (s[j] == c)
			j++;
		start = j;
		while (s[j] != c && s[j] != '\0')
			j++;
		end = j;
		arr2d[i] = ft_substr(s, start, end - start);
		if (arr2d[i] == NULL)
		{
			free_the_remain(arr2d, i);
			return (NULL);
		}
		i++;
	}
	return (arr2d);
}

/**
 * Splits the string 's' into an array of words, using the delimiter 'c
 */
char	**ft_split(char const *s, char c)
{
	int		num_of_words;
	char	**arr_of_words;

	if (!s)
		return (NULL);
	num_of_words = count_words(s, c);
	arr_of_words = (char **)malloc(((num_of_words + 1) * sizeof(char *)));
	if (!arr_of_words)
		return (NULL);
	arr_of_words[num_of_words] = NULL;
	if (!extact_wrds_to_2d_arr(arr_of_words, s, c, num_of_words))
		return (NULL);
	return (arr_of_words);
}

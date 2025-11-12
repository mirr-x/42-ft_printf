/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:43:49 by molahrac          #+#    #+#             */
/*   Updated: 2025/10/20 19:59:52 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Checks if 'c' is an alphanumeric character (a letter or a digit) */
int	ft_isalnum(int c)
{
	if (!(ft_isalpha(c) || ft_isdigit(c)))
		return (0);
	return (1);
}

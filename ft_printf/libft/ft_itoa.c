/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 10:28:28 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/02 12:52:04 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	recx(char *arr, long num, int len_num)
{
	int	x;

	x = -1;
	if (num < 0)
	{
		num *= -1;
		arr[0] = '-';
		x = 0;
	}
	while (len_num != x)
	{
		arr[len_num] = (num % 10) + '0';
		num /= 10;
		len_num--;
	}
}

char	*ft_itoa(int n)
{
	int		len_num;
	char	*arr;
	long	num;

	num = n;
	len_num = ft_intlen(num);
	arr = (char *)malloc((len_num + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	arr[len_num] = '\0';
	if (num == 0)
	{
		arr[0] = '0';
		return (arr);
	}
	recx(arr, num, len_num - 1);
	return (arr);
}

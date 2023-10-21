/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 08:40:15 by ulyildiz          #+#    #+#             */
/*   Updated: 2023/10/20 07:57:52 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_order(int n)
{
	int		i;
	float	j;

	j = (float)n;
	i = 0;
	if (n == 0)
		return (1);
	while (j > 1 || j < -1)
	{
		j /= 10;
		i++;
		if (j > -1 && j < 0)
			i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*array;
	char	*arr;
	int		j;

	j = ft_order(n);
	array = (char *)malloc(j + 1);
	arr = array + 1;
	if (array == NULL)
		return (NULL);
	array[j] = '\0';
	if (n == -2147483648)
		return (ft_memcpy(array, "-2147483648", 11));
	else if (n < 0)
	{
		array[0] = '-';
		array[1] = '\0';
		array = ft_strjoin(array, ft_itoa(-n));
	}
	else if (n >= 10)
		array = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n >= 0 && n < 10)
		array[0] = n + '0';
	return (array);
}

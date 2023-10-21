/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:21:04 by ulyildiz          #+#    #+#             */
/*   Updated: 2023/10/21 11:13:55 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	j = start;
	i = 0;
	substr = (char *)malloc(len + 1);
	if (substr == NULL || s == NULL)
		return (NULL);
	while (i < len && j < ft_strlen(s))
	{
		substr[i] = s[j];
		i++;
		j++;
	}
	substr[i] = '\0';
	return (substr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 23:35:20 by ulyildiz          #+#    #+#             */
/*   Updated: 2023/10/18 10:38:25 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isit(char const *set, int c)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	int		len;

	len = ft_strlen(s1);
	while (*s1 != '\0' && ft_isit(set, *s1))
	{
		s1++;
		len--;
	}
	while (len != 0 && ft_isit(set, s1[len - 1]))
		len--;
	arr = ft_substr(s1, 0, len);
	return (arr);
}

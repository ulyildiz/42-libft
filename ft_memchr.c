/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:47:09 by ulyildiz          #+#    #+#             */
/*   Updated: 2023/10/17 22:27:28 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	unsigned char *s1;

	s1 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(s1 + i) == (unsigned char)c)
			return ((void *)(s1 + i));
		i++;
	}
	return (NULL);
}

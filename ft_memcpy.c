/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 23:04:09 by ulyildiz          #+#    #+#             */
/*   Updated: 2023/10/24 17:18:58 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sourc;
	size_t	i;

	dest = (char *)dst;
	sourc = (char *) src;
	i = 0;
	if (dest == NULL && sourc == NULL)
		return (NULL);
	while (i < n)
	{
		dest[i] = sourc[i];
		i++;
	}
	return (dst);
}

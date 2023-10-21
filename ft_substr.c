/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:21:04 by ulyildiz          #+#    #+#             */
/*   Updated: 2023/10/18 10:15:00 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	substr = (char *)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
		return ("");
	substr = (char *)ft_memcpy(substr, &s[start], len);
	substr[len] = '\0';
	return (substr);
}

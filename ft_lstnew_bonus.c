/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:52:03 by ulyildiz          #+#    #+#             */
/*   Updated: 2023/10/21 10:55:52 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptobox;

	ptobox = (t_list *)malloc(sizeof(t_list));
	if (ptobox == NULL)
		return (NULL);
	ptobox -> content = content;
	ptobox -> next = NULL;
	return (ptobox);
}

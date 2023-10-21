/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:13:40 by ulyildiz          #+#    #+#             */
/*   Updated: 2023/10/21 10:01:18 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
/*	int	i;
	i = 3;
	i = ft_lstsize(lst);
	printf("%d", i);
*/	
	if (lst == NULL)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}
/*int main()
{
	t_list a;
	t_list b;
	t_list *first = &a;

	a.content = "al";
	a.next = &b;
	b.content = "la";
	b.next = NULL;

	t_list *conc = ft_lstlast(first);
	printf("%s", conc->content);
}*/
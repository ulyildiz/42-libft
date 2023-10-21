/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:19:32 by ulyildiz          #+#    #+#             */
/*   Updated: 2023/10/17 22:34:59 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	d;
	int	is;

	is = 1;
	d = 0;
	while (*str == 32 || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		d = (*str - '0') + d * 10;
		str++;
	}
	return (is * d);
}

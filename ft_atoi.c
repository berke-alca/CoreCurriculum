/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:21:53 by balca             #+#    #+#             */
/*   Updated: 2026/10/17 14:39:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		counter;
	long	res;
	int		minus;

	minus = 1;
	res = 0;
	counter = 0;
	while (str[counter] == ' ' || (str[counter] >= 9 && str[counter] <= 13))
		counter++;
	if (str[counter] == '-' || str[counter] == '+')
	{
		if (str[counter] == '-')
			minus = -1;
		counter++;
	}
	while (str[counter] >= '0' && str[counter] <= '9')
	{
		res = res * 10 + (str[counter] - '0');
		counter++;
	}
	return ((int)(res * minus));
}
// int main()
// {
// 	int erg = (ft_atoi("--42"));
// 	printf("%d", erg);
// }
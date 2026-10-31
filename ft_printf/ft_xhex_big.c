/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xhex_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: b3 <b3@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 21:18:21 by b3                #+#    #+#             */
/*   Updated: 2026/10/31 21:22:45 by b3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	laength(unsigned int n)
{
	int	laength;

	laength = 0;
	if (n <= 0)
	{
		laength++;
	}
	while (n != 0)
	{
		n = n / 16;
		laength++;
	}
	return (laength);
}

static char	*ft_itoa_hex(unsigned int n)
{
	char	*new_arr;
	int		index;
	long	temp;

	temp = n;
	index = laength(n);
	new_arr = malloc(sizeof(char) * (index + 1));
	if (!new_arr)
		return (NULL);
	new_arr[index--] = '\0';
	if (n == 0)
		new_arr[0] = '0';
	while (temp > 0)
	{
		new_arr[index--] = "0123456789ABCDEF"[temp % 16];
		temp = temp / 16;
	}
	return (new_arr);
}
int print_xhex_big(unsigned int u)
{
    char	*number;
	int		return_value;

	number = ft_itoa_hex(u);
	if(number == NULL)
		return (-1);
	return_value = ft_strlen(number);
	print_string(number);
	free(number);
	return(return_value);
}
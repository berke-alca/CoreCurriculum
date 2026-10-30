/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 13:32:09 by balca             #+#    #+#             */
/*   Updated: 2026/10/30 14:05:32 by balca            ###   ########.fr       */
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
		n = n / 10;
		laength++;
	}
	return (laength);
}

char	*ft_itoa_unsigned(unsigned int n)
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
		new_arr[index--] = temp % 10 + '0';
		temp = temp / 10;
	}
	return (new_arr);
}

int print_unsigned(unsigned int u)
{
	char	*number;
	int		return_value;

	number = ft_itoa_unsigned(u);
	if(number == NULL)
		return (-1);
	return_value = ft_strlen(number);
	print_string(number);
	free(number);
	return(return_value);
}
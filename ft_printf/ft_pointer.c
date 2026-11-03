/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:42:31 by balca             #+#    #+#             */
/*   Updated: 2026/11/03 12:27:50 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	laength(unsigned long n)
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

static char	*ft_itoa_ptr(unsigned long n)
{
	char			*new_arr;
	int				index;
	unsigned long	temp;

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
		new_arr[index--] = "0123456789abcdef"[temp % 16];
		temp = temp / 16;
	}
	return (new_arr);
}

int	print_pointer(void *ptr)
{
	int		counter;
	char	*number;

	counter = 0;
	if (!ptr)
		return (print_string("(nil)"));
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	counter = 2;
	number = ft_itoa_ptr((unsigned long)ptr);
	counter += print_string(number);
	free(number);
	return (counter);
}

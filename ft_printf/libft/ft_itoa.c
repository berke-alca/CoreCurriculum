/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:16:10 by balca             #+#    #+#             */
/*   Updated: 2026/10/19 14:28:49 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	laength(int n)
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

char	*ft_itoa(int n)
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
	if (n < 0)
	{
		new_arr[0] = '-';
		temp = -temp;
	}
	while (temp > 0)
	{
		new_arr[index--] = temp % 10 + '0';
		temp = temp / 10;
	}
	return (new_arr);
}
// int main()
// {
// 		char *text;
// 		text = ft_itoa(-2147483648);
// 		printf("%s", text);
// }
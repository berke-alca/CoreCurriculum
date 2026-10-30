/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:56:02 by balca             #+#    #+#             */
/*   Updated: 2026/10/24 13:24:04 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	div;
	long	temp;
	char	print_int;
	char	print_tochar;

	temp = n;
	div = 1;
	if (temp < 0)
	{
		write(fd, "-", 1);
		temp = temp * -1;
	}
	while (temp / div > 9)
		div *= 10;
	while (div > 0)
	{
		print_int = temp / div;
		print_tochar = print_int + '0';
		write(fd, &print_tochar, 1);
		temp = temp % div;
		div /= 10;
	}
}

// int	main()
// {
// 	ft_putnbr_fd(-123456789, 1);
// }
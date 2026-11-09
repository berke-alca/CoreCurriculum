/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:43:36 by balca             #+#    #+#             */
/*   Updated: 2026/11/09 15:13:13 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	long	value;
	int		*buffer;

	if (argc < 2)
		return (0);
	buffer = malloc(sizeof(int) * (argc - 1));
	if (!buffer)
		return (1);
	i = 1;
	while (i < argc)
	{
		value = ft_atoi_ps(argv[i]);
		if (!is_number(argv[i]) || value > 2147483647 || value < -2147483648)
		{
			ft_putendl_fd("Error", 2);
			free(buffer);
			return (1);
		}
		buffer[i - 1] = (int)value;
		i++;
	}
	free(buffer);
	return (0);
}

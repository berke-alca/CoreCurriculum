/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:43:36 by balca             #+#    #+#             */
/*   Updated: 2026/11/09 12:17:10 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	counter;

	counter = argc;
	i = 0;
	while (counter > 0)
	{
		ft_printf("%s\n", argv[i]);
		i++;
		counter--;
	}
	return (counter);
}

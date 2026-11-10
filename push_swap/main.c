/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:43:36 by balca             #+#    #+#             */
/*   Updated: 2026/11/10 16:40:11 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	version;
	int			*buffer;

	ft_bzero(&version, sizeof(t_push_swap));
	if (parse_flags(&version, argc, argv) == 0)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	if (argc < 2)
		return (0);
	buffer = parse_args(argc, argv);
	if (!buffer)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	free(buffer);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:06:46 by balca             #+#    #+#             */
/*   Updated: 2026/11/10 16:30:22 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_flag(char *argument)
{
	int	i;

	i = 0;
	if (argument[i] == '-' && argument[i + 1] == '-')
	{
		return (1);
	}
	return (0);
}

int	set_flag(t_push_swap *version, char *arg)
{
	int	check;

	check = is_flag(arg);
	if (check != 1)
		return (0);
	else if (ft_strncmp(arg, "--simple", 9) == 0)
		version->level = SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		version->level = MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		version->level = COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		version->level = ADAPTIVE;
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		version->bench = 1;
	else
		return (0);
	return (1);
}

int	parse_flags(t_push_swap *version, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (is_flag(argv[i]) && set_flag(version, argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 16:28:50 by balca             #+#    #+#             */
/*   Updated: 2026/11/16 13:42:57 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_push_swap *version)
{
	int	i;
	int	min_index;

	min_index = 0;
	i = 1;
	while (i < version->a.size)
	{
		if (version->a.val[min_index] > version->a.val[i])
		{
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	sort_simple(t_push_swap *version)
{
	int	min_index;
	int	min_value;

	while (version->a.size > 0)
	{
		min_index = find_min_index(version);
		min_value = version->a.val[min_index];
		if (min_index <= version->a.size / 2)
		{
			while (version->a.val[0] != min_value)
				do_op(version, RA);
		}
		else
		{
			while (version->a.val[0] != min_value)
				do_op(version, RRA);
		}
		do_op(version, PB);
	}
	while (version->b.size > 0)
		do_op(version, PA);
}

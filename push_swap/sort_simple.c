/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 16:28:50 by balca             #+#    #+#             */
/*   Updated: 2026/11/13 17:23:45 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_push_swap *version)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < version->count)
	{
	}
}

int		find_min_index(t_push_swap *version)
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

void	rotate_to_top(void)
{

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 10:08:02 by balca             #+#    #+#             */
/*   Updated: 2026/11/16 13:42:50 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_bits(int maximum)
{
	int	lines;

	lines = 0;
	while ((1 << lines) <= maximum)
		lines++;
	return (lines);
}

void	sort_complex(t_push_swap *version)
{
	int	j;
	int	counter;
	int	lines;

	lines = count_bits(version->a.size - 1);
	j = 0;
	while (j < lines)
	{
		counter = version->a.size;
		while (counter > 0)
		{
			if (((version->a.val[0] >> j) & 1) == 0)
			{
				do_op(version, PB);
			}
			else
				do_op(version, RA);
			counter--;
		}
		while (version->b.size > 0)
			do_op(version, PA);
		j++;
	}
}

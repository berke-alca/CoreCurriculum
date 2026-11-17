/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjum <aanjum@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 16:59:51 by aanjum            #+#    #+#             */
/*   Updated: 2026/11/14 17:01:14 by aanjum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Function: compute_disorder
Prototype: int compute_disorder(t_stack *a);
Parameters:
a: stack a, before any move.
Purpose: Measure how far stack a is from sorted, as the subject defines it.
Algorithm: Look at every pair (i, j) with i above j. Each pair where the
upper number is bigger is a mistake. Result = mistakes * 10000 / pairs,
so 0 means sorted and 10000 means reversed (two decimals of a percent).
Return: Disorder in basis points, 0 to 10000.
Edge cases: Fewer than 2 numbers returns 0 (no pairs, no division by 0).
Memory: Does not allocate or free memory. Uses long to avoid overflow.
*/

int	compute_disorder(t_stack *a)
{
	long	mistakes;
	long	pairs;
	int		i;
	int		j;

	if (a->size < 2)
		return (0);
	mistakes = 0;
	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->val[i] > a->val[j])
				mistakes++;
			j++;
		}
		i++;
	}
	pairs = (long) a->size * (a->size - 1) / 2;
	return ((int)(mistakes * 10000 / pairs));
}

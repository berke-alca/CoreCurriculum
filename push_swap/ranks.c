/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 21:35:51 by aanjum            #+#    #+#             */
/*   Updated: 2026/11/13 14:11:50 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Function: count_smaller
Prototype: static int count_smaller(t_stack *a, int i);
Parameters:
a: stack a with the original numbers.
i: index of the number we want the rank of.
Purpose: Count how many numbers in a are smaller than a->val[i].
Algorithm: Walk the whole array once and add 1 for every smaller value.
Return: The rank of a->val[i], from 0 to size - 1.
Edge cases: Duplicates are rejected by the parser, so every rank is unique.
Memory: Does not allocate or free memory.
*/

static int	count_smaller(t_stack *a, int i)
{
	int	j;
	int	count;

	count = 0;
	j = 0;
	while (j < a->size)
	{
		if (a->val[j] < a->val[i])
			count++;
		j++;
	}
	return (count);
}

/*
Function: make_ranks
Prototype: int make_ranks(t_stack *a);
Parameters:
a: stack a filled with the parsed numbers.
Purpose: Replace every number by its position in sorted order,
so the stack holds 0..n-1 (for example 42 -7 100 becomes 1 0 2).
Algorithm: For each index, count the smaller numbers (that count is
the rank) and store it in a new array. Then free the old array and
keep the new one. The order of the stack does not change.
Return: 1 on success, 0 if malloc fails.
Edge cases: An empty stack returns 1 without allocating.
Memory: Allocates one new int array and frees the old one, so the
total memory stays the same. On failure nothing is changed.
*/

int	make_ranks(t_stack *a)
{
	int	*rank;
	int	i;

	if (a->size == 0)
		return (1);
	rank = malloc(sizeof(int) * a->size);
	if (!rank)
		return (0);
	i = 0;
	while (i < a->size)
	{
		rank[i] = count_smaller(a, i);
		i++;
	}
	free(a->val);
	a->val = rank;
	return (1);
}

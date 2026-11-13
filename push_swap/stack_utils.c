/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjum <aanjum@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:58:22 by aanjum            #+#    #+#             */
/*   Updated: 2026/11/12 16:13:19 by aanjum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function: is_sorted
Prototype: int is_sorted(t_ps *ps);
Parameters:
ps: the program state holding stack a and stack b.
Purpose: Check if the job is finished: stack a in ascending order
from top to bottom and stack b empty.
Algorithm: If b is not empty, return 0. Otherwise walk stack a
from index 0 (the top) and compare each number with the one below
it. As soon as a number is bigger than the next one, return 0.
If the loop reaches the end, return 1.
Return: 1 if sorted and b is empty, 0 otherwise.
Edge cases: 0 or 1 numbers in a count as sorted, so
"./push_swap 42" prints nothing. Duplicates cannot occur because
the parser rejects them, so ">" is enough.
Memory: Does not allocate or free memory.
*/

/*
Function: free_stacks
Prototype: void free_stacks(t_ps *ps);
Parameters:
ps: the program state holding stack a and stack b.
Purpose: Release the memory of both stacks before the program ends,
on normal exits and on error exits.
Algorithm: Free the array of a and the array of b, then set both
pointers to NULL and both sizes to 0.
Return: Nothing.
Edge cases: Safe if an array was never allocated, because free(NULL)
does nothing. Safe if called twice, because the pointers are NULL
after the first call.
Memory: Frees the two arrays created by init_stacks. Does not free
ps itself, because ps lives on the stack in main.
*/

#include "push_swap.h"

int	is_sorted(t_push_swap *ps)
{
	int	i;

	if (ps->b.size != 0)
		return (0);
	i = 0;
	while (i < ps->a.size - 1)
	{
		if (ps->a.val[i] > ps->a.val[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	free_stacks(t_push_swap *ps)
{
	free(ps->a.val);
	free(ps->b.val);
	ps->a.val = NULL;
	ps->b.val = NULL;
	ps->a.size = 0;
	ps->b.size = 0;
}

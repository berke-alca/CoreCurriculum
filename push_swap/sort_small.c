/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjum <aanjum@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 16:22:56 by aanjum            #+#    #+#             */
/*   Updated: 2026/11/15 17:01:31 by aanjum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Function: min_index
Prototype: static int min_index(t_stack *s);
Parameters:
s: the stack to search (here always stack a).
Purpose: Find where the smallest number of the stack is.
Algorithm: Walk the array once and remember the index of the smallest value.
Return: Index of the smallest number, 0 being the top.
Edge cases: Only called while the stack has more than 3 numbers.
Memory: Does not allocate or free memory.
*/

static int	min_index(t_stack *s)
{
	int	i;
	int	best;

	best = 0;
	i = 1;
	while (i < s->size)
	{
		if (s->val[i] < s->val[best])
			best = i;
		i++;
	}
	return (best);
}

/*
Function: rotate_a_to_top
Prototype: static void rotate_a_to_top(t_push_swap *ps, int idx);
Parameters:
ps: program state.
idx: position in stack a of the number to bring to the top.
Purpose: Bring one number of a to the top with the fewest moves.
Algorithm: In the top half, ra idx times. In the bottom half,
rra (size - idx) times, which is shorter.
Return: Nothing.
Edge cases: idx = 0 does nothing.
Memory: Does not allocate or free memory.
*/

static void	rotate_a_to_top(t_push_swap *ps, int idx)
{
	int	moves;

	if (idx <= ps->a.size / 2)
	{
		while (idx > 0)
		{
			do_op(ps, RA);
			idx--;
		}
		return ;
	}
	moves = ps->a.size - idx;
	while (moves > 0)
	{
		do_op(ps, RRA);
		moves--;
	}
}

/*
Function: sort_three
Prototype: static void sort_three(t_push_swap *ps);
Parameters:
ps: program state, stack a holds exactly 3 numbers.
Purpose: Sort 3 numbers in at most 2 moves.
Algorithm: First put the biggest number at the bottom: if it is on top,
ra; if it is in the middle, rra. Then the two left on top only need
an sa if they are in the wrong order.
Return: Nothing.
Edge cases: Already sorted input makes no move.
Memory: Does not allocate or free memory.
*/

static void	sort_three(t_push_swap *ps)
{
	int	*v;

	v = ps->a.val;
	if (v[0] > v[1] && v[0] > v[2])
		do_op(ps, RA);
	else if (v[1] > v[0] && v[1] > v[2])
		do_op(ps, RRA);
	v = ps->a.val;
	if (v[0] > v[1])
		do_op(ps, SA);
}

/*
Function: sort_small
Prototype: void sort_small(t_push_swap *ps);
Parameters:
ps: program state, stack a holds 2 to 5 numbers, stack b is empty.
Purpose: Sort small inputs with very few moves (used by --adaptive only).
Algorithm: 2 numbers: sa if needed. 3 numbers: sort_three.
4 or 5 numbers: push the smallest to b (brought to the top the short
way) until 3 are left, sort_three, then pa them back. They come back
smallest last, so they land on top in the right order.
Return: Nothing.
Edge cases: Fewer than 2 numbers does nothing. Max 2 moves for 3
numbers, max 10 moves for 5 numbers.
Memory: Does not allocate or free memory.
*/

void	sort_small(t_push_swap *ps)
{
	if (ps->a.size < 2)
		return ;
	if (ps->a.size == 2)
	{
		if (ps->a.val[0] > ps->a.val[1])
			do_op(ps, SA);
		return ;
	}
	while (ps->a.size > 3)
	{
		rotate_a_to_top(ps, min_index(&ps->a));
		do_op(ps, PB);
	}
	sort_three(ps);
	while (ps->b.size > 0)
		do_op(ps, PA);
}

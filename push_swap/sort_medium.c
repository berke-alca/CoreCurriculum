/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjum <aanjum@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 16:49:22 by aanjum            #+#    #+#             */
/*   Updated: 2026/11/14 16:56:52 by aanjum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Function: ft_isqrt
Prototype: static int ft_isqrt(int n);
Parameters:
n: the number to take the square root of.
Purpose: Integer square root, because sqrt from math.h is not allowed.
Algorithm: Start at 0 and go up while (r + 1) * (r + 1) still fits in n.
Return: The largest r with r * r <= n.
Edge cases: n = 0 or 1 returns n.
Memory: Does not allocate or free memory.
*/

static int	ft_isqrt(int n)
{
	int	r;

	r = 0;
	while ((r + 1) * (r + 1) <= n)
		r++;
	return (r);
}

/*
Function: max_index
Prototype: static int max_index(t_stack *s);
Parameters:
s: the stack to search (here always stack b).
Purpose: Find where the biggest number of the stack is.
Algorithm: Walk the array once and remember the index of the largest value.
Return: Index of the biggest number, 0 being the top.
Edge cases: Only called while the stack is not empty.
Memory: Does not allocate or free memory.
*/

static int	max_index(t_stack *s)
{
	int	i;
	int	best;

	best = 0;
	i = 1;
	while (i < s->size)
	{
		if (s->val[i] > s->val[best])
			best = i;
		i++;
	}
	return (best);
}

/*
Function: rotate_b_to_top
Prototype: static void rotate_b_to_top(t_push_swap *ps, int idx);
Parameters:
ps: program state.
idx: position in stack b of the number to bring to the top.
Purpose: Bring one number of b to the top with the fewest moves.
Algorithm: In the top half, rb idx times. In the bottom half,
rrb (size - idx) times, which is shorter.
Return: Nothing.
Edge cases: idx = 0 does nothing.
Memory: Does not allocate or free memory.
*/

static void	rotate_b_to_top(t_push_swap *ps, int idx)
{
	int	moves;

	if (idx <= ps->b.size / 2)
	{
		while (idx > 0)
		{
			do_op(ps, RB);
			idx--;
		}
		return ;
	}
	moves = ps->b.size - idx;
	while (moves > 0)
	{
		do_op(ps, RRB);
		moves--;
	}
}

/*
Function: fill_b
Prototype: static void fill_b(t_push_swap *ps, int k);
Parameters:
ps: program state, stack a holds ranks 0..n-1.
k: window size.
Purpose: Move every number from a to b in rough order (phase 1).
Algorithm: i counts the numbers pushed so far. If the top of a is
below i, push it and rb (it goes to the bottom of b). If it is below
i + k, push it (it stays on top). Otherwise ra and look at the next.
Return: Nothing.
Edge cases: Always ends: while a is not empty, some number in a is
below i + k, because only i numbers have left a.
Memory: Does not allocate or free memory.
*/

static void	fill_b(t_push_swap *ps, int k)
{
	int	i;

	i = 0;
	while (ps->a.size > 0)
	{
		if (ps->a.val[0] < i)
		{
			do_op(ps, PB);
			do_op(ps, RB);
			i++;
		}
		else if (ps->a.val[0] < i + k)
		{
			do_op(ps, PB);
			i++;
		}
		else
			do_op(ps, RA);
	}
}

/*
Function: sort_medium
Prototype: void sort_medium(t_push_swap *ps);
Parameters:
ps: program state, stack a holds ranks 0..n-1, stack b is empty.
Purpose: The O(n sqrt n) strategy (--medium): chunk sort.
Algorithm: Window k = sqrt(n) * 3 / 2 (15 for 100, 33 for 500).
Phase 1: fill_b. Phase 2: while b is not empty, bring its biggest
number to the top the short way and pa. a ends up sorted.
Return: Nothing.
Edge cases: Works for any size from 2 up; k is at least 1.
Memory: Does not allocate or free memory; uses the stacks only.
*/

void	sort_medium(t_push_swap *ps)
{
	int	k;

	k = ft_isqrt(ps->a.size) * 3 / 2;
	if (k < 1)
		k = 1;
	fill_b(ps, k);
	while (ps->b.size > 0)
	{
		rotate_b_to_top(ps, max_index(&ps->b));
		do_op(ps, PA);
	}
}

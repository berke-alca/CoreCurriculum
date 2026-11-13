/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 21:38:21 by aanjum            #+#    #+#             */
/*   Updated: 2026/11/13 14:08:30 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Function: choose_adaptive
Prototype: static t_strat choose_adaptive(int disorder_bp);
Parameters:
disorder_bp: disorder in basis points, 0 to 10000.
Purpose: Pick the internal method for --adaptive.
Algorithm: Below 2000 (0.2) use simple, below 5000 (0.5) use medium,
otherwise use complex, as the subject requires.
Return: SIMPLE, MEDIUM or COMPLEX.
Edge cases: Exactly 2000 goes to medium and exactly 5000 goes to complex.
Memory: Does not allocate or free memory.
*/

static t_strat	choose_adaptive(int disorder_bp)
{
	if (disorder_bp < 2000)
		return (SIMPLE);
	if (disorder_bp < 5000)
		return (MEDIUM);
	return (COMPLEX);
}

/*
Function: dispatch
Prototype: void dispatch(t_push_swap *ps);
Parameters:
ps: program state with stacks, chosen level and measured disorder.
Purpose: Run the right sorting algorithm for the flag and the input.
Algorithm: Store the level actually used (for --bench), resolving
--adaptive through the disorder. If a is already sorted, do nothing.
With 5 numbers or fewer, use the small sorts for every flag.
Otherwise call simple, medium or complex.
Return: Nothing.
Edge cases: Sorted input prints no moves. ps->disorder_bp must be
computed before dispatch, before any move.
Memory: Does not allocate or free memory.
*/

void	dispatch(t_push_swap *ps)
{
	ps->used = ps->strategy;
	if (ps->strategy == ADAPTIVE)
		ps->used = choose_adaptive(ps->disorder_bp);
	if (is_sorted(ps))
		return ;
	if (ps->a.size <= 5)
		sort_small(ps);
	else if (ps->used == SIMPLE)
		sort_simple(ps);
	else if (ps->used == MEDIUM)
		sort_medium(ps);
	else
		sort_complex(ps);
}

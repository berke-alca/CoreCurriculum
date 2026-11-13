/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjum <aanjum@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 21:27:43 by aanjum            #+#    #+#             */
/*   Updated: 2026/11/12 13:51:30 by aanjum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
sa, sb, ss: swap the top two elements of a stack.
void op_sa(t_push_swap *ps) - swaps top two of stack a.
void op_sb(t_push_swap *ps) - swaps top two of stack b.
void op_ss(t_push_swap *ps) - does sa and sb at the same time.
Does nothing if the stack has fewer than 2 elements.
swap_top is a static helper that does the actual swap.
*/

static void	swap_top(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return ;
	tmp = s->val[0];
	s->val[0] = s->val[1];
	s->val[1] = tmp;
}

void	op_sa(t_push_swap *ps)
{
	swap_top(&ps->a);
}

void	op_sb(t_push_swap *ps)
{
	swap_top(&ps->b);
}

void	op_ss(t_push_swap *ps)
{
	swap_top(&ps->a);
	swap_top(&ps->b);
}

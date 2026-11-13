/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 21:34:09 by aanjum            #+#    #+#             */
/*   Updated: 2026/11/13 13:20:54 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
pa, pb: move the top element from one stack to the other.
void op_pa(t_push_swap *ps) - top of b goes to top of a.
void op_pb(t_push_swap *ps) - top of a goes to top of b.
Does nothing if the source stack is empty.
push_to is a static helper: shifts dst right to make
room at index 0, copies top of src, shifts src left.*/

static void	push_to(t_stack *dst, t_stack *src)
{
	int	i;

	if (src->size == 0)
		return ;
	i = dst->size;
	while (i > 0)
	{
		dst->val[i] = dst->val[i - 1];
		i--;
	}
	dst->val[0] = src->val[0];
	dst->size++;
	i = 0;
	while (i < src->size - 1)
	{
		src->val[i] = src->val[i + 1];
		i++;
	}
	src->size--;
}

void	op_pa(t_push_swap *ps)
{
	push_to(&ps->a, &ps->b);
}

void	op_pb(t_push_swap *ps)
{
	push_to(&ps->b, &ps->a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:02:18 by balca             #+#    #+#             */
/*   Updated: 2026/11/13 14:17:15 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_up(t_stack *st)
{
	int	i;
	int	tmp;

	if (st->size <= 1)
		return ;
	tmp = st->val[0];
	i = 0;
	while (i < st->size - 1)
	{
		st->val[i] = st->val[i + 1];
		i++;
	}
	st->val[st->size - 1] = tmp;
}

void	op_ra(t_push_swap *ra)
{
	rotate_up (&ra->a);
}

void	op_rb(t_push_swap *rb)
{
	rotate_up (&rb->b);
}

void	op_rr(t_push_swap *rr)
{
	rotate_up (&rr->a);
	rotate_up (&rr->b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:51:29 by balca             #+#    #+#             */
/*   Updated: 2026/11/12 14:03:22 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_reverse(t_stack *st)
{
	int	i;
	int	tmp;

	if (st->size <= 1)
		return ;
	tmp = st->val[st->size - 1];
	i = st->size - 1;
	while (i > 0)
	{
		st->val[i] = st->val[i - 1];
		i--;
	}
	st->val[0] = tmp;
}

void	rra(t_push_swap *rra)
{
	rotate_reverse(&rra->a);
}

void	rrb(t_push_swap *rrb)
{
	rotate_reverse(&rrb->b);
}

void	rrr(t_push_swap *rrr)
{
	rotate_reverse(&rrr->a);
	rotate_reverse(&rrr->b);
}

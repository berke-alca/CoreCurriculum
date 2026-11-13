/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:51:29 by balca             #+#    #+#             */
/*   Updated: 2026/11/13 13:21:37 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_reverse(t_stack *st)
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

void	op_rra(t_push_swap *rra)
{
	rotate_reverse(&rra->a);
}

void	op_rrb(t_push_swap *rrb)
{
	rotate_reverse(&rrb->b);
}

void	op_rrr(t_push_swap *rrr)
{
	rotate_reverse(&rrr->a);
	rotate_reverse(&rrr->b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:37:23 by balca             #+#    #+#             */
/*   Updated: 2026/11/12 16:07:29 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_op(t_push_swap *ps, t_op op)
{
	if (op == SA)
		op_sa(ps);
	if (op == SB)
		op_sb(ps);
	if (op == SS)
		op_ss(ps);
	if (op == PA)
		op_pa(ps);
	if (op == PB)
		op_pb(ps);
	if (op == RA)
		op_ra(ps);
	if (op == RB)
		op_rb(ps);
	if (op == RR)
		op_rr(ps);
	if (op == RRA)
		op_rra(ps);
	if (op == RRB)
		op_rrb(ps);
	if (op == RRR)
		op_rrr(ps);
}

static char	*op_name(t_op op)
{
	char	*names[11];

	names[0] = "sa";
	names[1] = "sb";
	names[2] = "ss";
	names[3] = "pa";
	names[4] = "pb";
	names[5] = "ra";
	names[6] = "rb";
	names[7] = "rr";
	names[8] = "rra";
	names[9] = "rrb";
	names[10] = "rrr";
	return (names[op]);
}

void	do_op(t_push_swap *version, t_op operation)
{
	apply_op(version, operation);
	version->count[operation]++;
	if (version->print == 1)
	{
		ft_printf("%s\n", op_name(operation));
	}
}

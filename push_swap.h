/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:32:28 by balca             #+#    #+#             */
/*   Updated: 2026/11/12 16:32:30 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf.h"

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*val;
	int	size;
}	t_stack;

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
}	t_op;

typedef enum e_strat
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strat;

typedef struct s_push_swap
{
	t_stack	a;
	t_stack	b;
	int		count[OP_COUNT];
	int		print;
	int		bench;
	int		strategy;
	int		used;
	int		disorder_bp;
}	t_push_swap;

/* parsing.c */
int		is_number(char *text);
long	ft_atoi_ps(const char *str);
int		has_duplicates(int *buffer, int size);
int		count_numbers(int argc, char **argv);
int		*parse_args(int argc, char **argv, int *out_count);

/* flag.c */
int		is_flag(char *argument);
int		set_flag(t_push_swap *version, char *arg);
int		parse_flags(t_push_swap *version, int argc, char **argv);

/* do_op.c */
void	do_op(t_push_swap *ps, t_op op);

/* ops_swap.c - Areej */
void	op_sa(t_push_swap *ps);
void	op_sb(t_push_swap *ps);
void	op_ss(t_push_swap *ps);

/* ops_push.c - Areej */
void	op_pa(t_push_swap *ps);
void	op_pb(t_push_swap *ps);

/* ops_rotate.c */
void	op_ra(t_push_swap *ps);
void	op_rb(t_push_swap *ps);
void	op_rr(t_push_swap *ps);

/* ops_reverse.c */
void	op_rra(t_push_swap *ps);
void	op_rrb(t_push_swap *ps);
void	op_rrr(t_push_swap *ps);

/* stack_utils.c - Areej */
int		is_sorted(t_push_swap *ps);
void	free_stacks(t_push_swap *ps);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:18:08 by aanjum            #+#    #+#             */
/*   Updated: 2026/11/13 14:21:53 by balca            ###   ########.fr       */
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
void	rotate_reverse(t_stack *st);

/* stack_utils.c - Areej */
int		is_sorted(t_push_swap *ps);
void	free_stacks(t_push_swap *ps);

/* rank.c - Areej */
int		make_ranks(t_stack *a);

/* dispatch.c - Areej */
void	dispatch(t_push_swap *ps);

/*error message for main*/
int		print_error(t_push_swap *version);

/*stack init*/
int		init_stacks(t_push_swap *version, int *buffer, int count);

/*sort.x.c files*/
void	sort_small(t_push_swap *version);
void	sort_simple(t_push_swap *version);
void	sort_medium(t_push_swap *version);
void	sort_complex(t_push_swap *version);
#endif

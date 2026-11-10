/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:43:39 by balca             #+#    #+#             */
/*   Updated: 2026/11/10 16:31:22 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf.h"

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
	int		count[11];
	int		print;
	int		bench;
	int		level;
	int		used;
	int		disorder_bp;
}	t_push_swap;


int		is_number(char *text);
long	ft_atoi_ps(const char *str);
int		has_duplicates(int *buffer, int size);
int		*parse_args(int argc, char **argv);
int		is_flag(char *argument);
int		set_flag(t_push_swap *version, char *arg);
int		parse_flags(t_push_swap *version, int argc, char **argv);

#endif
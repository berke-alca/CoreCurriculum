/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjum <aanjum@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 16:40:44 by aanjum            #+#    #+#             */
/*   Updated: 2026/11/15 18:02:04 by aanjum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Function: put_percent
Prototype: static void put_percent(int bp);
Parameters:
bp: disorder in basis points, 0 to 10000.
Purpose: Print the disorder as a percentage with two decimals, on stderr.
Algorithm: bp / 100 is the whole part, bp % 100 the two decimals, so
4987 prints as 49.87%. No float is needed (ft_printf has no %f).
Return: Nothing.
Edge cases: 0 prints 0.00%, 10000 prints 100.00%, 5 prints 0.05%.
Memory: Does not allocate or free memory.
*/

static void	put_percent(int bp)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(bp / 100, 2);
	ft_putchar_fd('.', 2);
	ft_putchar_fd('0' + bp % 100 / 10, 2);
	ft_putchar_fd('0' + bp % 10, 2);
	ft_putstr_fd("%\n", 2);
}

/*
Function: put_strategy
Prototype: static void put_strategy(t_push_swap *ps);
Parameters:
ps: program state with the chosen flag and the strategy used.
Purpose: Print the strategy name and its complexity class, on stderr.
Algorithm: With --adaptive (or no flag), first say "adaptive ->", then
the method it really ran: small sort for 5 numbers or fewer, otherwise
simple, medium or complex with its class.
Return: Nothing.
Edge cases: A forced flag never prints "adaptive".
Memory: Does not allocate or free memory.
*/

static void	put_strategy(t_push_swap *ps)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (ps->strategy == ADAPTIVE)
		ft_putstr_fd("adaptive -> ", 2);
	if (ps->strategy == ADAPTIVE && ps->a.size <= 5)
		ft_putstr_fd("small sort, O(1)\n", 2);
	else if (ps->used == SIMPLE)
		ft_putstr_fd("simple, O(n^2)\n", 2);
	else if (ps->used == MEDIUM)
		ft_putstr_fd("medium, O(n*sqrt(n))\n", 2);
	else
		ft_putstr_fd("complex, O(n log n)\n", 2);
}

/*
Function: fill_names
Prototype: static void fill_names(char **names);
Parameters:
names: an array of OP_COUNT strings to fill.
Purpose: Give each operation its printed name, in the order of t_op.
Algorithm: One assignment per operation (no global array, which the
subject forbids).
Return: Nothing.
Edge cases: The order must match the enum e_op in push_swap.h.
Memory: Does not allocate; the names are string literals.
*/

static void	fill_names(char **names)
{
	names[SA] = "sa";
	names[SB] = "sb";
	names[SS] = "ss";
	names[PA] = "pa";
	names[PB] = "pb";
	names[RA] = "ra";
	names[RB] = "rb";
	names[RR] = "rr";
	names[RRA] = "rra";
	names[RRB] = "rrb";
	names[RRR] = "rrr";
}

/*
Function: put_counts
Prototype: static void put_counts(t_push_swap *ps);
Parameters:
ps: program state with the 11 counters filled by do_op.
Purpose: Print the total number of operations and the count of each
operation, on stderr.
Algorithm: Add up the 11 counters for the total, then print every
operation name with its counter.
Return: Nothing.
Edge cases: Sorted input prints a total of 0 and all counters at 0.
Memory: Does not allocate or free memory.
*/

static void	put_counts(t_push_swap *ps)
{
	char	*names[OP_COUNT];
	int		i;
	int		total;

	fill_names(names);
	total = 0;
	i = 0;
	while (i < OP_COUNT)
	{
		total += ps->count[i];
		i++;
	}
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putstr_fd("\n[bench]", 2);
	i = 0;
	while (i < OP_COUNT)
	{
		ft_putchar_fd(' ', 2);
		ft_putstr_fd(names[i], 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(ps->count[i], 2);
		i++;
	}
	ft_putchar_fd('\n', 2);
}

/*
Function: print_bench
Prototype: void print_bench(t_push_swap *ps);
Parameters:
ps: program state after sorting.
Purpose: The --bench report: disorder, strategy and class, total and
per-operation counts. Everything goes to stderr, so stdout keeps only
the moves for the checker.
Algorithm: Do nothing without --bench, otherwise print the four parts.
Return: Nothing.
Edge cases: Called after dispatch and before free_stacks.
Memory: Does not allocate or free memory.
*/

void	print_bench(t_push_swap *ps)
{
	if (!ps->bench)
		return ;
	put_percent(ps->disorder_bp);
	put_strategy(ps);
	put_counts(ps);
}

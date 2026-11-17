/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjum <aanjum@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:43:36 by aanjum            #+#    #+#             */
/*   Updated: 2026/11/17 15:32:32 by aanjum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	version;
	int			*buffer;
	int			count;

	if (argc < 2)
		return (0);
	ft_bzero(&version, sizeof(t_push_swap));
	version.print = 1;
	if (parse_flags(&version, argc, argv) == 0)
		return (print_error(&version));
	if (count_numbers(argc, argv) == 0)
		return (0);
	buffer = parse_args(argc, argv, &count);
	if (!buffer)
		return (print_error(&version));
	if (init_stacks(&version, buffer, count) == 0)
		return (print_error(&version));
	if (make_ranks(&version.a) == 0)
		return (print_error(&version));
	version.disorder_bp = compute_disorder(&version.a);
	dispatch(&version);
	print_bench(&version);
	free_stacks(&version);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:21:26 by aanjum            #+#    #+#             */
/*   Updated: 2026/11/16 13:40:19 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stacks(t_push_swap *version, int *buffer, int count)
{
	version->a.val = buffer;
	version->a.size = count;
	version->b.val = malloc(sizeof (int) * count);
	if (!version->b.val)
		return (0);
	version->b.size = 0;
	return (1);
}

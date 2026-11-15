/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: b3 <b3@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 16:12:51 by balca               #+#    #+#             */
/*   Updated: 2026/11/15 16:12:51 by b3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_chunks(t_push_swap *version)
{
    int counter;
    int chunks_needed;

    counter = 1;
    while ((counter + 1) * (counter + 1) <= version->a.size)
    {
        counter++;
    }
    if (chunks_needed <= 1)
        return (1);
    chunks_needed = counter / 2;
    return (chunks_needed);
}
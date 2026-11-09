/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 12:39:30 by balca             #+#    #+#             */
/*   Updated: 2026/11/09 13:10:58 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *text)
{
	int	i;
	int	check;

	i = 0;
	if (text[i] == '-' || text[i] == '+')
	{
		i++;
	}
	if (text[i] == '\0')
		return (0);
	while (text[i] != '\0')
	{
		check = ft_isdigit(text[i]);
		if (check == 0)
			return (0);
		i++;
	}
	return (1);
}

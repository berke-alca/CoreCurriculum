/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 12:52:39 by balca             #+#    #+#             */
/*   Updated: 2026/11/03 12:33:49 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str)
{
	int	size;

	if (str == NULL)
		return (print_string("(null)"));
	size = ft_strlen(str);
	write(1, str, size);
	return (size);
}

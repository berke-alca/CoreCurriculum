/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 13:17:47 by balca             #+#    #+#             */
/*   Updated: 2026/10/30 13:29:45 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_int(int i)
{
	char	*number;
	int		return_value;

	number = ft_itoa(i);
	if(number == NULL)
		return (-1);
	return_value = ft_strlen(number);
	print_string(number);
	free(number);
	return(return_value);
}

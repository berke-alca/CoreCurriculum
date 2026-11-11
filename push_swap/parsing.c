/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 12:39:30 by balca             #+#    #+#             */
/*   Updated: 2026/11/10 16:01:04 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *text)
{
	long	i;
	long	check;

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

long	ft_atoi_ps(const char *str)
{
	long		counter;
	long		res;
	long		minus;

	minus = 1;
	res = 0;
	counter = 0;
	while (str[counter] == ' ' || (str[counter] >= 9 && str[counter] <= 13))
		counter++;
	if (str[counter] == '-' || str[counter] == '+')
	{
		if (str[counter] == '-')
			minus = -1;
		counter++;
	}
	while (str[counter] >= '0' && str[counter] <= '9')
	{
		res = res * 10 + (str[counter] - '0');
		if (res > 2147483648)
			return (res * minus);
		counter++;
	}
	return (res * minus);
}

int	has_duplicates(int *buffer, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (size > j)
		{
			if (buffer[i] == buffer[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	*parse_args(int argc, char **argv)
{
	int		i;
	long	value;
	int		*buffer;

	buffer = malloc(sizeof(int) * (argc - 1));
	if (!buffer)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		while (is_flag(argv[i]) == 1)
			i++;
		value = ft_atoi_ps(argv[i]);
		if (!is_number(argv[i]) || value > 2147483647 || value < -2147483648)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i - 1] = (int)value;
		i++;
	}
	if (has_duplicates(buffer, argc - 1) == 1)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjum <aanjum@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 12:39:30 by aanjum            #+#    #+#             */
/*   Updated: 2026/11/12 13:57:03 by aanjum           ###   ########.fr       */
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

int	count_numbers(int argc, char **argv)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	while (i < argc)
	{
		if (!is_flag(argv[i]))
			n++;
		i++;
	}
	return (n);
}

long	ft_atoi_ps(const char *str)
{
	long	counter;
	long	res;
	long	minus;

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

int	*parse_args(int argc, char **argv, int *out_count)
{
	int		i;
	int		j;
	long	value;
	int		*buffer;

	*out_count = count_numbers(argc, argv);
	if (*out_count == 0)
		return (NULL);
	buffer = malloc(sizeof(int) * (*out_count));
	if (!buffer)
		return (NULL);
	i = 1;
	j = 0;
	while (i < argc)
	{
		value = ft_atoi_ps(argv[i]);
		if (!is_number(argv[i]) || value > 2147483647 || value < -2147483648)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i - 1] = (int) value;
		if (!is_flag(argv[i]))
		{
			value = ft_atoi_ps(argv[i]);
			if (!is_number(argv[i]) || value > 2147483647
					|| value < -2147483648)
			return (free(buffer), NULL);
			buffer[j++] = (int) value;
		}
		i++;
	}
	if (has_duplicates(buffer, *out_count))
		return (free(buffer), NULL);
	return (buffer);
}
//Areej: was not skiping flgs if you run ./push_swap --simple 3 2 1 so it tries to parse --simple as a number and return error.
// int	*parse_args(int argc, char **argv, int *out_count)
// {
// 	int		i;
// 	int		j;
// 	long	value;
// 	int		*buffer;

// 	*out_count = count_numbers(argc, argv);
// 	if (*out_count == 0)
// 		return (NULL);
// 	buffer = malloc(sizeof(int) * (*out_count));
// 	if (!buffer)
// 		return (NULL);
// 	i = 1;
// 	j = 0;
// 	while (i < argc)
// 	{
// 		if (!is_flag(argv[i]))
// 		{
// 			value = ft_atoi_ps(argv[i]);
// 			if (!is_number(argv[i]) || value > 2147483647
// 					|| value < -2147483648)
// 			return (free(buffer), NULL);
// 			buffer[j++] = (int) value;
// 		}
// 		i++;
// 	}
// 	if (has_duplicates(buffer, *out_count))
// 		return (free(buffer), NULL);
// 	return (buffer);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: b3 <b3@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 14:56:35 by balca             #+#    #+#             */
/*   Updated: 2026/11/17 23:59:55 by b3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == ' ')
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] != '\0' && s[i] != ' ')
			i++;
	}
	return (words);
}

static int	count_tokens(int argc, char **argv)
{
	int	counter;
	int	sum;

	sum = 0;
	counter = 1;
	while (counter < argc)
	{
		if (!is_flag(argv[counter]))
			sum += count_words(argv[counter]);
		counter++;
	}
	return (sum);
}

static void	free_words(char **words)
{
	int	counter;

	counter = 0;
	while (words[counter] != NULL)
	{
		free(words[counter]);
		counter++;
	}
	free(words);
}

static int	fill(char *arg, int *buffer, int *j)
{
	char	**words;
	long	value;
	int		i;

	words = ft_split(arg, ' ');
	if (words == NULL)
		return (0);
	if (words[0] == NULL)
		return (free_words(words), 0);
	i = 0;
	while (words[i] != NULL)
	{
		value = ft_atoi_ps(words[i]);
		if (is_number(words[i]) == 0 || (int)value != value)
			return (free_words(words), 0);
		buffer[*j] = (int)value;
		(*j)++;
		i++;
	}
	free_words(words);
	return (1);
}

int	*parse_args(int argc, char **argv, int *out_count)
{
	int	*buffer;
	int	i;
	int	j;

	*out_count = count_tokens(argc, argv);
	if (*out_count == 0)
		return (NULL);
	buffer = malloc(sizeof(int) * (*out_count));
	if (buffer == NULL)
		return (NULL);
	i = 1;
	j = 0;
	while (i < argc)
	{
		if (is_flag(argv[i]) == 0)
		{
			if (fill(argv[i], buffer, &j) == 0)
				return (free(buffer), NULL);
		}
		i++;
	}
	if (has_duplicates(buffer, *out_count))
		return (free(buffer), NULL);
	return (buffer);
}

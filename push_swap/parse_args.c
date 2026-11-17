/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 14:56:35 by balca             #+#    #+#             */
/*   Updated: 2026/11/17 16:42:08 by balca            ###   ########.fr       */
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

void	count_tokens()
{
	
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
	i = 0;
	j = 0;
	while (++i < argc)
	{
		if (is_flag(argv[i]))
			continue ;
		value = ft_atoi_ps(argv[i]);
		if (!is_number(argv[i]) || (int)value != value)
			return (free(buffer), NULL);
		buffer[j++] = (int)value;
	}
	if (has_duplicates(buffer, *out_count))
		return (free(buffer), NULL);
	return (buffer);
}

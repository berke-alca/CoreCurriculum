/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 09:20:52 by balca             #+#    #+#             */
/*   Updated: 2026/10/19 13:01:50 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_make_word(char const *s, size_t start, size_t len)
{
	char	*word;
	size_t	i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free_split(char **split, size_t words)
{
	while (words > 0)
	{
		words--;
		free(split[words]);
	}
	free(split);
}

static int	ft_add_word(char **split, char const *s, char c, size_t *pos)
{
	size_t	start;
	size_t	i;

	i = *pos;
	while (s[i] == c)
		i++;
	start = i;
	while (s[i] && s[i] != c)
		i++;
	*pos = i;
	if (i == start)
		return (0);
	split[0] = ft_make_word(s, start, i - start);
	if (!split[0])
		return (-1);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	word;
	int		status;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	word = 0;
	while (s[i])
	{
		status = ft_add_word(&split[word], s, c, &i);
	if (status == -1)
	{
		ft_free_split(split, word);
		return (NULL);
	}
		if (status == 1)
			word++;
	}
	split[word] = NULL;
	return (split);
}
// int	main()
// {
// 	char	**result;
// 	int		i;

// 	result = ft_split("berke,alca,42", ',');
// 	i = 0;
// 	while (result[i] != NULL)
// 	{
// 		printf("%s\n", result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return (0);
// 	//cc ft_split.c ft_substr.c ft_strlen.c ft_strdup.c -o test
// }
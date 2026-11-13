/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: b3 <b3@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:47:01 by b3                #+#    #+#             */
/*   Updated: 2026/10/26 10:47:06 by b3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *text)
{
	size_t	counter;

	if (!text) //weil stash erste mal null ist
		return (0); 
	counter = 0;
	while (text[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*new_str;
	size_t	laength_str1;
	size_t	i;

	i = 0;
	laength_str1 = ft_strlen(s1);
	new_str = malloc(laength_str1 + ft_strlen(s2) + 1);
	if (!new_str)
	{
		free(s1);
		return (NULL);
	}
	while (laength_str1 > i)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[i - laength_str1] != '\0')
	{
		new_str[i] = s2[i - laength_str1];
		i++;
	}
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

char *extract_line(char *stash)
{
    char	*line;
	size_t	i;
	size_t	counter;

    i = 0;
    counter = 0;
	if (!stash[0])
		return (NULL);
    while (stash[i] != '\0' && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    line = malloc(i + 1);
    if (!line)
        return (NULL);
    while(counter < i)
    {
        line[counter] = stash[counter];
        counter++;
    }
    line[i] = '\0';
    return (line);
}

char	*trim_stash(char *stash)
{
	char	*newline;
	char	*rest;
	size_t	i;

    i = 0;
    newline = ft_strchr(stash, '\n');   //pointer auf das erste \n in stash
    if (newline == NULL || newline[i + 1] == '\0')
    {
        free (stash);
        return (NULL);
    }
    rest = malloc(ft_strlen(newline) + 1);
    if (!rest)
    {
        free (stash);
        return (NULL);
    }
    while(newline[i] != '\0')
    {
        rest[i] = newline[i + 1];
        i++;
    }
    rest[i] = '\0';
    free (stash);
    return (rest);
}
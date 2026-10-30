/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: b3 <b3@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:59:07 by b3                #+#    #+#             */
/*   Updated: 2026/10/26 15:55:53 by b3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && !ft_strchr(stash, '\n'))
	{
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes == -1)
        {
            free (buffer);
            free (stash);
            return (NULL);
        }
        buffer[bytes] = '\0';
        stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char *get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);   // liest bis erste slash n, kann aebr auch merhere dann sein wegen buffer size oder sogar zuende
	if (!stash)
		return (NULL);
	line = extract_line(stash);         // kopiert die erste Zeile aus stash bis genau zum ersten slash n
	stash = trim_stash(stash);          // stash = nur noch der Rest nach \n
    return (line);
}



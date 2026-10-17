/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:37:26 by balca             #+#    #+#             */
/*   Updated: 2026/10/17 14:18:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	laenghts1;
	size_t	terminator;
	size_t	counter;
	char	*newptr;

	terminator = 0;
	laenghts1 = 0;
	counter = 0;
	while (s1[laenghts1] != '\0')
	{
		laenghts1++;
		terminator++;
	}
	newptr = malloc(laenghts1 + 1);
	if (!newptr)
		return (NULL);
	while (laenghts1 > 0)
	{
		newptr[counter] = s1[counter];
		counter++;
		laenghts1--;
	}
	newptr[terminator] = '\0';
	return (newptr);
}

// int main()
// {
//     char *name = "berke";
//     char *cpy = ft_strdup(name);
//     printf("%s", cpy);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:18:39 by marvin            #+#    #+#             */
/*   Updated: 2026/10/14 12:18:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//header veränder !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <unistd.h>
#include <stdlib.h>

char *ft_strdup(const char *s1)
{
    int laenghts1;
    int terminator;
    int counter; 
    char *newptr;

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

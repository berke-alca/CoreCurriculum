/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:37:35 by marvin            #+#    #+#             */
/*   Updated: 2026/10/14 10:37:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//header veränder !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <unistd.h>
#include <stdlib.h>

void *ft_calloc(size_t count, size_t size)
{
    size_t  howmanybytes;
    void    *ptr;

    if (count == 0 || size == 0)
        return (malloc(1));
    if (count > __SIZE_MAX__ / size)
        return (NULL);
    howmanybytes = count * size;
    ptr = malloc(howmanybytes);
    if (ptr == NULL)
        return (NULL);
    ft_memset(ptr, 0, howmanybytes);
    return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:34:17 by balca             #+#    #+#             */
/*   Updated: 2026/10/17 14:17:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len);

void	*ft_calloc(size_t count, size_t size)
{
	size_t	howmanybytes;
	void	*ptr;

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
// int main()
// {
//     int *ptr = ft_calloc(10, 4);
//     int i = 0;
//     while(i != 10)
//     {
//         printf("%d", ptr[i]);
// 		i++;
//     }
// }
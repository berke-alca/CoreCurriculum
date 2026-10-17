/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:10:45 by balca             #+#    #+#             */
/*   Updated: 2026/10/17 14:39:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	laengthsrc;
	size_t	i;
	size_t	counter;

	laengthsrc = 0;
	i = 0;
	counter = 0;
	while (src[counter] != '\0')
	{
		laengthsrc++;
		counter++;
	}
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (laengthsrc);
}

// int main ()
// {
// 	char empty[10];
// 	char src[] = "berke";
// 	ft_strlcpy(empty, src, 10);
// 	printf("%s", empty);
// }
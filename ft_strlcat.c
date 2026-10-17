/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:40:15 by balca             #+#    #+#             */
/*   Updated: 2026/10/17 14:39:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlaength;
	size_t	srclaength;
	size_t	i;
	size_t	space;

	i = 0;
	srclaength = 0;
	dstlaength = 0;
	while (dstlaength < size && dst[dstlaength] != '\0')
		dstlaength++;
	while (src[srclaength] != '\0')
		srclaength++;
	if (dstlaength >= size)
		return (size + srclaength);
	space = size - dstlaength - 1;
	while (src[i] != '\0' && i < space)
	{
		dst[dstlaength + i] = src[i];
		i++;
	}
	dst[dstlaength + i] = '\0';
	return (dstlaength + srclaength);
}

// int main()
// {
// 	char name[7] = "berke";
// 	char nachname[] = "alca";

// 	printf("%s\n", name);
// 	ft_strlcat(name, nachname, 7);
// 	printf("%s\n", name);
// }
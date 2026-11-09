/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 13:38:18 by balca             #+#    #+#             */
/*   Updated: 2026/10/19 13:05:36 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptrdest;
	const unsigned char	*ptrsrc;
	size_t				index;

	if (!dest && !src)
		return (dest);
	ptrdest = dest;
	ptrsrc = src;
	index = 0;
	while (index < n)
	{
		ptrdest[index] = ptrsrc[index];
		index++;
	}
	return (dest);
}
// int main()
// {
// 	char text[] = "ich bin berke";
// 	char copyed[] = "";
// 	ft_memcpy(copyed, text, 14);
// 	printf("%s", copyed);
// }
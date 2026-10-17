/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 13:38:18 by balca             #+#    #+#             */
/*   Updated: 2026/10/15 17:05:30 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptrdest;
	const unsigned char	*ptrsrc;
	size_t				counter;

	counter = 0;
	ptrdest = dest;
	ptrsrc = src;
	while (n > 0)
	{
		ptrdest[counter] = ptrsrc[counter];
		counter++;
		n--;
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
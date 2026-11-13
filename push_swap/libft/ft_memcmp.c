/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:52:26 by balca             #+#    #+#             */
/*   Updated: 2026/10/15 17:22:37 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptrs1;
	const unsigned char	*ptrs2;
	size_t				counter;

	ptrs1 = s1;
	ptrs2 = s2;
	counter = 0;
	while (n > 0)
	{
		if (ptrs1[counter] != ptrs2[counter])
		{
			return (ptrs1[counter] - ptrs2[counter]);
		}
		counter++;
		n--;
	}
	return (0);
}
// int main()
// {
// 	char text[] = "brrke";
// 	char text2[] = "berke";
// 	int erg = ft_memcmp(text, text2, 5);
// 	printf("%d", erg);
// }
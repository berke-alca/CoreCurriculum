/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 10:24:05 by balca             #+#    #+#             */
/*   Updated: 2026/10/15 14:38:26 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *start, int byte_value, size_t max_bytes)
{
	const unsigned char	*ptr;
	size_t				counter;

	ptr = start;
	counter = 0;
	while (max_bytes > 0)
	{
		if (ptr[counter] == (unsigned char)byte_value)
		{
			return ((void *)&ptr[counter]);
		}
		counter++;
		max_bytes--;
	}
	return (NULL);
}

// int main()
// {
// 	char name[] = "berke";
// 	char *back;
// 	back = ft_memchr(name, 'r', 5);
// 	printf("%s", back);
// }
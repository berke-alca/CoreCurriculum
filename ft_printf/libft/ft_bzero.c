/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 13:18:18 by balca             #+#    #+#             */
/*   Updated: 2026/10/15 17:35:21 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*newptr;
	size_t			counter;

	counter = 0;
	newptr = ptr;
	while (n > 0)
	{
		newptr[counter] = 0;
		counter++;
		n--;
	}
}
// int main()
// {
// 	char	text[] = "berke";
// 	ft_bzero(text, 2);
// 	printf("%d %d %d %d %d\n",
// 		text[0], text[1], text[2], text[3], text[4]);
// }

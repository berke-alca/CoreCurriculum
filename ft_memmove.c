/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 10:23:05 by balca             #+#    #+#             */
/*   Updated: 2026/10/19 13:01:51 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*new_dest;
	const unsigned char	*new_src;

	new_dest = dest;
	new_src = src;
	if (!dest && !src)
		return (dest);
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			new_dest[n] = new_src[n];
		}
	}
	else
	{
		while (n > 0)
		{
			*new_dest++ = *new_src++;
			n--;
		}
	}
	return (dest);
}

// int main()
// {
// 	char text[] = "berke";
// 	char copy[6];
// 	ft_memmove(copy, text, 6);
// 	printf("%s", copy);
// }
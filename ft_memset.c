/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 09:11:54 by balca             #+#    #+#             */
/*   Updated: 2026/10/09 09:11:54 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *str, int value, size_t sizeOfBytes)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = str;
	while (sizeOfBytes > 0)
	{
		ptr[i] = (unsigned char)value;
		i++;
		sizeOfBytes--;
	}
	return (str);
}
// int main()
// {
// 	char text[] = "my Name is berke";
// 	int i = 0;
// 	char *newText = ft_memset(text, 'B', 2);
// 	while(newText[i] != '\0') 
// 	{
// 		printf("%c", newText[i]);
// 		i++;
// 	}
// }
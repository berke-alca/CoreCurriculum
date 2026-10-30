/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 09:11:54 by balca             #+#    #+#             */
/*   Updated: 2026/10/09 09:11:54 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *str, int value, size_t size_of_bytes)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = str;
	while (size_of_bytes > 0)
	{
		ptr[i] = (unsigned char)value;
		i++;
		size_of_bytes--;
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
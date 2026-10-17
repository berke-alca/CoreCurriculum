/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:39:10 by balca             #+#    #+#             */
/*   Updated: 2026/10/15 16:06:22 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	if (n == 0)
	{
		return (0);
	}
	while (n > 0)
	{
		if ((unsigned char)s1[counter] != (unsigned char)s2[counter])
		{
			return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
		}
		if (s1[counter] == '\0')
		{
			return (0);
		}
		counter++;
		n--;
	}
	return (0);
}
// int main()
// {
// 	char txt1[] = "berke1";
// 	char txt2[] = "berke2";
// 	int value = ft_strncmp(txt1, txt2 , 6);
// 	printf("%d", value);
// }
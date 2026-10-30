/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:01:54 by balca             #+#    #+#             */
/*   Updated: 2026/10/20 12:46:37 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		f(counter, &s[counter]);
		counter++;
	}
	s[counter] = '\0';
}
// void    funktion(unsigned int i, char *s)
// {
//     *s = s + 10;
// }
// int main()
// {
//     char name[] = "berke";
//     ft_striteri(name, funktion);
//     printf("%s\n", name);
// 	return (0);
// }
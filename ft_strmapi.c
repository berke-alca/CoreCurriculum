/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: b3 <b3@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:35:32 by balca             #+#    #+#             */
/*   Updated: 2026/10/19 18:59:23 by b3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char    *new_arr;
    unsigned int counter;

    counter = 0;
    new_arr = malloc(ft_strlen(s) + 1);
    if (!new_arr)
        return (0);
    while (s[counter] != '\0')
    {
        new_arr[counter] = f(counter, s[counter]);
        counter++;
    }
    new_arr[counter] = '\0';
    return (new_arr);
}
// char testing(unsigned int i, char c)
// {
//     return (c);
// }
// int main()
// {
//     char *new;
//     new = ft_strmapi("berke", testing);
//     printf("%s\n", new);
    
    
// }
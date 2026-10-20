/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 10:18:21 by balca             #+#    #+#             */
/*   Updated: 2026/10/20 12:44:51 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*new_str;
	int		counter;

	counter = 0;
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	new_str = malloc(end - start + 1);
	if (!new_str)
	{
		while (start <= end)
		{
			new_str[counter] = s1[start];
			start++;
			counter++;
		}
	}
	new_str[counter] = '\0';
	return (new_str);
}
// int main()
// {

// }
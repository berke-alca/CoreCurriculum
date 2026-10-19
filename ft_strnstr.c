/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:14:16 by balca             #+#    #+#             */
/*   Updated: 2026/10/15 15:49:03 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;
	size_t	needlelength;

	needlelength = 0;
	n = 0;
	h = 0;
	while (needle[needlelength] != '\0')
		needlelength++;
	if (needlelength == 0)
		return ((char *)haystack);
	while (h < len && haystack[h] != '\0')
	{
		n = 0;
		while (n < needlelength)
		{
			if (h + n >= len || haystack[h + n] != needle[n])
				break ;
			n++;
		}
		if (n == needlelength)
			return ((char *)&haystack[h]);
		h++;
	}
	return (0);
}

// int main()
// {
// 	char name[] = "berke";
// 	char *pname = ft_strnstr(name, "erke" , 6);
// 	printf("%s", pname);	
// }
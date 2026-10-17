/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 09:10:01 by balca             #+#    #+#             */
/*   Updated: 2026/10/09 09:10:01 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *text)
{
	size_t	counter;

	counter = 0;
	while (text[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

// int main()
// {
// 	int laength = ft_strlen("berke");
// 	printf("%d", laength);
// }
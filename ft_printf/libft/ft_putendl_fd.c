/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:40:04 by balca             #+#    #+#             */
/*   Updated: 2026/10/20 12:55:54 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	laenght;

	laenght = ft_strlen(s);
	write(fd, s, laenght);
	write(fd, "\n", 1);
}

// int	main()
// {
// 	ft_putendl_fd("berke", 1);
// }
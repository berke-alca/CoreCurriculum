/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: b3 <b3@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:26:18 by b3                #+#    #+#             */
/*   Updated: 2026/10/19 19:31:58 by b3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void ft_putstr_fd(char *s, int fd)
{
    int laenght;

    laenght = ft_strlen(s);
    write(fd, s, laenght);
}

int main()
{
    ft_putstr_fd("berke", 1);
}
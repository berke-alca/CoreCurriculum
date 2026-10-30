/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:02:29 by balca             #+#    #+#             */
/*   Updated: 2026/10/22 13:11:40 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*safe_next;

	safe_next = (*lst);
	while (safe_next != NULL)
	{
		safe_next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = safe_next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:02:29 by balca             #+#    #+#             */
/*   Updated: 2026/10/24 13:57:17 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*safe_next;

	if (!lst || !*lst || !del)
		return ;
	while (*lst != NULL)
	{
		safe_next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = safe_next;
	}
	*lst = NULL;
}

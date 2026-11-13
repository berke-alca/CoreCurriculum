/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:59:38 by balca             #+#    #+#             */
/*   Updated: 2026/10/20 16:58:23 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}
// int main()
// {
// 	t_list	*first_node;
// 	t_list	*second_node;

// 	first_node = ft_lstnew("first content ever wow\n");
// 	second_node = ft_lstnew("new");
// 	first_node->next = second_node;
// 	printf("%s", (char *)first_node->content);
// 	printf("%p", first_node->next);
// }
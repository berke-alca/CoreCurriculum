/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:58:57 by balca             #+#    #+#             */
/*   Updated: 2026/10/24 13:41:57 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
// int main(void)
// {
//     t_list first_node;
//     t_list replace_the_node_start;
//     t_list *head;

//     first_node.content = "A";
//     first_node.next = NULL;
//     replace_the_node_start.content = "X";
//     replace_the_node_start.next = NULL;

//     head = &first_node;
//     ft_lstadd_front(&head, &replace_the_node_start);
//     printf("%s\n", (char *)head->content);
// 	printf("%s\n", (char *)first_node.content);
// }
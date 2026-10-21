/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:58:57 by balca             #+#    #+#             */
/*   Updated: 2026/10/20 17:10:49 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new; //der pointer der auf a zeigt also den start zeigt nun auf new, neuer startt
//lst = addresse vom head, *lst = inhalt vom head = adresse ersten nodes
}
#include <stdio.h>

int main(void)
{
    t_list first_node;
    t_list replace_the_node_start;
    t_list *head;

    first_node.content = "A";
    first_node.next = NULL;
    replace_the_node_start.content = "X";
    replace_the_node_start.next = NULL;

    head = &first_node;
    ft_lstadd_front(&head, &replace_the_node_start);
    printf("%s\n", (char *)head->content);
	printf("%s\n", (char *)replace_the_node_start.content);
	printf("%s\n", (char *)first_node.content);
 
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 13:53:02 by marvin            #+#    #+#             */
/*   Updated: 2026/10/21 13:53:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *node_atm;

    node_atm = *lst;
    if (*lst == NULL) //liste ist leer dann new der erste
    {
        *lst = new;
        return;
    }
    while (node_atm->next != NULL)//geh bis letze kntoen
    {
        node_atm = node_atm->next;
    }
    if (node_atm->next == NULL)
        node_atm->next = new;
}
int main()
{
	t_list	a;
	t_list	b;
	t_list	*head;

	a.content = "A";
	a.next = NULL;
	b.content = "B";
	b.next = NULL;
	head = &a;
	ft_lstadd_back(&head, &b);
	printf("%s\n", (char *)a.next->content);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 13:31:43 by balca            #+#    #+#             */
/*   Updated: 2026/10/22 11:51:06 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst != NULL)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}
// int main()
// {
//     t_list A;
//     t_list B;
//     t_list C;
//     t_list *head;

//     A.content = "A";
//     B.content = "B";
//     C.content = "C";
//     A.next = &B;
//     B.next = &C;
//     C.next = NULL;
//     head = &A;
//     ft_lstsize(&A);
// 	//printf vor return counter rein zum einfach testen
// }
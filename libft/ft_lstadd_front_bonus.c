/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:24:48 by izperez           #+#    #+#             */
/*   Updated: 2023/10/03 09:35:45 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
	changes the pointer t_list to new.
 */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
		{
			new->next = *lst;
		}
		*lst = new;
	}
}

/* int	main(void)
{
	t_list	**list;
	t_list	*node;

	node = 0;
	list = &node;
	*list = ft_lstnew("hola caracola");
	ft_lstadd_front(list, ft_lstnew("juantxo pancho"));
	node = *list;
	while (node)
	{
		printf("%s\n", (char *) node->content);
		node = node->next;
	}
	return (0);
} */

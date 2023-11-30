/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:14:02 by izperez           #+#    #+#             */
/*   Updated: 2023/10/06 14:24:37 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

/* void	delnode(void *content)
{
	*(char *)content = 0;
}

int	main(void)
{
	t_list	**list;
	t_list	*node;
	t_list	*deleted;
	char	txt[] = "holi";

	node = 0;
	list = &(node);
	ft_lstadd_front(list, ft_lstnew(txt));
	ft_lstadd_front(list, ft_lstnew("cachi"));
	deleted = (*list)->next;
	ft_lstdelone(deleted, delnode);
	node = *list;
	while (node)
	{
		printf("%s\n", node->content);
		node = node->next;
	}
	return (0);
} */
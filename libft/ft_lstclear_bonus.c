/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:49:57 by izperez           #+#    #+#             */
/*   Updated: 2023/10/06 18:45:16 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	while (*lst)
	{
		node = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = node;
	}
}

/* int	main(void)
{
	t_list	**lst;
	t_list	*node;

	node = 0;
	lst = &(node);
} */
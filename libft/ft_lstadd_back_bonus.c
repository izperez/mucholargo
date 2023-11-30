/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:43:24 by izperez           #+#    #+#             */
/*   Updated: 2023/10/03 12:13:28 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (lst)
	{
		if (*lst)
		{
			node = ft_lstlast(*lst);
			node->next = new;
		}
		else
			*lst = new;
	}
}

/* int	main(void)
{
	t_list	**list;
	t_list	*node;

	node = 0;
	list = malloc (sizeof(t_list *));
	*list = node;
	ft_lstadd_back(list, ft_lstnew("Hola"));
	ft_lstadd_back(list, ft_lstnew("Caracola"));
	ft_lstadd_back(list, ft_lstnew("klk"));
	printf("%s", ft_lstlast(*list)->content);
	return (0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:28:12 by izperez           #+#    #+#             */
/*   Updated: 2023/10/06 19:01:02 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static char	ft_count(unsigned int i, char *s)
{
	return (*s + i);
} */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;
	void	*content;

	if (!lst)
		return (0);
	node = 0;
	new_lst = 0;
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}

/* int	main(void)
{
	t_list	**lst;
	t_list	*node;

	node = "Hola Caracola";
	lst = &(node);
	ft_lstmap(lst, )
} */
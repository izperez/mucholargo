/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:45:14 by izperez           #+#    #+#             */
/*   Updated: 2023/10/03 10:59:46 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst)
	{
		while (lst)
		{
			lst = lst->next;
			i++;
		}
	}
	return (i);
}

/* int	main(void)
{
	t_list	**list;
	t_list	*node;

	node = 0;
	list = &(node);
	ft_lstadd_front(list, ft_lstnew("Hola"));
	ft_lstadd_front(list, ft_lstnew("Caracola"));
	ft_lstadd_front(list, ft_lstnew("klk"));
	printf("%d", ft_lstsize(node));
	return (0);
} */

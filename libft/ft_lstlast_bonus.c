/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:48:00 by izperez           #+#    #+#             */
/*   Updated: 2023/10/05 12:12:25 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
		}
		return (lst);
	}
	return (lst);
}

/* int	main(void)
{
	t_list	**list;
	t_list	*knot;

	knot = 0;
	list = &(knot);
	ft_lstadd_front(list, ft_lstnew("Hola"));
	ft_lstadd_front(list, ft_lstnew(" que "));
	ft_lstadd_front(list, ft_lstnew("tal?"));
	printf("%s", (char *)ft_lstlast(knot)->content);
	return (0);
}	 */
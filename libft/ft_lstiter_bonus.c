/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:14:41 by izperez           #+#    #+#             */
/*   Updated: 2023/10/06 18:53:35 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static char	ft_count(unsigned int i, char *s)
{
	return (*s + i);
} */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* int	main(void)
{
	t_list	**lst;
	t_list	*node;

	node = "Hola Caracola";
	lst = &(node);
	ft_lstiter(lst, ft_count);
	printf("%s", node);
} */

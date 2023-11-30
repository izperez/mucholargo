/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:10:07 by izperez           #+#    #+#             */
/*   Updated: 2023/10/05 15:43:17 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*knot;

	knot = malloc(sizeof (*knot));
	if (!knot)
		return (0);
	knot->content = content;
	knot->next = 0;
	return (knot);
}

/* int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew("Hola");
	printf("%s", lst->content);
}
 */
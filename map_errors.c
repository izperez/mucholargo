/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:45:24 by izperez           #+#    #+#             */
/*   Updated: 2023/12/18 13:06:09 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*  prints the correspondant error */
void	ft_print_error(int type)
{
	if (type == 1)
		ft_printf ("Error\n Invalid char found");
	else if (type == 2)
		ft_printf ("Error\n Just 1 player");
	else if (type == 3)
		ft_printf ("Error\n Just 1 exit");
	else if (type == 4)
		ft_printf ("Error\n Minimum 1 collectable");
	else if (type == 5)
		ft_printf ("Error\n Map is not around walls");
	else if (type == 6)
		ft_printf ("Error\n Is not expandible");
}

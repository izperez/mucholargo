/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:16:57 by izperez           #+#    #+#             */
/*   Updated: 2024/01/14 09:39:53 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define ERROR "\033[1;31m [Error]\n"

/*  prints the correspondant error */
void	ft_print_error(int type)
{
	if (type == 1)
		ft_printf (ERROR "\033[30m Map extension is not .ber");
	else if (type == 2)
		ft_printf (ERROR "\033[30m Map is not surrounded by walls");
	else if (type == 3)
		ft_printf (ERROR "\033[30m Invalid char found");
	else if (type == 4)
		ft_printf (ERROR "\033[30m Either player, exit or collectable issue");
	else if (type == 5)
		ft_printf ("**Error**\n ");
	else if (type == 6)
		ft_printf ("Error\n ");
}

//horizontal walls check, checks the first and last line
int	ft_horizontal_walls(t_game *map)
{
	int	i;

	i = 0;
	while (map->width > i)
	{
		if (map->matrix[0][i] != '1' && map->matrix[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

//vertical walls check, checks the first and last column
int	ft_vertical_walls(t_game *map)
{
	int	i;

	i = 0;
	while (map->height > i)
	{
		if (map->matrix[i][0] != '1' && map->matrix[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:16:57 by izperez           #+#    #+#             */
/*   Updated: 2024/01/22 13:07:07 by izperez          ###   ########.fr       */
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
		ft_printf ("\033[30m CONGRATULATIONS!!!");
	else if (type == 6)
		ft_printf ("\033[30m Map is not rectangular");
}

//horizontal walls check, checks the first and last line
int	ft_horizontal_walls(t_game *map)
{
	int	i;
	int	j;

	i = map->width;
	j = 0;
	while (j > i)
	{
		if (map->matrix[0][i] == '1' && map->matrix[map->height - 1][j] == '1')
			return (0);
		j++;
	}
	return (1);
}

//vertical walls check, checks the first and last column
int	ft_vertical_walls(t_game *map)
{
	int	height;
	int	width;

	height = 0;
	width = map->width;
	while (map->height > height)
	{
		if (map->matrix[height][0] == '1' && \
			map->matrix[height][map->width] == '1')
			return (0);
		height++;
	}
	return (1);
}

int	ft_checking(t_game *map, int i, int j)
{
	int	check;

	if (map->matrix[j][i] == '1')
		return (0);
	check = right_move(map, i, j);
	if (check == 0)
		return (0);
	return (1);
}

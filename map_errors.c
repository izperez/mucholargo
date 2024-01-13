/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:45:24 by izperez           #+#    #+#             */
/*   Updated: 2024/01/13 09:23:17 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//si el programa no ha terminado después de checkear si hay un carácter válido,
//vuelve a llamar a la matriz para contar los respectivos chars que queremos.
static void	count_checker(t_game map, int width, int height)
{
	if (map.matrix != 'P' || map.matrix != 'E' || map.matrix != 'C' \
		|| map.matrix != '1' || map.matrix != '0')
	{
		ft_print_error(3);
		map.matrix[height][width];
		//ft_exit();
	}
	if (map.matrix[height][width] == 'P')
		map.player_count++;
	else if (map.matrix[height][width] == 'E')
		map.exit_count++;
	else if (map.matrix[height][width] == 'C')
		map.collect_count++;
}

//checks if there is a valid char
//1 player = 1, 1 exit = 1, <= 1 collectable
static void	character_valid(t_game map)
{
	int	height;
	int	width;

	height = 0;
	while (height < map.height - 1)
	{
		width = 0;
		while (width <= map.width)
		{
			count_checker(map, height, width);
			width++;
		}
		height++;
	}
	if (!(map.player_count == 1 && map.exit_count == 1 \
		&& map.collect_count >= 1))
	{
		ft_print_error(4);
		//ft_exit();
	}
}

//checks if the map is surrounded by walls
//if not, prints error
int	if_is_around_walls(t_game map)
{
	int	horizontal_walls;
	int	vertical_walls;

	horizontal_walls = ft_horizontal_walls(map);
	vertical_walls = ft_vertical_walls(map);
	if (horizontal_walls && vertical_walls)
		return (1);
	else
	{
		ft_print_error(2);
		//ft_exit();
	}
}

int	check_errors(t_game map)
{
	if_is_around_walls(map);
	check_valid_chars(map);
}

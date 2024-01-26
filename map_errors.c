/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:45:24 by izperez           #+#    #+#             */
/*   Updated: 2024/01/26 13:11:54 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_is_rectangular(t_game *map)
{
	int	first_row;
	int	i;
	int	cmp_row;

	i = 0;
	first_row = ft_strlen(map->matrix[0]);
	while (i < map->height)
	{
		cmp_row = ft_strlen(map->matrix[i]);
		if (first_row != cmp_row)
		{
			ft_print_error(6);
			ft_exit(map);
		}
		i++;
	}
}

//checks if there is a valid char
//1 player = 1, 1 exit = 1, <= 1 collectable
static void	character_valid(t_game *map)
{
	int	height;
	int	width;

	height = 0;
	while (height < map->height)
	{
		width = 0;
		while (width < map->width)
		{
			count_checker(map, height, width);
			width++;
		}
		height++;
	}
	if ((map->player_count != 1 || map->exit_count != 1 \
		|| map->collect_count < 1))
	{
		ft_print_error(4);
		ft_exit(map);
	}
}

//checks if the map is surrounded by walls
//if not, prints error
static void	if_is_around_walls(t_game *map)
{
	int	horizontal_walls;
	int	vertical_walls;

	vertical_walls = ft_vertical_walls(map);
	horizontal_walls = ft_horizontal_walls(map);
	if (horizontal_walls == 0 || vertical_walls == 0)
	{
		ft_print_error(2);
		ft_exit(map);
	}
}

void	check_errors(t_game *map)
{
	ft_is_rectangular(map);
	if_is_around_walls(map);
	character_valid(map);
	flood_fill(map);
}

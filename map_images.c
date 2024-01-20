/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:01:23 by izperez           #+#    #+#             */
/*   Updated: 2024/01/20 09:46:26 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//put images xmp in the window
void	ft_put_images(t_game *map)
{
	int	i;
	int	j;

	map->floor = mlx_xpm_file_to_image(map->win_ptr, \
					"game_images/floor.xpm", &i, &j);
	map->wall = mlx_xpm_file_to_image(map->win_ptr, \
					"game_images/wall.xmp", &i, &j);
	map->exit = mlx_xpm_file_to_image(map->win_ptr, \
					"games_images/exit.xmp", &i, &j);
	map->collectables = mlx_xpm_file_to_image(map->win_ptr, \
					"game_images/item.xmp", &i, &j);
	map->player = mlx_xpm_file_to_image(map->win_ptr, \
					"game_images/player.xmp", &i, &j);
}

/* 
 *	1. place player in the window
 *	2. save pos.height of the player in the struct
 *	3. save pos.width of the player in the struct
 */
static void	place_player(t_game *map, int height, int width)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->player, \
							width * WINDOW_WIDTH, height * WINDOW_HEIGHT);
	map->x = height;
	map->y = width;
}

/* 
 *	1. place collectables in the window
 *	2. increments the cont collectables in the struct
 */
static void	place_collectables(t_game *map, int height, int width)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->collectables, \
							width * WINDOW_WIDTH, height * WINDOW_HEIGHT);
	map->collectables++;
}

static void	ft_add_images_aux(t_game *map, int height, int width)
{
	if (map->matrix[height][width] == '1')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->wall, width * WINDOW_WIDTH, height * WINDOW_HEIGHT);
	if (map->matrix[height][width] == '0')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->floor, width * WINDOW_WIDTH, height * WINDOW_HEIGHT);
	if (map->matrix[height][width] == 'P')
		place_player(map, height, width);
	if (map->matrix[height][width] == 'C')
		place_collectables(map, height, width);
	if (map->matrix[height][width] == 'E')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->exit, width * WINDOW_HEIGHT, height * WINDOW_HEIGHT);
}

/* place walls, floor, player, collectable and ext images into mlx_window */
void	ft_add_to_win(t_game *map)
{
	int	height;
	int	width;

	map->collectables = 0;
	height = 0;
	while (height < map->height)
	{
		width = 0;
		while (map->matrix[height][width])
		{
			ft_add_images_aux(map, height, width);
			width++;
		}
		height++;
	}
}

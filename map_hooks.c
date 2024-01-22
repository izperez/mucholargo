/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:24:29 by izperez           #+#    #+#             */
/*   Updated: 2024/01/22 12:55:43 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Moves the player into a new pos
 * If the you reach E and collectable count is 0, print a congrats msg */
	/* if (j + 1 < map->width)
	{
		if (map->matrix[i][j + 1] == '0')
		{
			map->matrix[i][j] = '0';
			map->matrix[i][j + 1] = 'P';
			return (1);
		}
		else if (map->matrix[i][j + 1] == 'E' && map->collect_count == 0)
		{
			map->matrix[i][j] = '0';
			map->matrix[i][j + 1] = 'P';
			ft_print_error(5);
			return (2);
		}
	}
	return (0); */
int	right_move(t_game *map, int i, int j)
{
	if (map->matrix[j][i] == 'E')
	{
		if (map->collectables != 0)
			return (0);
		ft_print_error(5);
		ft_exit(map);
	}
	if (map->matrix[j][i] == '0')
	{
		map->matrix[j][i] = 'P';
		map->x = i;
		map->y = j;
		map->counter++;
	}
	if (map->matrix[j][i] == 'C')
	{
		map->matrix[j][i] = 'P';
		map->x = i;
		map->y = j;
		map->collectables--;
		map->counter++;
	}
	return (1);
}

/* Moves the player up and down */
static int	key_w_s_up_down(t_game *map, int movement)
{
	int	i;
	int	j;

	i = map->x;
	j = map->y;
	if (movement == KEY_W || movement == KEY_UP)
	{
		j--;
		ft_checking(map, i, j);
		map->matrix[j + 1][i] = '0';
	}
	else if (movement == 1)
	{
		j++;
		ft_checking(map, i, j);
		map->matrix[j - 1][i] = '0';
	}
	ft_printf("Steps taken: %d", map->counter);
	ft_printf("\nCollectables left: %d", map->collectables);
	return (1);
}

/* Moves the player right and left */
static int	key_a_d_right_left(t_game *map, int movement)
{
	int	i;
	int	j;

	i = map->x;
	j = map->y;
	if (movement == 1)
	{
		j--;
		ft_checking(map, i, j);
		map->matrix[j][i + 1] = '0';
	}
	else if (movement == 2)
	{
		j++;
		ft_checking(map, i, j);
		map->matrix[j][i - 1] = '0';
	}
	ft_printf("Steps taken: %d", map->counter);
	ft_printf("\nCollectables left: %d", map->collectables);
	return (1);
}

/* works return 1 if the keys has been press */
int	ft_hook(int key, t_game *map)
{
	int	works;

	works = 0;
	if (key == KEY_ESC)
		ft_exit(map);
	if (key == KEY_W || key == KEY_UP)
		works = key_w_s_up_down(map, key);
	if (key == KEY_S || key == KEY_DOWN)
		works = key_w_s_up_down(map, key);
	if (key == KEY_D || key == KEY_RIGHT)
		works = key_a_d_right_left(map, key);
	if (key == KEY_A || key == KEY_LEFT)
		works = key_a_d_right_left(map, key);
	if (works)
		ft_add_to_win(map);
	return (1);
}

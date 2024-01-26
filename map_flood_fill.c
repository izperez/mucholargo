/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:13:06 by izperez           #+#    #+#             */
/*   Updated: 2024/01/26 12:51:33 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Save the position of the character you want 
 */
static t_pos	find_char(t_game *map, char *character)
{
	t_pos	position;
	int		x;
	int		y;

	position.x = -1;
	position.y = -1;
	x = 0;
	while (map->matrix[x] != NULL)
	{
		y = 0;
		while (map->matrix[y][x] != '\0')
		{
			if (ft_strncmp(&map->matrix[y][x], character, INT32_MAX) == 0)
			{
				position.x = x;
				position.y = y;
				return (position);
			}
			y++;
		}
		x++;
	}
	return (position);
}

static void	fill_player(t_game *map)
{
	int		player_x;
	int		player_y;
	t_pos	position;

	position = find_char(map, "P");
	player_x = position.x;
	player_y = position.y;
	ft_printf("pox: %i poy: %i\n", player_x, player_y);
}

void	flood_fill(t_game *map)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * (map->height + 1));
	while (i < map->height)
	{
		tmp[i] = ft_strdup(map->matrix[i]);
		i++;
	}
	tmp[i] = NULL;
	fill_player(map);
}

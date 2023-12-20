/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:43:59 by izperez           #+#    #+#             */
/*   Updated: 2023/12/19 13:39:25 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_movements(int x, int y, t_player *player)
{
	if (player->pos->x == '0' || player->pos->x == 'C' || player->pos->x == 'E')
	{
		player->pos->x = 'P';
		return (1);
	}
	return (0);
}

int	ft_isexpandible(char ***matrix, t_size *size)
{
	t_moves	*moves;
	int		x;
	int		y;

	while (matrix[y])
	{
		while (matrix[y][x])
		{
			if (matrix[y][x] == 'P')
			{
				moves->up = ft_movements(x - 1, y, matrix);
				moves->down = ft_movements(x + 1, y, matrix);
				moves->right = ft_movements(x, y - 1, matrix);
				moves->left = ft_movements(x, y + 1, matrix);
			}
			if (moves->up == 1 || moves->down == 1 \
				|| moves->right == 1 || moves->left == 1)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

/* 
 * check if the map can be resolved
  * el jugador tiene que poder acceder a todas los collect y a la salida
 */
int	ft_map_can_be_resolved(char **matrix, t_size *size)
{
	int		x;
	int		y;
	t_size	*size;
	int		expand_dup;
	char	**duplicated;

	expand_dup = 1;
	x = 0;
	y = 0;
	ft_duplicated(matrix, &duplicated, size);
	while (expand_dup == 1)
	{
		expand_dup = ft_isexpandible(&duplicated, size);
	}
	if (ft_compare(matrix, duplicated) == 0)
	{
		ft_free_matrix(duplicated);
	}
	ft_free_matrix(duplicated);
	return (1);
}

/* Comparar mi matriz org con el duplicado si en la pos C y E si hay una P */
int	ft_compare(char **matrix, char ***duplicated)
{
	int	x;
	int	y;

	y = 0;
	while (matrix[y] != NULL)
	{
		x = 0;
		while (matrix[y][x] != '\0')
		{
			if (matrix[y][x] == 'C' || matrix[y][x] == 'E')
			{
				if (duplicated[y][x] != 'P')
				{
					return (0);
				}
			}
			x++;
		}
		y++;
	}
	return (1);
}

/* Recorre y alloca memoria para mi duplicado */
/* Makes a copy of my matrix in duplicated */

static int	ft_duplicated(char **matrix, char ***duplicated, t_size *size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	*duplicated = (char *)malloc(sizeof (char) * size->height + 1);
	while (matrix[j] != NULL)
	{
		*duplicated[j] = ft_strdup(matrix[j]);
		j++;
	}
	*duplicated[j] = NULL;
}

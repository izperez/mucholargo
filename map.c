/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:21:13 by izperez           #+#    #+#             */
/*   Updated: 2024/01/13 09:30:24 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//checks the width of the map (without the \n)
//if is rectangular
static int	width_map(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	if (str[len - 1] == '\n')
		len--;
	return (len);
}

//allocate memory for the matrix
//add the line to the matrix
//if the matrix is not empty, free it
//returns 1 if everything is ok
static int	add_line(t_game *map, char *line)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = malloc(sizeof(char *) * (map->height + 1));
	if (tmp == NULL)
		return (0);
	tmp[map->height] = NULL;
	while (line[i] != '\0')
	{
		tmp[i] = map->matrix[i];
		i++;
	}
	tmp[i] = line;
	if (map->matrix != NULL)
		free(map->matrix);
	map->matrix = tmp;
	return (1);
}

//reads the map and stores it in a matrix
int	reading_the_map(t_game *map, char **av)
{
	char	*readmap;

	map->fd = open(av[1], O_RDONLY);
	if (map->fd == -1)
		return (0);
	while (1)
	{
		readmap = get_next_line(map->fd);
		if (!add_line(map, readmap))
			break ;
		printf ("%s\n", readmap);
	}
	close (map->fd);
	map->width = width_map(map->matrix[0]);
	return (1);
}

/* En el bucle va liberando la memoria asignada a cada fila */
int	ft_exit(t_game *map)
{
	int	line;

	line = 0;
	if (map->mlx_win)
		mlx_destroy_window(map->mlx_img, map->mlx_win);
	free (map->mlx_img);
	while (line < map->height - 1)
		free (map->matrix[line++]);
	free(map->matrix);
	exit (0);
}

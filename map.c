/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:21:13 by izperez           #+#    #+#             */
/*   Updated: 2024/01/26 11:13:31 by izperez          ###   ########.fr       */
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
static int	add_line(t_game *map, char *line, int iter)
{
	int		i;
	char	**tmp;
	size_t	len;

	i = 0;
	if (line == NULL)
		return (0);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	map->height++;
	tmp = (char **)malloc(sizeof(char *) * (iter + 1));
	if (tmp == NULL)
		return (0);
	tmp[iter] = NULL;
	while (i < iter)
	{
		tmp[i] = map->matrix[i];
		i++;
	}
	tmp[i] = line;
	tmp[i + 1] = NULL;
	map->matrix = tmp;
	return (1);
}

//reads the map and stores it in a matrix
int	reading_the_map(t_game *map, char **av)
{
	char	*readmap;
	int		i;

	i = 0;
	map->fd = open(av[1], O_RDONLY);
	if (map->fd == -1)
		return (0);
	while (1)
	{
		readmap = get_next_line(map->fd);
		if (!add_line(map, readmap, i))
			break ;
		i++;
	}
	close (map->fd);
	map->height = i;
	map->width = width_map(map->matrix[0]);
	return (1);
}

/* En el bucle va liberando la memoria asignada a cada fila */
int	ft_exit(t_game *map)
{
	int	line;

	line = 0;
	if (map->win_ptr)
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	free (map->mlx_ptr);
	while (line < map->height - 1)
		free (map->matrix[line++]);
	free(map->matrix);
	exit(0);
}

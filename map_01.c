/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:56:06 by izperez           #+#    #+#             */
/*   Updated: 2023/12/19 13:38:49 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Checks if the extension is .ber */
int	ft_isextension(char *str, char *ber)
{
	size_t	i;
	size_t	str_len;
	size_t	ber_len;

	str_len = ft_strlen(str);
	ber_len = ft_strlen(ber);
	i = 0;
	while (i < str_len && str[str_len - ber_len + 1] == ber[i])
		i++;
	if (str_len == ber_len)
		return (1);
	else
		return (0);
}

/* Reads the map */
char	**ft_read_map(char *mapname)
{
	char	*line;
	char	*tmp;
	char	*free_tmp;
	char	**map;
	int		fd;

	tmp = "";
	free_tmp = NULL;
	fd = open(ft_strjoin("./maps/", mapname), O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s\n", line);
		tmp = ft_strjoin(tmp, line);
		free (free_tmp);
	}
	map = ft_split(tmp, '\n');
	return (map);
}

/* 
 * Checks if the map is rectangular
 * takes de len of the first row and compares the following ones,
 * if they match their len is a rectangular.
 */

int	ft_isrectangular(char **map, t_size	*size)
{
	size_t	i;
	size_t	row_len;

	i = 0;
	row_len = ft_strlen(map[0]);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i] != row_len))
			return (0);
		i++;
	}
	size->width = row_len;
	size->height = i;
	return (1);
}

/* 
 * check if the map is sourrounded by walls.
 * check if the first and last row are walls.
 * check if the first and las colum of each row are walls.
 */
int	ft_around_walls(char **map)
{
	int	i;
	int	row_len;

	i = 0;
	row_len = ft_strlen(map[0]);
	while (i < row_len)
	{
		if (map[0][i] != '1' || map[row_len][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][row_len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

/* Free matrix */
void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free (matrix[i]);
		i++;
	}
	free (matrix);
}

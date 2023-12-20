/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:38:12 by izperez           #+#    #+#             */
/*   Updated: 2023/12/19 13:48:19 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* rellena la matriz */
static char	**ft_create_matrix(char *smap, t_size *size, int *collect_count)
{
	char	**matrix;

	matrix = ft_read_map(smap);
	if (ft_around_walls == 0)
	{
		ft_print_error(5);
		return (matrix);
	}
	if (ft_all_validated == 0)
	{
		ft_all_validated(matrix);
		return (matrix);
	}
	if (ft_isrectangular(smap, size))
	{
		ft_print_error(0);
		return (matrix);
	}
	if (ft_map_can_be_resolved(smap, size) == 0)
	{
		ft_print_error(6);
		return (matrix);
	}
	if (matrix == 0)
		return (NULL);
	return (matrix);
}

/* rellenar la estructura de mapa */
/* creates object map */
t_map	ft_create_map(char *smap)
{
	t_map	map;
	t_size	*size;
	char	**matrix;
	int		collect_count;

	map.created = 0;
	matrix = ft_create_matrix(smap, &size, &collect_count);
	if (matrix == NULL)
	{
		return (map);
	}
	map.matrix = matrix;
	map.size = size;
	map.collect_count = collect_count;
	map.created = 1;
	return (map);
}

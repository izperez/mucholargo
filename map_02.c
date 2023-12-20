/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:43:52 by izperez           #+#    #+#             */
/*   Updated: 2023/12/19 12:26:48 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 
 * checks the line of the matrix
 * then each position of the matrix and returns ft_valid
 */
int	ft_all_validated(char **map)
{
	int	x;
	int	y;
	int	player;
	int	exit;
	int	collect;

	player = 0;
	exit = 0;
	collect = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_c_counter(map[y][x], &player, &exit, &collect);
			x++;
		}
		y++;
	}
	ft_valid(&player, &exit, &collect);
}

/* check if there is a valid character
 * 1 player
 * 1 exit
 * minimum 1 collectable 
 * */
static int	ft_valid(int *player, int *exit, int *collect)
{
	if (player != 1)
		map_errors(2);
	else if (exit != 1)
		map_errors(3);
	else if (collect < 1)
		map_errors(4);
	if (player == 1 && exit == 1 && collect > 1)
		ft_printf("Everything OK");
}

/* counts how many players, exits and collectables has */
static int	ft_c_counter(char c, int *player, int *exit, int *collect)
{
	if (ft_found_cvalid(c) == 0)
		return (0);
	if (c == 'P')
		*player += 1;
	else if (c == 'E')
		*exit += 1;
	else if (c == 'C')
		*collect += 1;
	return (1);
}

/* founds valid chars
 * if valid c not ound print correspondant error */
static int	ft_found_cvalid(char c)
{
	if (c != 'P' || c != 'E' || c != 'C' || c != '1' || c != '0')
	{
		map_errors(1);
		return (0);
	}
	return (1);
}

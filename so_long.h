/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:42:51 by izperez           #+#    #+#             */
/*   Updated: 2024/01/11 15:21:29 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define WINDOW_WIDTH	500
# define WINDOW_HEIGHT	500

//hooks
# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 0
# define KEY_D 1
# define KEY_A 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123

typedef struct s_game
{
	char		**matrix;
	int			fd;
	int			created;
	int			collect_count;
	int			player_count;
	int			exit_count;
	int			x;
	int			y;
	int			height;
	int			width;
	int			counter;

	void		*floor;
	void		*wall;
	void		*collectables;
	void		*exit;
	void		*player;

	void		*mlx_win;
	void		*mlx_img;
}				t_game;

//map.c
int		reading_the_map(t_game *map, char **av);

//map_errors.c
int		check_errors(t_game map);
int		if_is_around_walls(t_game map);

//map_errors_aux.c
void	ft_print_error(int type);
int		ft_horizontal_walls(t_game map);
int		ft_vertical_walls(t_game map);


#endif

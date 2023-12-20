/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:42:51 by izperez           #+#    #+#             */
/*   Updated: 2023/12/20 14:05:27 by izperez          ###   ########.fr       */
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

// Esto no lo necesito porque el tamaño de la ventana depende del tamaño del mapa
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

typedef struct s_moves
{
	int	up;
	int	down;
	int	right;
	int	left;
}			t_moves;

typedef struct s_size
{
	int	width;
	int	height;
}			t_size;

typedef struct s_pos
{
	int	x;
	int	y;
}			t_pos;

typedef struct s_player
{
	t_pos	*pos;
}				t_player;

typedef struct s_map
{
	char	**matrix;
	t_size	*size;
	int		created;
	int		collect_count;
}				t_map;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
}				t_window;

typedef struct s_game
{
	t_map		*map;
	t_player	*s_player;
}				t_game;

void	ft_free_matrix(char **matrix);
char	**ft_read_map(char *mapname);
int		ft_isextension(char *str, char *ber);
int		ft_isrectangular(char **map, t_size *size);
int		ft_around_walls(char **map);
int		ft_all_validated(char **map);
void	ft_print_error(int type);
t_map	ft_create_map(char *matrix);

int		ft_isexpandible(char ***matrix, t_size *size);

#endif

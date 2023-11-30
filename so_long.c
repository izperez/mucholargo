/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:42:41 by izperez           #+#    #+#             */
/*   Updated: 2023/11/30 13:31:04 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "ventnitaa");
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		y++;
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xB45BE1);
			x++;
		}
	}
	mlx_loop(mlx_ptr);
}

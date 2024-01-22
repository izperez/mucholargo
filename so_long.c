/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:42:41 by izperez           #+#    #+#             */
/*   Updated: 2024/01/22 12:29:43 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	map;

	if (ac != 2)
		return (0);
	if (!ft_strchr(av[1], '.ber'))
		ft_print_error(1);
	ft_memset(&map, 0, sizeof(t_game));
	reading_the_map(&map, av);
	check_errors(&map);
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, map.width * WINDOW_WIDTH, \
	map.height * WINDOW_HEIGHT, "solog");
	ft_put_images(&map);
	ft_put_images(&map);
	mlx_key_hook(map.win_ptr, ft_hook, &map);
	mlx_hook(map.win_ptr, 17, 0, (void *)exit, 0);
	mlx_loop(map.mlx_ptr);
}

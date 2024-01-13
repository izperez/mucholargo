/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:42:41 by izperez           #+#    #+#             */
/*   Updated: 2024/01/11 15:03:37 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	map;

	if (ac != 2)
		return (0);
	//ft_strchr para comprobar la extension
	if (!ft_strchr(av[1], '.ber'))
		ft_print_error(1);
	//ft_memset para copiar en map
	ft_memset(&map, 0, sizeof(t_game));
	//map_reading
	reading_the_map(&map, av);
	//check_errors
	//check_errors(&map);
	//mlx_init
	//mlx_new_window
	//put_images
	//add_graphics
	//mlx_key_hook
	//mlx_hook
	//mlx_loop
}

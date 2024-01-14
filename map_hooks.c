/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:24:29 by izperez           #+#    #+#             */
/*   Updated: 2023/12/21 09:56:21 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(int key)
{
	t_player	*player;

	if (key == KEY_ESC)
		ft_destroy_hook();
	else if (key == KEY_W || key == KEY_UP)
		player->pos->x += 1;
	else if (key == KEY_S || key == KEY_DOWN)
		player->pos->x -= 1;
	else if (key == KEY_A || key == KEY_LEFT)
		player->pos->y -= 1;
	else if (key == KEY_D || key == KEY_RIGHT)
		player->pos->y += 1;
}

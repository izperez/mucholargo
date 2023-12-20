/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:01:15 by izperez           #+#    #+#             */
/*   Updated: 2023/12/05 12:02:56 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//returns a void pointer: %p -> "0x"
//char: %c
void	pf_putchar(char c, int	*bytes)
{
	if (*bytes == -1)
		return ;
	if ((write(1, &c, 1)) == -1)
	{
		*bytes = -1;
		return ;
	}
	*bytes += 1;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_isnegative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:55:19 by izperez           #+#    #+#             */
/*   Updated: 2023/12/05 12:04:44 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//print a integer(base 10): %i || decimal number(base 10): %d
void	pf_isnegative(int i, char *base, int *bytes)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (i == 0)
		pf_putchar('0', bytes);
	if (i == -2147483648)
	{
		pf_putstr("-2147483648", bytes);
		return ;
	}
	if (i < 0)
	{
		pf_putchar('-', bytes);
		pf_isnegative((i * -1), base, bytes);
	}
	if (i >= 10)
	{
		pf_isnegative(i / base_len, base, bytes);
		pf_putchar(base[i % base_len], bytes);
	}
	if (i > 0 && i < 10)
		pf_putchar(base [i % base_len], bytes);
}
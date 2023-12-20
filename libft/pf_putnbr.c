/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:57:11 by izperez           #+#    #+#             */
/*   Updated: 2023/12/05 11:57:34 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//print num hex|dec
void	pf_putnbr(size_t i, char *base, int *bytes)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (i < 0)
		pf_isnegative(i, base, bytes);
	else if (i / base_len)
		pf_putnbr(i / base_len, base, bytes);
	pf_putchar(base[i % base_len], bytes);
}
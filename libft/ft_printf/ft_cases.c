/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:07:05 by izperez           #+#    #+#             */
/*   Updated: 2023/10/19 11:10:43 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

//string: %s
void	pf_putstr(char *str, int *bytes)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i] != 0)
	{
		pf_putchar(str[i], bytes);
		i++;
	}
}

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

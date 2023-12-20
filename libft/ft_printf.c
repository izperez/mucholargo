/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:53:12 by izperez           #+#    #+#             */
/*   Updated: 2023/12/05 12:04:56 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_simbol(char simb, va_list args, int *bytes)
{
	if (*bytes == -1)
		return ;
	if (simb == 'c')
		pf_putchar(va_arg(args, int), bytes);
	else if (simb == 's')
		pf_putstr(va_arg(args, char *), bytes);
	else if (simb == 'p')
	{
		pf_putstr("0x", bytes);
		pf_putnbr(va_arg(args, size_t), HEX_MIN, bytes);
	}
	else if (simb == 'd' || simb == 'i')
		pf_isnegative(va_arg(args, int), DEC, bytes);
	else if (simb == 'u')
		pf_putnbr(va_arg(args, unsigned int), DEC, bytes);
	else if (simb == 'x')
		pf_putnbr(va_arg(args, unsigned int), HEX_MIN, bytes);
	else if (simb == 'X')
		pf_putnbr(va_arg(args, unsigned int), HEX_MAY, bytes);
	else if (simb == '%')
		pf_putchar('%', bytes);
	else
		return ;
}

int	ft_printf(const char *variable, ...)
{
	va_list		args;
	int			i;
	int			bytes;

	bytes = 0;
	va_start (args, variable);
	i = 0;
	while (variable[i])
	{
		if (variable[i] == '%')
			ft_check_simbol(variable[i++ + 1], args, &bytes);
		else
			pf_putchar(variable[i], &bytes);
		i++;
	}
	va_end(args);
	return (bytes);
}

/* int	main(void)
{
	int	i;
	int	j;

	j = printf("nueva: %d\n", 4);
	i = ft_printf("nueva: %d\n", 4);
	printf("%d\n%d", j, i);
	return (0);
}
 */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:55:02 by izperez           #+#    #+#             */
/*   Updated: 2023/10/18 13:57:25 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DEC "0123456789"
# define HEX_MIN "0123456789abcdef"
# define HEX_MAY "0123456789ABCDEF"

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int			ft_printf(char const *variable, ...);
int			ft_strlen(const char *str);
void		pf_putchar(char c, int *bytes);
void		pf_putstr(char *str, int *bytes);
void		pf_putnbr(size_t i, char *base, int *bytes);
void		pf_isnegative(int i, char *base, int *bytes);

#endif
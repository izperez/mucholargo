/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:38:27 by izperez           #+#    #+#             */
/*   Updated: 2023/10/04 13:24:44 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static char	ft_count(unsigned int i, char *s)
{
	return (*s + i);
} */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (*s)
		f(i++, s++);
}

// int	main(void)
// {
// 	char	str[] = "Hola Caracolaa";

// 	ft_striteri(str, ft_count);
// 	printf("%s", str);
// }

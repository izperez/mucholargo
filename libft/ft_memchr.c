/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:37:18 by izperez           #+#    #+#             */
/*   Updated: 2023/09/19 10:31:54 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	num;

	str = (unsigned char *)s;
	num = c;
	i = 0;
	while (i < n)
	{
		if (str[i] == num)
		{
			return ((void *)(str + i));
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	str1[] = "HolaCaracola";
	char	*strR;

	strR = ft_memchr(str1, 'r', 8);
	if (strR != NULL)
	{
		printf("Encontrado: %s\n", strR);
	}
	else
	{
		printf("No encontrado\n");
	}
	return (0);
}*/

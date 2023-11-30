/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:41:48 by izperez           #+#    #+#             */
/*   Updated: 2023/10/04 14:03:34 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*source;
	char	*dest;

	source = (char *)src;
	dest = (char *)dst;
	i = 0;
	if (!dst && !src)
		return (0);
	if (dest > source)
	{
		while (len-- > 0)
		{
			dest[len] = source[len];
		}
	}
	else
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}

/* int	main(void)
{
	char	str1[20] = "123456789";
	char	str2[20] = "7777777777";

	printf("antes: %s, %s\n", str1, str2);
	ft_memmove(str2, str1, 5);
	printf("despues: %s, %s\n", str1, str2);
	return (0);
} */

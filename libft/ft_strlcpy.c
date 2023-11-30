/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:26:25 by izperez           #+#    #+#             */
/*   Updated: 2023/10/05 11:33:34 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*source;

	i = 0;
	source = (char *)src;
	if (dstsize > 0)
	{
		while (source[i] && i < dstsize - 1)
		{
			dst[i] = source[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

/* int	main(void)
{
	char	dest[50];
	char	src[] = "HOLACARACOLA";
	printf("%lu | %s", strlcpy (dest, src, 3), dest);
} */

/* 	src_length = 0;
	while (i + 1 < dstsize && src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dest[i] = 0;
	return (i); */

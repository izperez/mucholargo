/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:21:21 by izperez           #+#    #+#             */
/*   Updated: 2023/11/30 13:10:05 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	i = 0;
	if (dstsize == 0 || dstsize <= dlen)
	{
		return (slen + dstsize);
	}
	while (src[i] != 0 && i < dstsize - dlen - 1)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = 0;
	return (dlen + slen);
}

/* int	main(void)
{
	char	dst[] = "Caracola";
	char	src[] = "Hola";

	printf("Antes %s, %s\n", src, dst);
	ft_strlcat(dst, src, 12);
	printf("Despues %s, %s\n", src, dst);
	return (0);
} */

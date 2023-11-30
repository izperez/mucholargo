/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:14:35 by izperez           #+#    #+#             */
/*   Updated: 2023/10/05 12:26:35 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	i = 0;
	d = (unsigned char *) dst;
	s = (unsigned const char *) src;
	if ((dst == 0) && (src == 0))
		return (NULL);
	if ((dst == src) || n == 0)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

/* int	main(void)
{
	char	*src;
	char	*dst;
	size_t	n;

	src = "Hola";
	dst = "Adios";
	n = 3;
	printf("%s\n", src);
	printf("%s\n", ft_memcpy(dst, src, n));
	printf("%s\n", dst);
	// printf("%s\n", memcpy(dst, src, n));
	return (0);
} */

/* int	main(void)
{
	char	src[] = "test basic du memcpy !";
	char	buff1[22];
	char	buff2[22];

	memcpy(buff1, src, 22);
	printf("FUNCION ORIGINAL: %s\n", buff1);
	ft_memcpy(buff2, src, 22);
	printf("FUNCION PROPIA: %s\n", buff2);
	return (0);
} */

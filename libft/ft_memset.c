/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:01:24 by izperez           #+#    #+#             */
/*   Updated: 2023/09/19 10:34:25 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char	str[40] = "hola";

	printf("antes %s\n", str);
	ft_memset(str, 'b', 1);
	printf("despues: %s\n", str);
}*/

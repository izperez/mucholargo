/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:45:43 by izperez           #+#    #+#             */
/*   Updated: 2023/10/13 17:04:46 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t loc)
{
	size_t	i;
	size_t	j;

	if (!haystack && !needle)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != 0 && i < loc)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < loc)
		{
			if (needle[j + 1] == 0)
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	*str1 = "Hola";
	char	*str2 = "HolaCaracola";
	char	*result = ft_strnstr(str1, str2, 3);

	if (result)
		printf("Encontrado: %s", result);
	else
		printf("No encontrado");
	return (0);
} */
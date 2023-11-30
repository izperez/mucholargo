/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:06:11 by izperez           #+#    #+#             */
/*   Updated: 2023/10/06 13:27:43 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	ptr = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!ptr)
		return (0);
	while (s1[i] != 0)
	{
		ptr[i + j] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = 0;
	return (ptr);
}

/* int	main(void)
{
	char	*str1 = "Hola";
	char	*str2 = "Caracola";

	printf("%s", ft_strjoin(str1, str2));
	return (0);
} */

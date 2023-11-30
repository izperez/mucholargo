/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:01:44 by izperez           #+#    #+#             */
/*   Updated: 2023/10/06 13:25:03 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{	
	char	*sub;
	size_t	i;
	size_t	size;

	sub = 0;
	i = 0;
	if (!s)
		return (0);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	sub = (char *) ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (0);
	while (i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	return (sub);
}

/* int	main(void)
{
	//char		str1[] = "Mi string a imprimir";
	const char	*sour = ft_substr("", 0, 1);
	//ft_substr(str1, 3, 7);
	if (sour != NULL)
	{
		printf("String: %s\n", sour);
		printf("Substring: %s", sour);
	}
	return (0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:40:14 by izperez           #+#    #+#             */
/*   Updated: 2023/10/10 11:05:31 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//returns a pointer to the located character
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = (int) ft_strlen(str);
	while (i > 0)
	{
		i--;
		if (str[i] == (unsigned char)c)
		{
			return (str + i);
		}
	}
	if ((unsigned char)c == 0)
		return (str + ft_strlen(s));
	else
		return (NULL);
}

/* int	main(void)
{
	char	str[] = "holal";
	char	*strL;

	strL = ft_strrchr(str, 'l');
	printf("%s", strL);
	return (0);
} */

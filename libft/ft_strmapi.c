/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:02:14 by izperez           #+#    #+#             */
/*   Updated: 2023/10/04 13:24:50 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static char	ft_count(unsigned int i, char s)
{
	return (s + i);
} */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*str;

	i = 0;
	if (!s)
		return (0);
	str = (char *)ft_calloc((ft_strlen(s)) + 1, sizeof(char));
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}

/* int	main(void)
{
	char	str[] = "holiii caracolii";
	printf("%s", ft_strmapi(str, ft_count));
}
 */
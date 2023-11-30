/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:17:54 by izperez           #+#    #+#             */
/*   Updated: 2023/10/05 11:49:56 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Returns NULL if its not found
	REturn a pointer where it´s found
	
*/
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
		{
			return (str + i);
		}
		i++;
	}
	if ((unsigned char) c == '\0')
		return (str + i);
	else
		return (NULL);
}

/* int	main(void)
{
	char nombre[] = "izaro";
	char *strA;

	strA = ft_strchr(nombre, 'a');
	printf("%s", strA);
	return (0);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:37:38 by izperez           #+#    #+#             */
/*   Updated: 2023/09/25 10:16:28 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int		len;
	char				*str;

	len = ft_strlen(s1);
	str = (char *) malloc (sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	ft_strlcpy (str, s1, len + 1);
	return (str);
}

/* int	main(void)
{
	char	*test;
	test = ft_strdup("holaCaracola");
	return (0);
} */
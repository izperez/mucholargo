/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:50:56 by izperez           #+#    #+#             */
/*   Updated: 2023/10/06 14:23:35 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
	Returns an string without the char(set)
	removes char at the start+end.
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && start < end)
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end]) && end >= start)
		end--;
	str = malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (0);
	ft_strlcpy(str, &s1[start], (end - start + 2));
	return (str);
}

// int	main(void)
// {
// 	char *result;

// 	char s1[] = "HolaCaracola";
// 	char set[] = "Haol";
// 	//result = ft_strtrim(s1, set);
// 	result = ft_strtrim("", "");
// 	//printf("%s", s1);
// 	//printf("%s", set);
// 	printf("%s", result);
// 	return(0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:22:16 by izperez           #+#    #+#             */
/*   Updated: 2023/10/06 19:00:57 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Returns each position of the caracter you want of the arrays of arrays.
 */

int	ft_counter(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			j++;
		while (s[i] != c && s[i])
		i++;
	}
	return (j);
}

static void	freeblock(char **result)
{
	int	j;

	j = 0;
	while (result[j])
	{
		free (result[j]);
		j++;
	}
	free (result);
}

int	ft_check(const char *s, char c, char **result)
{
	int	i;
	int	j;
	int	start;
	int	end;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		if (end > start)
		{
			result[j] = ft_substr(s, start, end - start);
			if (!result[j])
				return (freeblock(result), 0);
			j++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**result;

	i = 0;
	j = 0;
	result = ft_calloc(ft_counter(s, c) + 1, sizeof(char *));
	if (!result)
		return (0);
	if (!ft_check(s, c, result))
		return (NULL);
	return (result);
}

/* int	main(void)
{
	int		i;
	char	str[] = "Hola Caracola keloke";
	char	**splits;

	i = 0;
	splits = ft_split(str, ' ');
	while (splits[i])
	{
		printf("%s\n", splits[i]);
		i++;
	}
	return (0);
} */

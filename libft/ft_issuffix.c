/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issuffix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:19:15 by izperez           #+#    #+#             */
/*   Updated: 2023/12/11 14:20:39 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	issufix(char *str, char *suff)
{
	size_t	i;
	size_t	str_len;
	size_t	suff_len;

	str_len = ft_strlen(str);
	suff_len = ft_strlen(suff);
	i = 0;
	while (i < str_len && str[str_len - suff_len + 1] == suff[i])
		i++;
	if (str_len == suff_len)
		return (1);
	else
		return (0);
}

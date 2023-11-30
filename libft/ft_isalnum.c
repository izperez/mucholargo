/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:10:29 by izperez           #+#    #+#             */
/*   Updated: 2023/09/19 10:32:49 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	printf("%d", ft_isalnum('5'));
	printf("\n%d", ft_isalnum('P'));
	printf("\n%d", ft_isalnum('p'));
	printf("\n%d", ft_isalnum(':'));
	printf("\n%d", ft_isalnum('^'));
}*/

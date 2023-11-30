/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:48:27 by izperez           #+#    #+#             */
/*   Updated: 2023/09/29 13:31:51 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		len ++;
		n = n / 10;
	}
	if (n < 0)
		len = len + 1;
	return (len);
}

void	ft_isnegative(int n, char *result)
{
	int	i;
	int	len;

	len = ft_len(n);
	result[0] = '-';
	n = n * -1;
	i = 0;
	while (n > 0)
	{
		result[len - i - 1] = n % 10 + '0';
		i++;
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		len;

	len = ft_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	result = (char *)ft_calloc((ft_len(n) + 1), sizeof(char));
	if (!result)
		return (0);
	result[ft_len(n)] = 0;
	if (n < 0)
		ft_isnegative(n, result);
	if (n >= 0)
	{
		result[0] = '0';
		while (n > 0)
		{
			result[len - i - 1] = n % 10 + '0';
			i++;
			n = n / 10;
		}
	}
	return (result);
}

/* int	main(void)
{
	int		n1 = -0;
	int		n2 = 123456789;
	char	*result1;
	char	*result2;

	result1 = ft_itoa(n1);
	result2 = ft_itoa(n2);
	printf("%s\n%s", result1, result2);
	return (0);
} */

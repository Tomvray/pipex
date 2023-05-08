/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvray <tvray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:42:07 by tvray             #+#    #+#             */
/*   Updated: 2022/10/17 15:54:30 by tvray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 10)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_fill_str(int size, int sign, char *str, unsigned int num)
{
	int	count;

	count = 1;
	while (count <= size)
	{
		str[size + sign - count] = num % 10 + '0';
		num = num / 10;
		count++;
	}
	if (sign)
		str[0] = '-';
	str[size + sign] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	int				size;
	int				sign;
	unsigned int	num;
	char			*res;

	sign = 0;
	if (n < 0)
	{
		sign = 1;
		num = -n;
	}
	else
		num = n;
	size = ft_intlen(num);
	res = malloc(sizeof(char) * (size + sign + 1));
	if (!res)
		return (NULL);
	return (ft_fill_str(size, sign, res, num));
}

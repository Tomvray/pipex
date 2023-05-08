/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvray <tvray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:41:59 by tvray             #+#    #+#             */
/*   Updated: 2022/10/17 16:36:43 by tvray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

int	ft_atoi(const char *nptr)
{
	long int	nbr;
	int			sign;

	nbr = 0;
	sign = 1;
	while (*nptr == ' ' || (9 <= *nptr && *nptr <= 13))
		nptr += 1;
	if (*nptr == '-')
	{
		sign = -1;
		nptr += 1;
	}
	else if (*nptr == '+')
		nptr += 1;
	while (*nptr <= '9' && *nptr >= '0')
	{
		if (nbr > LONG_MAX / 10 || (nbr == LONG_MAX / 10 && *nptr > '7'))
			return (-1);
		if (nbr < LONG_MIN / 10 || (nbr == LONG_MIN / 10 && *nptr > '8'))
			return (0);
		nbr = nbr * 10 + sign * (*nptr - '0');
		nptr += 1;
	}
	return (nbr);
}

/*
#include <limits.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int k, i;
	char	*str = strdup("92233727000");

	i = 0;
	while (i < 10)
	{
		if (ft_atoi(str) != atoi(str))
			printf("ouch %s\n", str);
		i++;
		printf("%s\n", str);
		str[19] += 1;
	}
	free(str);
	// printf("atoi = %i\n", atoi(str));
	// printf("ft = %i\n", ft_atoi(str));
	// printf("%ld\n", LONG_MIN);
	// printf("bool %i\n", 9223372036854775807 < 999999999999999999);
	
}
*/
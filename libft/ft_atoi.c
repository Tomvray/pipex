#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	size_t	nbr;
	int		sign;

	i = 0;
	sign = 1;
	nbr = 0;
	while (nptr[i] == ' ' || (9 <= nptr[i] && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		nbr = nbr * 10 + sign *(nptr[i] - '0');
		i++;
	}
	return (nbr);
}

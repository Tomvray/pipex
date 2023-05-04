#include "libft.h"

int	ft_intlen(unsigned int n)
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

char    *ft_itoa(int n)
{
	int				count;
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
	res = malloc(sizeof(char)* (size + sign + 1));
	if (!res)
		return (NULL);
	count = 1;
	while (count <= size)
	{
		res[size + sign - count] = num % 10 + '0';
		num = num / 10;
		count++;
	}
	if (sign)
		res[0] = '-';
	res[size + sign] = 0;
	return (res);
}
#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	size_t			len;
	char			*res;

	len = ft_strlen(s);
	
	while (i < len)
	{
		f(i, s + i);
		i++;
	}
}
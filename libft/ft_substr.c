#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t  len_s;
	size_t  i;
	char    *res;

	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_calloc(1, 1));
	if (len > len_s - start)
		len = len_s - start;
	res = malloc((len + 1) * sizeof(char));
	if (res != NULL)
	{
		i = 0;
		while(i < len)
		{
			res[i] = s[start + i];
			i++;
		}
		res[i] = 0;
	}
	return (res);
}
/*
int main()
{
	char const	s[] = "123456";
	char	*str;

	str = ft_substr(s, 10, 15);
	puts(str);
	free(str);
}
*/
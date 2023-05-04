#include "libft.h"

int	ft_char_is_in_set(char c, char const *set)
{
	size_t	len_set;
	size_t	i;

	i = 0;
	len_set = ft_strlen(set);
	while (i < len_set)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*res;

	len = ft_strlen(s1);
	while (len > 0 && ft_char_is_in_set(*s1, set))
	{
		len --;
		s1++;
	}
	while (len > 0 && ft_char_is_in_set(s1[len - 1], set))
		len --;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	ft_memmove(res, s1, len);
	res[len] = 0;
	return (res);
}

/*
int	main(void)
{
	char	*str;

	str = ft_strtrim("0123456789", "3501a9");
	printf("%s\n", str);
	free(str);
}
*/
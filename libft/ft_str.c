#include "libft.h"

size_t  ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return(i);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	size_src;
	size_t	size_dest;

	size_src = ft_strlen(src);
	if (size == 0)
		return(size_src);
	size_dest = ft_strlen(dest);
	i = 0;
	if(size < size_dest)
		return (size + size_src);
	while (i + size_dest < size - 1 && src[i] != 0)
	{
		dest[i + size_dest] = src[i];
		i++;
	}
	dest [i + size_dest] = 0;
	return (size_dest + size_src);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	len_src = ft_strlen(src);
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && *(src + i) != 0)
		{
			*(dest + i) = *(src + i);
			i++;
		}
		*(dest + i) = 0;
	}
	return (len_src);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		l1;
	int		l2;

	i = 0;
	l1 = *s1;
	l2 = *s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && l1 == l2 && l1 != 0 && l2 != 0)
	{
		i++;
		l1 = *(s1 + i);
		l2 = *(s2 + i);
	}
	if (l1 < 0)
		l1 = 256 + l1;
	if (l2 < 0)
		l2 = 256 + l2;
	return (l1 - l2);
}

char	*ft_strchr(const char *s, int c)   
{
	size_t	i;
	char	*ptr;

	ptr = (char *) s;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (ptr + i);
		i ++;
	}
	if (c == 0)
		return (ptr + i);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ptr;

	ptr = (char *) s;
	i = ft_strlen(s);
	if (c == 0)
		return (ptr + i);
	while (i > 0)
	{
		if (s[i - 1] == c)
			return (ptr + i - 1);
		i--;
	}
	return (NULL);
}

char	*ft_strnstr(const char * s1, const char * s2, size_t len)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	len2 = ft_strlen(s2);
	if (len2 == 0)
		return((char*) s1);
	if (len == 0)
		return (NULL);
	len1 = ft_strlen(s1);
	i = 0;
	if (len1 > len)
		len1 = len;
	while (i + len2 <= len1)
	{
		if (ft_strncmp(s1 + i, s2, len2) == 0)
			return ((char *) s1 + i);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	size_t	i;

	cpy = malloc(sizeof(*cpy) * (ft_strlen(s) + 1));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

#include "libft.h"

void    *ft_memset(void *s, int c, size_t n)
{
	size_t  i;
	char    *ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}

void    *ft_bzero(void   *s, size_t n)
{
	return (ft_memset(s, 0, n));
}

void    *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t  	i;
	char    	*ptr_dest;
	const char	*ptr_src;

	if (!n || dest == src)
		return (dest);
	ptr_dest = dest;
	ptr_src = src;
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			ptr_dest[i - 1] = ptr_src[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			ptr_dest[i] = ptr_src[i];
			i ++;
		}
	}
	return (dest);
}

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src == dest)
		return (dest);
	i = 0;
	while (i < n)
	{
		((char*) dest)[i] = ((char*) src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	ptr = (char *) s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == c)
		{
			return (ptr + i);
		}
		i++;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	const char	*ptr1;
	const char	*ptr2;

	i = 0;
	ptr1 = s1;
	ptr2 = s2;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return ((unsigned char) ptr1[i] - (unsigned char) ptr2[i]);
		i++;
	}
	return (0);
}

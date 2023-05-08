/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvray <tvray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:42:13 by tvray             #+#    #+#             */
/*   Updated: 2022/10/10 12:23:34 by tvray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}

void	*ft_bzero(void *s, size_t n)
{
	return (ft_memset(s, 0, n));
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;

	if (!n || dest == src)
		return (dest);
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			((char *)dest)[i - 1] = ((char *)src)[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i ++;
		}
	}
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src == dest)
		return (dest);
	i = 0;
	while (i < n)
	{
		((char *) dest)[i] = ((char *) src)[i];
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
		if ((unsigned char) ptr[i] == (unsigned char) c)
		{
			return (ptr + i);
		}
		i++;
	}
	return (NULL);
}

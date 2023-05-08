/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvray <tvray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:29:45 by tvray             #+#    #+#             */
/*   Updated: 2022/10/04 14:07:44 by tvray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	size_src;
	size_t	size_dest;

	size_src = ft_strlen(src);
	if (size == 0)
		return (size_src);
	size_dest = ft_strlen(dest);
	i = 0;
	if (size < size_dest)
		return (size + size_src);
	while (i + size_dest < size - 1 && src[i] != 0)
	{
		dest[i + size_dest] = src[i];
		i++;
	}
	dest[i + size_dest] = 0;
	return (size_dest + size_src);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
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

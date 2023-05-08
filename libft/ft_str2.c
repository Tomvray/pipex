/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvray <tvray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:28:46 by tvray             #+#    #+#             */
/*   Updated: 2022/10/04 13:49:25 by tvray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ptr;

	ptr = (char *) s;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
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
		if (s[i - 1] == (unsigned char) c)
			return (ptr + i - 1);
		i--;
	}
	return (NULL);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	len2 = ft_strlen(s2);
	if (len2 == 0)
		return ((char *) s1);
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

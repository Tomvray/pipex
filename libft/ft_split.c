/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvray <tvray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:42:44 by tvray             #+#    #+#             */
/*   Updated: 2022/10/17 16:00:32 by tvray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenword(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**free_split(char **s, size_t k)
{
	size_t	i;

	i = 0;
	while (i < k)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static char	**ft_splitcpy(char const *s, char **tab, char c, size_t len)
{
	size_t	j;
	size_t	k;

	j = 0;
	while (j < len)
	{
		k = 0;
		while (*s && *s == c)
			s++;
		tab[j] = (char *) malloc(sizeof(char) * (ft_lenword(s, c) + 1));
		if (!tab[j])
			return (free_split(tab, k - 1));
		while (*s && *s != c)
		{
			tab[j][k] = *s;
			s++;
			k++;
		}
		tab[j][k] = 0;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	nb_words;
	size_t	i;
	char	**res;

	if (!s)
		return (NULL);
	nb_words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			nb_words++;
		while (s[i] && s[i] != c)
			i++;
	}
	res = malloc(sizeof(char *) * (nb_words + 1));
	if (!res)
		return (NULL);
	return (ft_splitcpy(s, res, c, nb_words));
}

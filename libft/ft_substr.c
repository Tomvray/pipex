/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvray <tvray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:43:08 by tvray             #+#    #+#             */
/*   Updated: 2022/10/17 16:15:25 by tvray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_calloc(1, 1));
	if (len > len_s - start)
		len = len_s - start;
	res = malloc((len + 1) * sizeof(char));
	if (res != NULL)
	{
		i = 0;
		while (i < len)
		{
			res[i] = s[start + i];
			i++;
		}
		res[i] = 0;
	}
	return (res);
}

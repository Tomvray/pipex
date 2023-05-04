#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
    size_t  len1;
    size_t  len2;
    size_t  i;
    char    *res;

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    res = malloc(sizeof(char) * (len1 + len2 + 1));
    if (!res)
        return (res);
    i = 0;
    while (i < len1)
    {
        res[i] = s1[i];
        i++;
    }
    while (i < len1 + len2)
    {
        res[i] = s2[i - len1];
        i++;
    }
    res[i] = 0;
    return (res);
}
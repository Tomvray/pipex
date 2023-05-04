#include "libft.h"

size_t	ft_lenword(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char	**ft_splitcpy(char const *s, char **tab, char c, size_t len)
{
	size_t	j;
	size_t	k;

	j = 0;
	while (j < len)
	{
		k = 0;
		while (*s && *s == c)
			s++;
		tab[j] = (char*) malloc(sizeof(char) * (ft_lenword(s, c) + 1));
		if (!tab[j])
			return (NULL);
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
	res = malloc(sizeof(char*) * (nb_words + 1));
	if (!res)
		return (NULL);
	return (ft_splitcpy(s, res, c, nb_words));
}

/*
int main(int argc, char **argv)
{
    char **split;
	char	*s;
    int i;
    i = 0;
	s = "01234";
    if (argc == 3)
    {
        split = ft_split(argv[1], argv[2][0]);
    
        while (split[i])
        {
            printf("%s\n", split[i]);
            free(split[i]);
            i++;
        }
        free(split);
    }
}
*/
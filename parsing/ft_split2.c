
#include "../cub3d.h"

int	ft_strtab2(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i])
	{
		if ((str[i] == c) && (i != 0) && (str[i - 1] != c))
			j++;
		i++;
	}
	return (j);
}

int	ft_slen2(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	return (i);
}

char	**ft_free2(char **tab, int j)
{
	while (j)
		free(tab[j--]);
	free(tab);
	return (NULL);
}

char	**ft_decoupe2(char **tab, char *str, int k, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			tab[j] = malloc(sizeof(char) * (ft_slen2(&str[i], c) + 1));
			if (!tab)
				return (ft_free2(tab, j));
			while ((str[i]) && (str[i] != c))
				tab[j][k++] = str[i++];
			tab[j][k] = '\0';
			j++;
			k = 0;
		}
		else
		{
			i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split2(char const *s, char c)
{
	int k;
	char **tab;
	char *str;

	k = 0;
	if (s == NULL)
		return (NULL);
	str = (char *)s;
	tab = malloc(sizeof(char *) * ((ft_strtab2(str, c)) +  (1)));
	if (!tab)
		return (NULL);
	return (ft_decoupe2(tab, str, k, c));
}
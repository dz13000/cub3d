/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 00:04:37 by cabouzir          #+#    #+#             */
/*   Updated: 2023/11/26 00:55:58 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strtab(char *str, char c)
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

int	ft_slen(char *str, char c)
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

char	**ft_free(char **tab, int j)
{
	while (j)
		free(tab[j--]);
	free(tab);
	return (NULL);
}

char	**ft_decoupe(char **tab, char *str, int k, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			tab[j] = malloc(sizeof(char) * (ft_slen(&str[i], c) + 1));
			if (!tab)
				return (ft_free(tab, j));
			while ((str[i]) && (str[i] != c))
				tab[j][k++] = str[i++];
			tab[j][k] = '\0';
			j++;
			k = 0;
		}
        // else if (str[i] == c && str[i - 1] != c)
        // {
        //     i++;
        // }
		// else if(str[i] == c && str[i - 1] == c)
        // {
        //       if(str[i] == c)
        //     {
        //         tab[j] = malloc(sizeof(char) * 2);
        //         if (!tab)
		// 		    return (ft_free(tab, j));
        //         tab[j][0] = c;
        //         tab[j][1] = 0;
        //         j++;
        //     }
		// 	i++;
        // }
        else
            i++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		k;
	char	**tab;
	char	*str;

	k = 0;
	if (s == NULL)
		return (NULL);
	str = (char *)s;
	tab = malloc(sizeof(char *) * (ft_strtab(str, c) + 1));
	if (!tab)
		return (NULL);
	return (ft_decoupe(tab, str, k, c));
}
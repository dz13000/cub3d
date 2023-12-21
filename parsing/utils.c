/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 01:56:17 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 02:22:49 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

typedef struct s_ok
{
	int		i;
	int		j;
	int		k;
	int		nb;
	int		max;
	char	*tmp;
	char	**final;
}t_ok;

void	change_map2_utils(t_ok *ok, char **map)
{
	while (map[ok->i])
	{
		ok->final[ok->j] = ft_strdup(map[ok->i]);
		ok->k = 0;
		if (ft_strlen(map[ok->i]) < ok->max)
		{
			ok->nb = ok->max - ft_strlen(map[ok->i]);
			ok->tmp = malloc(sizeof(char *) * (ok->nb + 1));
			while (ok->k < ok->nb)
			{
				ok->tmp[ok->k] = 'v';
				ok->k++;
			}
			ok->tmp[ok->k] = '\0';
			ok->final[ok->j] = ft_strjoin(ok->final[ok->j], ok->tmp);
			free(ok->tmp);
		}
		ok->i++;
		ok->j++;
	}
}

char	**change_map2(char **map)
{
	static t_ok	ok = {0};

	ok.max = ft_strlen(map[ok.i]);
	while (map[ok.i])
	{
		ok.nb = ft_strlen(map[ok.i]);
		if (ok.nb > ok.max)
			ok.max = ok.nb;
		ok.i++;
	}
	ok.final = malloc(sizeof(char **) * (ok.i + 1));
	ok.i = 0;
	ok.nb = 0;
	change_map2_utils(&ok, map);
	ok.final[ok.j] = NULL;
	return (ok.final);
}

int	ft_strlen3(char *str)
{
	int	i;
	int	j;

	j = 0;
	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i])
	{
		i++;
		j++;
	}
	return (j);
}

char	*ft_strdup3(char *str)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	cpy = malloc(sizeof(char) * (slen(str) + 1));
	if (!cpy)
		return (NULL);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i])
	{
		cpy[j] = str[i];
		i++;
		j++;
	}
	cpy[i] = '\0';
	return (cpy);
}

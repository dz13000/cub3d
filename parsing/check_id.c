/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 02:46:42 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/02 04:27:29 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	verif_line(char *tmp)
{
	int	i;

	i = 0;
	while (tmp && tmp[i])
	{
		if (tmp[i] != ' ' && tmp[i] != '\t' && tmp[i + 1] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int	check_before(t_cub *cub, int i, int j)
{
	if (j == 0)
		return (0);
	if (j == 1)
	{
		if (cub->map2[i][j - 1] != ' ' && cub->map2[i][j - 1] != '\t')
			return (1);
		else
			return (0);
	}
	if (j > 1)
		j--;
	while (j && j >= 0)
	{
		if (cub->map2[i][j] != ' ' && cub->map2[i][j] != '\t')
			return (1);
		j--;
	}
	return (0);
}

int	check_id(t_cub *cub)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (cub->map2[i])
	{
		j = 0;
		while (cub->map2[i][j])
		{
			if (cub->map2[i][j] == 'N' && cub->map2[i][j + 1] == 'O'
				&& (cub->map2[i][j + 2] == ' ' || cub->map2[i][j + 2] == '\t'))
			{
				if (check_before(&*cub, i, j) == 0 && cub->line_no == 0)
				{
					cub->line_no = i;
					cub->count++;
					cub->line_no++;
					break ;
				}
			}
			else if (cub->map2[i][j] == 'S' && cub->map2[i][j + 1] == 'O'
					&& (cub->map2[i][j + 2] == ' ' || cub->map2[i][j
						+ 2] == '\t'))
			{
				if (check_before(&*cub, i, j) == 0 && cub->line_so == 0)
				{
					cub->line_so = i;
					cub->count++;
					cub->line_so++;
					break ;
				}
			}
			else if (cub->map2[i][j] == 'W' && cub->map2[i][j + 1] == 'E'
					&& (cub->map2[i][j + 2] == ' ' || cub->map2[i][j
						+ 2] == '\t'))
			{
				if (check_before(&*cub, i, j) == 0 && cub->line_we == 0)
				{
					cub->line_we = i;
					cub->count++;
					cub->line_we++;
					break ;
				}
			}
			else if (cub->map2[i][j] == 'E' && cub->map2[i][j + 1] == 'A'
					&& (cub->map2[i][j + 2] == ' ' || cub->map2[i][j
						+ 2] == '\t'))
			{
				if (check_before(&*cub, i, j) == 0 && cub->line_ea == 0)
				{
					cub->line_ea = i;
					cub->count++;
					cub->line_ea++;
					break ;
				}
			}
			else if (cub->map2[i][j] == 'F' && (cub->map2[i][j + 1] == ' '
						|| cub->map2[i][j + 1] == '\t'))
			{
				if (check_before(&*cub, i, j) == 0 && cub->line_f == 0)
				{
					cub->line_no = i;
					cub->count++;
					cub->line_f++;
					break ;
				}
			}
			else if (cub->map2[i][j] == 'C' && (cub->map2[i][j + 1] == ' '
						|| cub->map2[i][j + 1] == '\t'))
			{
				if (check_before(&*cub, i, j) == 0 && cub->line_c == 0)
				{
					cub->count++;
					cub->line_c++;
					break ;
				}
			}
			j++;
		}
		i++;
	}
	if (cub->count == 6)
	{
		printf("--------------->good\n");
		return (0);
	}
	return (1);
}

int	verif_line2(char *tmp)
{
	int	i;

	i = 0;
	if (!tmp || tmp[0] == '\0')
		return (1);
	while (tmp && tmp[i])
	{
		if (tmp[i] != ' ' && tmp[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

char	**split_map(char **tab)
{
	int		i;
	int		j;
	int		k;
	char	**map;

	i = 0;
	j = 0;
	k = 0;
	while (tab[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (verif_line2(tab[i]) == 0)
			break ;
		i--;
	}
	while (tab[k])
	{
		if (verif_line2(tab[k]) == 0)
			break ;
		k++;
	}
	printf("----->>>%d\n", k);
	map = malloc(sizeof(char **) * ((i - k) + 1));
	while (k <= i)
	{
		map[j] = ft_strdup(tab[k]);
		k++;
		j++;
	}
	if(!map)
	{
		//tt free ici;
		printf("Map introuvable\n");
		exit(1);
	}
	map[j] = NULL;
	return (map);
}

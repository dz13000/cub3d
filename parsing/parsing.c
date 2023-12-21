/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:05:36 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 09:49:45 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_f_utils(t_cub *cub, int *i, int *j)
{
	while (cub->map2[*i])
	{
		*j = 0;
		while (cub->map2[*i][*j])
		{
			if (cub->map2[*i][*j] == 'F')
				break ;
			*j += 1;
		}
		if (cub->map2[*i][*j] == 'F')
			break ;
		*i += 1;
	}
	*j += 1;
}

int	check_f(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	check_f_utils(&*cub, &i, &j);
	if (cub->map2[i][j] != ' ' && cub->map2[i][j] != '\t')
		return (1);
	while (cub->map2[i][j])
	{
		if (cub->map2[i][j] != ' ' && cub->map2[i][j] != '\t')
			break ;
		j++;
	}
	if (check_virgule(&cub->map2[i][j]) == 1)
		return (1);
	if (check_char_line(&cub->map2[i][j]) == 1)
		return (1);
	if (check_number(&cub->map2[i][j]) == 1)
		return (1);
	if (check_space_number(&cub->map2[i][j]) == 1)
		return (1);
	if (check_atoi_f(&cub->map2[i][j], &*cub) == 1)
		return (1);
	return (0);
}

int	check_id2(t_cub *cub)
{
	if (check_f(&*cub) == 1)
		return (1);
	if (check_c(&*cub) == 1)
		return (1);
	if (check_so(&*cub) == 1)
		return (1);
	if (check_no(&*cub) == 1)
		return (1);
	if (check_ea(&*cub) == 1)
		return (1);
	if (check_we(&*cub) == 1)
		return (1);
	return (0);
}

void	ft_check_id_parsing(t_cub *cub)
{
	int	i;

	i = 0;
	if (check_id(&*cub) == 1)
	{
		free(cub->map);
		i = 0;
		while (cub->map2[i])
			i++;
		while (i >= 0)
			free(cub->map2[i--]);
		free(cub->map2);
		dprintf(2, "Pas les bons identifiants mon reuf\n");
		exit(1);
	}
	if (check_id2(&*cub) == 1)
	{
		free_1(&*cub);
		dprintf(2, "Pas les bons identifiants mon reuf 2\n");
		exit(1);
	}
}

int	ft_parsing(char **argv, t_cub *cub)
{
	cub->map = copy_map2(argv);
	cub->map2 = ft_split2(cub->map, '\n');
	ft_check_id_parsing(&*cub);
	grep_last_line(&*cub);
	cub->map_bis = copy_map(argv, &*cub);
	cub->map2_bis = ft_split(cub->map_bis, '\n');
	cub->maps_finish = split_map(cub->map2_bis, &*cub);
	if (verif_map(&*cub) == 1)
	{
		free_2(&*cub);
		exit(1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 08:43:37 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 08:44:36 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	grep_last_line(t_cub *cub)
{
	int	i;
	int	j;

	cub->last_line = malloc(sizeof(char) * 3);
	i = 0;
	j = 0;
	while (cub->map2[i])
		i++;
	i--;
	while (cub->map[i] && (cub->map2[i][j] == '\t' || cub->map2[i][j] == ' '))
	{
		j++;
	}
	cub->last_line[0] = cub->map2[i][j];
	cub->last_line[1] = cub->map2[i][j + 1];
	cub->last_line[2] = '\0';
}

void	check_no2(t_cub *cub, int *i, int *j)
{
	int	tmp;

	tmp = 0;
	while (cub->map2[*i])
	{
		*j = 0;
		while (cub->map2[*i][*j])
		{
			tmp = *j;
			if (cub->map2[*i][*j] == 'N' && cub->map2[*i][tmp + 1] == 'O')
				break ;
			*j += 1;
		}
		tmp = *j;
		if (cub->map2[*i][*j] == 'N' && cub->map2[*i][tmp + 1] == 'O')
			break ;
		*i += 1;
	}
	*j += 1;
}

int	check_no(t_cub *cub)
{
	int	i;
	int	j;
	int	fd;

	i = 0;
	j = 0;
	check_no2(&*cub, &i, &j);
	if (cub->map2[i][j + 1] != ' ' && cub->map2[i][j + 1] != '\t')
		return (1);
	j++;
	while (cub->map2[i][j] && cub->map2[i][j] != '.')
	{
		if (cub->map2[i][j] != ' ' && cub->map2[i][j] != '\t')
			return (1);
		j++;
	}
	fd = open(&cub->map2[i][j], O_RDONLY);
	if (fd == -1)
	{
		cub->nb_fr = 1;
		return (1);
	}
	cub->path_no = ft_strdup(&cub->map2[i][j]);
	close(fd);
	return (0);
}

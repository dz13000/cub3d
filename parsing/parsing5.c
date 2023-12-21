/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 08:42:06 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 08:44:44 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_so2(t_cub *cub, int *i, int *j)
{
	int	tmp;

	tmp = 0;
	while (cub->map2[*i])
	{
		*j = 0;
		while (cub->map2[*i][*j])
		{
			tmp = *j;
			if (cub->map2[*i][*j] == 'S' && cub->map2[*i][tmp + 1] == 'O')
				break ;
			*j += 1;
		}
		tmp = *j;
		if (cub->map2[*i][*j] == 'S' && cub->map2[*i][tmp + 1] == 'O')
			break ;
		*i += 1;
	}
	*j += 1;
}

int	check_so(t_cub *cub)
{
	int	i;
	int	j;
	int	fd;

	i = 0;
	j = 0;
	check_so2(&*cub, &i, &j);
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
		return (1);
	cub->path_so = ft_strdup(&cub->map2[i][j]);
	close(fd);
	return (0);
}

void	check_ea2(t_cub *cub, int *i, int *j)
{
	int	tmp;

	tmp = 0;
	while (cub->map2[*i])
	{
		*j = 0;
		while (cub->map2[*i][*j])
		{
			tmp = *j;
			if (cub->map2[*i][*j] == 'E' && cub->map2[*i][tmp + 1] == 'A')
				break ;
			*j += 1;
		}
		tmp = *j;
		if (cub->map2[*i][*j] == 'E' && cub->map2[*i][tmp + 1] == 'A')
			break ;
		*i += 1;
	}
	*j += 1;
}

int	check_ea(t_cub *cub)
{
	int	i;
	int	j;
	int	fd;

	i = 0;
	j = 0;
	check_ea2(&*cub, &i, &j);
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
		cub->nb_fr = 2;
		return (1);
	}
	cub->path_ea = ft_strdup(&cub->map2[i][j]);
	close(fd);
	return (0);
}

void	check_we2(t_cub *cub, int *i, int *j)
{
	int	tmp;

	tmp = 0;
	while (cub->map2[*i])
	{
		*j = 0;
		while (cub->map2[*i][*j])
		{
			tmp = *j;
			if (cub->map2[*i][*j] == 'W' && cub->map2[*i][tmp + 1] == 'E')
				break ;
			*j += 1;
		}
		tmp = *j;
		if (cub->map2[*i][*j] == 'W' && cub->map2[*i][tmp + 1] == 'E')
			break ;
		*i += 1;
	}
	*j += 1;
}

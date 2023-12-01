/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:10:11 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/01 01:14:48 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_fisrt_wall(t_cub *cub)
{
	int	j;

	j = 0;
	while (cub->maps_finish[0][j])
	{
		if (cub->maps_finish[0][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	check_last_wall(t_cub *cub)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (cub->maps_finish[i])
		i++;
	i--;
	while (cub->maps_finish[i][j])
	{
		if (cub->maps_finish[i][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	check_wall(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	// printf("-----%s\n", cub->map2_bis[i]);
	while (cub->maps_finish[i])
	{
		j = 0;
		while (cub->maps_finish[i][j] && (cub->maps_finish[i][j] == ' '
				|| cub->maps_finish[i][j] == '\t'))
			j++;
		if (cub->maps_finish[i][j] != '1')
		{
			puts("je rentre\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_wall_end(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cub->maps_finish[i])
	{
		j = 0;
		while (cub->maps_finish[i][j])
			j++;
		j--;
		if (cub->maps_finish[i][j] != '1')
		{
			puts("je rentre2\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	verif_map(t_cub *cub)
{
	if (check_wall(&*cub) == 1)
		return (1);
	if (check_wall_end(&*cub) == 1)
		return (1);
	if (check_fisrt_wall(&*cub) == 1)
		return (1);
	if (check_last_wall(&*cub) == 1)
		return (1);
	if (check_char_map(&*cub) == 1)
		return (1);
	if (check_size(&*cub) == 1)
		return (1);
	if (check_spaces(&*cub) == 1)
	{
		puts("TROU\n");
		return (1);
	}
	if (check_player(&*cub) == 1)
		return(1);
	return (0);
}
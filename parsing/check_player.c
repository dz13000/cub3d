/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:46:52 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/01 02:12:11 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_player2(t_cub *cub)
{
	if ((cub->player_e == 0 && cub->player_s == 0 && cub->player_w == 0
			&& cub->player_n == 0))
		return (1);
	if (cub->player_e > 1)
		return (1);
	if (cub->player_s > 1)
		return (1);
	if (cub->player_w > 1)
		return (1);
	if (cub->player_n > 1)
		return (1);
	if (cub->player_e == 1 && (cub->player_s != 0 || cub->player_w != 0
			|| cub->player_n != 0))
		return (1);
	if (cub->player_s == 1 && (cub->player_e != 0 || cub->player_w != 0
			|| cub->player_n != 0))
		return (1);
	if (cub->player_w == 1 && (cub->player_s != 0 || cub->player_e != 0
			|| cub->player_n != 0))
		return (1);
	if (cub->player_n == 1 && (cub->player_s != 0 || cub->player_w != 0
			|| cub->player_e != 0))
		return (1);
	return (0);
}

int	check_player(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (cub->maps_finish[i])
	{
		j = 0;
		while (cub->maps_finish[i][j])
		{
			if (cub->maps_finish[i][j] == 'N')
				cub->player_n++;
			if (cub->maps_finish[i][j] == 'S')
				cub->player_s++;
			if (cub->maps_finish[i][j] == 'W')
				cub->player_w++;
			if (cub->maps_finish[i][j] == 'E')
				cub->player_e++;
			j++;
		}
		i++;
	}
	if (check_player2(&*cub) == 1)
		return (1);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:26:15 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 09:31:31 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_zero_utils(t_cub *cub, int i, int j)
{
	if (cub->test[i][j] == '0')
	{
		if (cub->test[i - 1][j] == 'v')
			return (1);
		if (cub->test[i + 1][j] == 'v')
			return (1);
		if (cub->test[i][j - 1] == 'v')
			return (1);
		if (cub->test[i][j + 1] == 'v')
			return (1);
	}
	return (0);
}

int	check_zero(t_cub *cub)
{
	int	j;
	int	i;

	i = 1;
	j = 0;
	cub->test = change_map2(cub->maps_finish);
	while (cub->test[i])
	{
		j = 0;
		while (cub->test[i][j])
		{
			if (check_zero_utils(&*cub, i, j) == 1)
				return (1);
			j++;
		}
		i++;
	}
	while (i >= 0)
	{
		free(cub->test[i]);
		i--;
	}
	free(cub->test);
	return (0);
}

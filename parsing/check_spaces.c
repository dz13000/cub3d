/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:50:51 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 09:35:44 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_up(t_cub *cub, int i, int j)
{
	int	i2;
	int	j2;

	i2 = i;
	j2 = j;
	while (i2 >= 1)
	{
		if (cub->maps_finish[i2][j2] == ' ')
		{
			i2--;
			continue ;
		}
		if (cub->maps_finish[i2][j2] != '1')
		{
			return (1);
		}
		if (cub->maps_finish[i2][j2] == '1')
		{
			break ;
		}
	}
	return (0);
}

int	check_left(t_cub *cub, int i, int j)
{
	int	i2;
	int	j2;

	i2 = i;
	j2 = j;
	while (j2 >= 1)
	{
		if (cub->maps_finish[i2][j2] == ' ')
		{
			j2--;
			continue ;
		}
		if (cub->maps_finish[i2][j2] != '1')
		{
			return (1);
		}
		if (cub->maps_finish[i2][j2] == '1')
		{
			break ;
		}
	}
	return (0);
}

int	check_down(t_cub *cub, int i, int j)
{
	int	i2;
	int	j2;

	i2 = i;
	j2 = j;
	while (cub->maps_finish[i2] && cub->maps_finish[i2 + 1] != NULL)
	{
		if (cub->maps_finish[i2][j2] == ' ')
		{
			i2++;
			continue ;
		}
		if (cub->maps_finish[i2][j2] != '1')
		{
			return (1);
		}
		if (cub->maps_finish[i2][j2] == '1')
		{
			break ;
		}
	}
	return (0);
}

int	check_right(t_cub *cub, int i, int j)
{
	int	i2;
	int	j2;

	i2 = i;
	j2 = j;
	while (cub->maps_finish[i2][j2] && cub->maps_finish[i2][j2 + 1] != '\0')
	{
		if (cub->maps_finish[i2][j2] == ' ')
		{
			j2++;
			continue ;
		}
		if (cub->maps_finish[i2][j2] != '1')
		{
			return (1);
		}
		if (cub->maps_finish[i2][j2] == '1')
		{
			break ;
		}
	}
	return (0);
}

int	check_spaces(t_cub *cub)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (cub->maps_finish[++i])
	{
		j = 0;
		while (cub->maps_finish[i][j])
		{
			if (cub->maps_finish[i][j] == ' ')
			{
				if (check_up(&*cub, i, j) == 1)
					return (1);
				if (check_down(&*cub, i, j) == 1)
					return (1);
				if (check_left(&*cub, i, j) == 1)
					return (1);
				if (check_right(&*cub, i, j) == 1)
					return (1);
			}
			j++;
		}
	}
	return (0);
}

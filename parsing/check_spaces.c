/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:50:51 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/01 01:52:51 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_up(t_cub *cub, int i, int j)
{
	int	i2;
	int	j2;

	i2 = i;
	j2 = j;
	printf(">>>>>>>>>%d\n", i2);
	printf(">>>>>>>>>%d\n", j2);
	while (i2 >= 1)
	{
		if (cub->maps_finish[i2][j2] == ' ')
		{
			i2--;
			puts("ICI\n");
			continue ;
		}
		if (cub->maps_finish[i2][j2] != '1')
		{
			// printf("+++>>>%c\n", cub->maps_finish[i2][j2]);
			puts("TROU2\n");
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
	printf(">>>>>>>>>%d\n", i2);
	printf(">>>>>>>>>%d\n", j2);
	while (j2 >= 1)
	{
		if (cub->maps_finish[i2][j2] == ' ')
		{
			j2--;
			puts("ICI\n");
			continue ;
		}
		if (cub->maps_finish[i2][j2] != '1')
		{
			// printf("+++>>>%c\n", cub->maps_finish[i2][j2]);
			puts("TROU2\n");
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
	printf(">>>>>>>>>%d\n", i2);
	printf(">>>>>>>>>%d\n", j2);
	while (cub->maps_finish[i2] && cub->maps_finish[i2 + 1] != NULL)
	{
		if (cub->maps_finish[i2][j2] == ' ')
		{
			i2++;
			puts("ICI\n");
			continue ;
		}
		if (cub->maps_finish[i2][j2] != '1')
		{
			// printf("+++>>>%c\n", cub->maps_finish[i2][j2]);
			puts("TROU2\n");
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
	printf(">>>>>>>>>%d\n", i2);
	printf(">>>>>>>>>%d\n", j2);
	while (cub->maps_finish[i2][j2] && cub->maps_finish[i2][j2 + 1] != '\0')
	{
		if (cub->maps_finish[i2][j2] == ' ')
		{
			j2++;
			puts("ICI\n");
			continue ;
		}
		if (cub->maps_finish[i2][j2] != '1')
		{
			// printf("+++>>>%c\n", cub->maps_finish[i2][j2]);
			puts("TROU2\n");
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
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (cub->maps_finish[i])
	{
		j = 0;
		while (cub->maps_finish[i][j] && cub->maps_finish[i][j] != '1')
			j++;
		while (cub->maps_finish[i][j])
		{
			// puts("TROU\n");
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
		i++;
	}
	return (0);
}
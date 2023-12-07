/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:50:51 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/07 10:25:58 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_up2(t_cub *cub, int i, int j)
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

int	check_left2(t_cub *cub, int i, int j)
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
int	check_down2(t_cub *cub, int i, int j)
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

int	check_right2(t_cub *cub, int i, int j)
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

int	check_zero(t_cub *cub)
{
	int i;
	int j;

	i = 1;
	j = 0;
	cub->test = change_map2(cub->maps_finish);
	// int i2 = 0;
	// while (cub->test[i2])
	// {
	// 	printf("%s\n", cub->test[i2]);
	// 	i2++;
	// }
	while (cub->test[i])
	{
		j = 0;
		// while (cub->test[i][j] && cub->test[i][j] != '1')
		// 	j++;
		while (cub->test[i][j])
		{
			// puts("TROU\n");
			if (cub->test[i][j] == '0')
			{
				// printf("--->>>%c\n", cub->test[i - 1][j]);
				if(cub->test[i - 1][j] == 'v')
					return(1);
				if(cub->test[i + 1][j] == 'v')
					return(1);
				if(cub->test[i][j - 1] == 'v')
					return(1);
				if(cub->test[i][j + 1] == 'v')
					return(1);
			}
			j++;
		}
		i++;
	}
	while(i >= 0)
	{
		free(cub->test[i]);
		i--;
	}
	free(cub->test);
	return (0);
}

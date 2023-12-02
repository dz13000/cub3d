/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:24:47 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/01 02:12:30 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
int	check_size(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->maps_finish[i])
	{
		if (ft_strlen(cub->maps_finish[i]) < 3)
			return (1);
		i++;
	}
	return (0);
}

int	ft_char(char c)
{
	if (c == '1')
		return (0);
	if (c == '0')
		return (0);
	if (c == 'N')
		return (0);
	if (c == 'S')
		return (0);
	if (c == 'E')
		return (0);
	if (c == 'W')
		return (0);
	if (c == ' ')
		return (0);
	return (1);
}

int	check_char_map(t_cub *cub)
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
			if (ft_char(cub->maps_finish[i][j]) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
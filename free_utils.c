/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 00:02:19 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 00:41:00 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	all_free(t_cub *cub)
{
	int	i;

	i = 0;
	free(cub->map);
	while (cub->map2[i])
		i++;
	while (i >= 0)
		free(cub->map2[i--]);
	free(cub->map2);
	free(cub->map_bis);
	i = 0;
	while (cub->map2_bis[i])
		i++;
	while (i >= 0)
		free(cub->map2_bis[i--]);
	free(cub->map2_bis);
	i = 0;
	while (cub->maps_finish[i])
		i++;
	i--;
	while (i >= 0)
		free(cub->maps_finish[i--]);
	free(cub->maps_finish);
	free(cub->last_line);
}

void	copy_map_utils(char *tmp, int *fd, t_cub *cub)
{
	while (1)
	{
		tmp = get_next_line(*fd);
		if (check_last_line(tmp, &*cub) == 1)
		{
			free(tmp);
			break ;
			return ;
		}
		free(tmp);
		if (tmp == NULL)
		{
			break ;
			return ;
		}
	}
}

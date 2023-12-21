/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:14:20 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 11:30:46 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(t_exec *exec)
{
	char	pos_x;
	char	pos_y;
	int		x;
	int		y;

	x = (int)(exec->ray.posx + exec->ray.dirx * exec->ray.movespeed);
	y = (int)(exec->ray.posy + exec->ray.diry * exec->ray.movespeed);
	pos_x = exec->final_map[x][(int)(exec->ray.posy)];
	pos_y = exec->final_map[(int)(exec->ray.posx)][y];
	if (pos_x == '0')
		exec->ray.posx += exec->ray.dirx * exec->ray.movespeed;
	if (pos_y == '0')
		exec->ray.posy += exec->ray.diry * exec->ray.movespeed;
}

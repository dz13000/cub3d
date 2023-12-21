/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:12:44 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 11:30:50 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_down(t_exec *exec)
{
	if (exec->final_map[(int)(exec->ray.posx - exec->ray.dirx
			* exec->ray.movespeed)][(int)(exec->ray.posy)] == '0')
		exec->ray.posx -= exec->ray.dirx * exec->ray.movespeed;
	if (exec->final_map[(int)(exec->ray.posx)][(int)(exec->ray.posy
			- exec->ray.diry * exec->ray.movespeed)] == '0')
		exec->ray.posy -= exec->ray.diry * exec->ray.movespeed;
}

void	move_left(t_exec *exec)
{
	if (exec->final_map[(int)(exec->ray.posx - exec->ray.diry
			* exec->ray.movespeed)][(int)(exec->ray.posy)] == '0')
		exec->ray.posx -= exec->ray.diry * exec->ray.movespeed;
	if (exec->final_map[(int)(exec->ray.posx)][(int)(exec->ray.posy
			+ exec->ray.dirx * exec->ray.movespeed)] == '0')
		exec->ray.posy += exec->ray.dirx * exec->ray.movespeed;
}

void	move_right(t_exec *exec)
{
	if (exec->final_map[(int)(exec->ray.posx + exec->ray.diry
			* exec->ray.movespeed)][(int)(exec->ray.posy)] == '0')
		exec->ray.posx += exec->ray.diry * exec->ray.movespeed;
	if (exec->final_map[(int)(exec->ray.posx)][(int)(exec->ray.posy
			- exec->ray.dirx * exec->ray.movespeed)] == '0')
		exec->ray.posy -= exec->ray.dirx * exec->ray.movespeed;
}

void	rotate_left(t_exec *exec)
{
	double	olddirx;
	double	oldplanex;

	olddirx = exec->ray.dirx;
	exec->ray.dirx = exec->ray.dirx * cos(exec->ray.rotspeed) - exec->ray.diry
		* sin(exec->ray.rotspeed);
	exec->ray.diry = olddirx * sin(exec->ray.rotspeed) + exec->ray.diry
		* cos(exec->ray.rotspeed);
	oldplanex = exec->ray.planx;
	exec->ray.planx = exec->ray.planx * cos(exec->ray.rotspeed)
		- exec->ray.plany * sin(exec->ray.rotspeed);
	exec->ray.plany = oldplanex * sin(exec->ray.rotspeed) + exec->ray.plany
		* cos(exec->ray.rotspeed);
}

void	rotate_right(t_exec *exec)
{
	double	olddirx;
	double	oldplanex;

	olddirx = exec->ray.dirx;
	exec->ray.dirx = exec->ray.dirx * cos(-exec->ray.rotspeed) - exec->ray.diry
		* sin(-exec->ray.rotspeed);
	exec->ray.diry = olddirx * sin(-exec->ray.rotspeed) + exec->ray.diry
		* cos(-exec->ray.rotspeed);
	oldplanex = exec->ray.planx;
	exec->ray.planx = exec->ray.planx * cos(-exec->ray.rotspeed)
		- exec->ray.plany * sin(-exec->ray.rotspeed);
	exec->ray.plany = oldplanex * sin(-exec->ray.rotspeed) + exec->ray.plany
		* cos(-exec->ray.rotspeed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:25:52 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 11:30:54 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_letter(t_exec *exec)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	j = 0;
	nb = 0;
	while (exec->final_map[i])
	{
		j = 0;
		check_letter2(&*exec, &i, &j, &nb);
		if (nb == 1)
			break ;
		i++;
	}
	exec->ray.posx = (double)i;
	exec->ray.posy = (double)j;
}

void	view_letter(t_exec *exec)
{
	if (exec->letter == 'N')
	{
		exec->ray.dirx = -1;
		exec->ray.diry = 0;
	}
	else if (exec->letter == 'S')
	{
		exec->ray.dirx = 1;
		exec->ray.diry = 0;
	}
	else if (exec->letter == 'W')
	{
		exec->ray.dirx = 0;
		exec->ray.diry = -1;
	}
	else if (exec->letter == 'E')
	{
		exec->ray.dirx = 0;
		exec->ray.diry = 1;
	}
}

void	init_buff(t_exec *exec)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < HEIGHT)
		while (++j < WIDTH)
			exec->ray.buf[i][j] = 0;
}

void	init_values(t_exec *exec, int x)
{
	double	camerax;

	if (exec->ray.side == 0)
		exec->ray.perpwalldist = (exec->ray.mapx - exec->ray.posx + (1
					- exec->ray.stepx) / 2) / exec->ray.raydirx;
	else
		exec->ray.perpwalldist = (exec->ray.mapy - exec->ray.posy + (1
					- exec->ray.stepy) / 2) / exec->ray.raydiry;
	camerax = 2 * x / (double)WIDTH - 1;
	exec->ray.raydirx = exec->ray.dirx + exec->ray.planx * camerax;
	exec->ray.raydiry = exec->ray.diry + exec->ray.plany * camerax;
	exec->ray.mapx = (int)exec->ray.posx;
	exec->ray.mapy = (int)exec->ray.posy;
	exec->ray.deltadistx = fabs(1 / exec->ray.raydirx);
	exec->ray.deltadisty = fabs(1 / exec->ray.raydiry);
}

void	define(t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - ray->posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - ray->posy) * ray->deltadisty;
	}
}

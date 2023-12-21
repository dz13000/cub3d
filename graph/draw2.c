/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:24:24 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 11:29:07 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	define_side(t_exec *exec)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (exec->ray.sidedistx < exec->ray.sidedisty)
		{
			exec->ray.sidedistx += exec->ray.deltadistx;
			exec->ray.mapx += exec->ray.stepx;
			exec->ray.side = 0;
		}
		else
		{
			exec->ray.sidedisty += exec->ray.deltadisty;
			exec->ray.mapy += exec->ray.stepy;
			exec->ray.side = 1;
		}
		if (exec->final_map[exec->ray.mapx][exec->ray.mapy] > '0')
			hit = 1;
	}
}

void	define_draw(t_exec *exec)
{
	exec->ray.lineheight = (int)(HEIGHT / exec->ray.perpwalldist);
	exec->ray.drawstart = -exec->ray.lineheight / 2 + HEIGHT / 2;
	if (exec->ray.drawstart < 0)
		exec->ray.drawstart = 0;
	exec->ray.drawend = exec->ray.lineheight / 2 + HEIGHT / 2;
	if (exec->ray.drawend >= HEIGHT || exec->ray.drawend < 0)
		exec->ray.drawend = HEIGHT - 1;
}

int	choose_texture(t_exec *exec, int texNum)
{
	if (exec->ray.raydirx > 0 && exec->ray.side == 0)
		texNum = 0;
	else if (exec->ray.raydirx < 0 && exec->ray.side == 0)
		texNum = 1;
	else if (exec->ray.raydiry > 0 && exec->ray.side == 1)
		texNum = 2;
	else
		texNum = 3;
	return (texNum);
}

void	define_wallx(t_exec *exec, double *wallx, int *texnum, int x)
{
	init_values(&*exec, x);
	define(&exec->ray);
	define_side(&*exec);
	define_draw(&*exec);
	*texnum = choose_texture(&*exec, *texnum);
	if (exec->ray.side == 0)
		*wallx = exec->ray.posy + exec->ray.perpwalldist * exec->ray.raydiry;
	else
		*wallx = exec->ray.posx + exec->ray.perpwalldist * exec->ray.raydirx;
}

void	on_draw(t_exec *exec, int x, int texNum, int texX)
{
	double	step;
	double	texpos;
	int		texy;
	int		color;
	int		y;

	y = exec->ray.drawstart;
	step = 1.0 * 64 / exec->ray.lineheight;
	texpos = (exec->ray.drawstart - HEIGHT / 2 + exec->ray.lineheight / 2)
		* step;
	while (y < exec->ray.drawend)
	{
		texy = (int)texpos & (64 - 1);
		texpos += step;
		color = exec->ray.texture[texNum][64 * texy + texX];
		if (exec->ray.side == 1)
			color = (color >> 1) & 8355711;
		exec->ray.buf[y][x] = color;
		exec->ray.re_buf = 1;
		y++;
	}
}

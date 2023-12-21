/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:19:03 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 11:29:10 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	set_rgb(int rgb[3])
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	ceiling_or_floor(t_exec *exec, int x, int q)
{
	int	i;
	int	y;

	i = 0;
	if (q == 0)
	{
		while (i < exec->ray.drawstart && i < HEIGHT)
		{
			exec->ray.buf[i][x] = set_rgb(exec->ray.ceiling_colors);
			exec->ray.re_buf = 1;
			i++;
		}
		return ;
	}
	y = exec->ray.drawend;
	while (y < HEIGHT - 1)
	{
		exec->ray.buf[y][x] = set_rgb(exec->ray.floor_colors);
		exec->ray.re_buf = 1;
		y++;
	}
}

void	calc(t_exec *exec)
{
	double	wallx;
	int		x;
	int		texnum;
	int		texx;

	x = 0;
	init_buff(&*exec);
	while (x < WIDTH)
	{
		define_wallx(&*exec, &wallx, &texnum, x);
		wallx -= floor(wallx);
		texx = (int)(wallx * (double)64);
		if (exec->ray.side == 0 && exec->ray.raydirx > 0)
			texx = 64 - texx - 1;
		if (exec->ray.side == 1 && exec->ray.raydiry < 0)
			texx = 64 - texx - 1;
		on_draw(&*exec, x, texnum, texx);
		ceiling_or_floor(&*exec, x, 0);
		ceiling_or_floor(&*exec, x, 1);
		x++;
	}
}

void	draw(t_exec *exec)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			exec->img.addr[y * WIDTH + x] = exec->ray.buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(exec->mlx, exec->window, exec->img.img, 0, 0);
}

int	main_loop(t_exec *exec)
{
	calc(&*exec);
	draw(&*exec);
	return (0);
}

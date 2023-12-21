/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:37:17 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 11:30:34 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int key, t_exec *exec)
{
	if (key == 'w')
		move_up(&*exec);
	if (key == 's')
		move_down(&*exec);
	if (key == 'a')
		move_left(&*exec);
	if (key == 'd')
		move_right(&*exec);
	if (key == 65363)
		rotate_right(&*exec);
	if (key == 65361)
		rotate_left(&*exec);
	if (key == 65307 || key == 113)
	{
		free_all(&*exec);
		exit(0);
	}
	mlx_clear_window(&*exec->mlx, &*exec->window);
	main_loop(&*exec);
	return (0);
}

void	free_mlx(t_exec *exec)
{
	int	i;

	i = -1;
	while (++i < HEIGHT)
		free(exec->ray.buf[i]);
	free(exec->ray.buf);
	i = -1;
	while (++i < 4)
		free(exec->ray.texture[i]);
	free(exec->ray.texture);
	if (exec->img.img)
		mlx_destroy_image(exec->mlx, exec->img.img);
	mlx_clear_window(exec->mlx, exec->window);
	mlx_destroy_window(exec->mlx, exec->window);
	mlx_destroy_display(exec->mlx);
	mlx_loop_end(exec->mlx);
	free(exec->mlx);
}

int	free_all(t_exec *exec)
{
	int	i;

	i = 0;
	while (i < 4)
		free(exec->ray.paths[i++]);
	i = 0;
	while (exec->final_map[i])
		i++;
	while (i >= 0)
		free(exec->final_map[i--]);
	free(exec->final_map);
	if (exec->mlx)
		free_mlx(&*exec);
	exit(1);
	return (0);
}

void	ft_init2(t_exec *exec)
{
	check_letter(&*exec);
	view_letter(&*exec);
	define_vector(&*exec);
	exec->ray.re_buf = 1;
	malloc_map(&*exec);
	exec->ray.movespeed = 0.5;
	exec->ray.rotspeed = 0.1;
}

void	ft_init(t_exec *exec, t_cub *cub)
{
	exec->mlx = mlx_init();
	if (!exec->mlx)
	{
		free_all(&*exec);
		exit(1);
	}
	ft_init2(&*exec);
	exec->window = mlx_new_window(exec->mlx, WIDTH, HEIGHT, "cub3d");
	define_texture(&*exec, &*cub);
	load_texture(&*exec);
	exec->img.img = mlx_new_image(exec->mlx, WIDTH, HEIGHT);
	exec->img.addr = (int *)mlx_get_data_addr(exec->img.img,
			&exec->img.bits_per_pixel,
			&exec->img.size_l,
			&exec->img.endian);
	main_loop(&*exec);
	mlx_hook(exec->window, 0, 1L << 0, &key_press, &*exec);
	mlx_hook(exec->window, 17, 0, &free_all, &*exec);
	mlx_key_hook(exec->window, &key_press, &*exec);
	mlx_loop_hook(exec->mlx, &main_loop, &*exec);
	mlx_loop(exec->mlx);
}

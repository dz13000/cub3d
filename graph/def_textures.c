/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:16:28 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 11:28:55 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	define_vector(t_exec *exec)
{
	if (exec->letter == 'N')
	{
		exec->ray.planx = 0;
		exec->ray.plany = 0.66;
	}
	else if (exec->letter == 'S')
	{
		exec->ray.planx = 0;
		exec->ray.plany = -0.66;
	}
	else if (exec->letter == 'W')
	{
		exec->ray.planx = -0.66;
		exec->ray.plany = 0;
	}
	else if (exec->letter == 'E')
	{
		exec->ray.planx = 0.66;
		exec->ray.plany = 0;
	}
}

void	malloc_map(t_exec *exec)
{
	int	i;
	int	j;

	i = 0;
	exec->ray.buf = malloc(sizeof(int **) * HEIGHT);
	exec->ray.texture = malloc(sizeof(int **) * 4);
	while (i < HEIGHT)
	{
		exec->ray.buf[i] = malloc(sizeof(int *) * WIDTH + 1);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		exec->ray.texture[i] = malloc(sizeof(int *) * (64 * 64));
		i++;
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < (64 * 64))
			exec->ray.texture[i][j] = 0;
	}
}

void	load_image(t_exec *exec, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	y = -1;
	img->img = mlx_xpm_file_to_image(exec->mlx, path, &img->img_width,
			&img->img_height);
	if (!img->img)
	{
		printf("Error\nTexture Invalide\n");
		free_all(&*exec);
		exit(1);
	}
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_l, &img->endian);
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			texture[img->img_width * y + x] = img->addr[img->img_width * y + x];
	}
	mlx_destroy_image(exec->mlx, img->img);
}

void	load_texture(t_exec *exec)
{
	load_image(exec, exec->ray.texture[0], exec->ray.paths[0], &exec->img);
	load_image(exec, exec->ray.texture[1], exec->ray.paths[1], &exec->img);
	load_image(exec, exec->ray.texture[2], exec->ray.paths[2], &exec->img);
	load_image(exec, exec->ray.texture[3], exec->ray.paths[3], &exec->img);
}

void	define_texture(t_exec *exec, t_cub *cub)
{
	exec->ray.paths[0] = ft_strdup(cub->path_ea);
	exec->ray.paths[1] = ft_strdup(cub->path_no);
	exec->ray.paths[2] = ft_strdup(cub->path_we);
	exec->ray.paths[3] = ft_strdup(cub->path_so);
	free(cub->path_so);
	free(cub->path_no);
	free(cub->path_ea);
	free(cub->path_we);
	exec->ray.floor_colors[0] = cub->f[0];
	exec->ray.floor_colors[1] = cub->f[1];
	exec->ray.floor_colors[2] = cub->f[2];
	exec->ray.ceiling_colors[0] = cub->c[0];
	exec->ray.ceiling_colors[1] = cub->c[1];
	exec->ray.ceiling_colors[2] = cub->c[2];
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:37:17 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/07 11:31:50 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    check_letter(t_exec *exec)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(exec->final_map[i])
    {
        j = 0;
        while(exec->final_map[i][j])
        {
            if(exec->final_map[i][j] == 'N')
                exec->letter = 'N';
            if(exec->final_map[i][j] == 'S')
                exec->letter = 'S';
            if(exec->final_map[i][j] == 'W')
                exec->letter = 'W';
            if(exec->final_map[i][j] == 'E')
                exec->letter = 'E';
            j++;
        }
        i++;
    }
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

void    define_vector(t_exec *exec)
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
		exec->ray.texture[i] = malloc(sizeof(int *) * (64
					* 64));
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
// modif
void	load_image(t_exec *exec, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	y = -1;
	img->img = mlx_xpm_file_to_image(exec->mlx, path, &img->img_width,
			&img->img_height);
	if (!img->img)
	{
		printf("Error\nInvalid texture path\n");
	}
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->size_l,
			&img->endian);
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
	load_image(exec, exec->ray.texture[0], exec->ray.paths[0],
		&exec->img);
	load_image(exec, exec->ray.texture[1], exec->ray.paths[1],
		&exec->img);
	load_image(exec, exec->ray.texture[2], exec->ray.paths[2],
		&exec->img);
	load_image(exec, exec->ray.texture[3], exec->ray.paths[3],
		&exec->img);
}

void    ft_init(t_exec *exec)
{
    exec->mlx = mlx_init();
    if(!exec->mlx)
    {
        //free exec;
        exit(1);
    }
    check_letter(&*exec);
    view_letter(&*exec);
    define_vector(&*exec);
    //
    malloc_map(&*exec);
    exec->ray.movespeed = 0.5;
    exec->ray.rotspeed = 0.09;
	exec->window = mlx_new_window(exec->mlx, WIDTH, HEIGHT, "cub3d");
    //donner les  chemins des textures
	load_texture(&*exec);
}
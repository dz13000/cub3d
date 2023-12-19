/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:37:17 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/18 23:16:57 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    check_letter(t_exec *exec)
{
    int i;
    int j;
	int nb;

    i = 0;
    j = 0;
	nb = 0;
    while(exec->final_map[i])
    {
        j = 0;
        while(exec->final_map[i][j])
        {
            if(exec->final_map[i][j] == 'N')
			{
                exec->letter = 'N';
				nb++;
				break;
			}
            if(exec->final_map[i][j] == 'S')
			{
                exec->letter = 'S';
				nb++;
				break;
			}
            if(exec->final_map[i][j] == 'W')
			{
                exec->letter = 'W';
				nb++;
				break;
			}
            if(exec->final_map[i][j] == 'E')
			{
                exec->letter = 'E';
				nb++;
				break;
			}
            j++;
        }
		if(nb == 1)
			break;
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
void	boucle_a_caca(t_exec *exec, int x, int texNum, int texX)
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
int	set_rgb(int rgb[3])
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}
// recup rgb
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
		boucle_a_caca(&*exec, x, texnum, texx);
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
		printf("--->>>%s\n", path);
		//free
		exit(1);
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
void	define_texture(t_exec *exec, t_cub *cub)
{
	exec->ray.paths[0] = cub->path_ea; 
	exec->ray.paths[1] = cub->path_no;
	exec->ray.paths[2] = cub->path_we;
	exec->ray.paths[3] = cub->path_so;
	exec->ray.floor_colors[0] = cub->f[0];
	exec->ray.floor_colors[1] = cub->f[1];
	exec->ray.floor_colors[2] = cub->f[2];
	exec->ray.ceiling_colors[0] = cub->c[0];
	exec->ray.ceiling_colors[1] = cub->c[1];
	exec->ray.ceiling_colors[2] = cub->c[2];
}
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
	exec->ray.dirx = exec->ray.dirx * cos(exec->ray.rotspeed)
		- exec->ray.diry * sin(exec->ray.rotspeed);
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
	exec->ray.dirx = exec->ray.dirx * cos(-exec->ray.rotspeed)
		- exec->ray.diry * sin(-exec->ray.rotspeed);
	exec->ray.diry = olddirx * sin(-exec->ray.rotspeed) + exec->ray.diry
		* cos(-exec->ray.rotspeed);
	oldplanex = exec->ray.planx;
	exec->ray.planx = exec->ray.planx * cos(-exec->ray.rotspeed)
		- exec->ray.plany * sin(-exec->ray.rotspeed);
	exec->ray.plany = oldplanex * sin(-exec->ray.rotspeed)
		+ exec->ray.plany * cos(-exec->ray.rotspeed);
}


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
		//free
		exit(0);
	}
	mlx_clear_window(&*exec->mlx, &*exec->window);
	main_loop(&*exec);
	return (0);
}

int	free_all(t_exec *exec)
{
	int	i;

	i = -1;
	while (++i < 4)
		free(exec->ray.paths[i]);
	(void)exec;
	exit(1);
	return (0);
}

void    ft_init(t_exec *exec, t_cub *cub)
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
    exec->ray.re_buf = 1;
    malloc_map(&*exec);
    exec->ray.movespeed = 0.5;
    exec->ray.rotspeed = 0.09;
	exec->window = mlx_new_window(exec->mlx, WIDTH, HEIGHT, "cub3d");
    //donner les  chemins des textures
	define_texture(&*exec, &*cub);
	load_texture(&*exec);
	exec->img.img = mlx_new_image(exec->mlx, WIDTH, HEIGHT);
	exec->img.addr = (int *)mlx_get_data_addr(exec->img.img,
			&exec->img.bits_per_pixel, &exec->img.size_l,
			&exec->img.endian);
	main_loop(&*exec);
	mlx_hook(exec->window, 0, 1L << 0, &key_press, &*exec);
	mlx_hook(exec->window, 17, 0, &free_all, &*exec);
	mlx_key_hook(exec->window, &key_press, &*exec);
	mlx_loop_hook(exec->mlx, &main_loop, &*exec);
	mlx_loop(exec->mlx);
}

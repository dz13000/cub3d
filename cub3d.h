/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:22:35 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/19 04:55:41 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1

# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363
# define FORWARD_W_Z 119
# define BACK_S_S 115
# define RIGHT_D_D 100
# define LEFT_A_Q 97
# define WIDTH 1680
# define HEIGHT 680

typedef struct s_img
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		size_l;
	int		endian;
	int		img_width;
	int		img_height;
}			t_img;

typedef struct s_cub
{
	char	*map;
	char	**map2;
	char	*map_bis;
	char	**map2_bis;
	char	**maps_finish;
	char	**test;
	int		count;
	int		line_no;
	int		line_so;
	int		line_we;
	int		line_ea;
	int		line_f;
	int		line_c;
	char	*last_line;
	int		player_n;
	int		player_s;
	int		player_w;
	int		player_e;
	char	*path_we;
	char	*path_no;
	char	*path_so;
	char	*path_ea;
	int		f[3];
	int		c[3];
	int		nb_fr;
}			t_cub;

typedef struct s_ray
{
	int		**buf;
	int		re_buf;
	int		**texture;
	double	movespeed;
	double	rotspeed;
	char	*paths[4];
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planx;
	double	plany;
	double	raydirx;
	double	raydiry;
	double	camerax;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	double	perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		x;
	int		floor_colors[3];
	int		ceiling_colors[3];
}			t_ray;

typedef struct t_exec
{
	void	*mlx;
	void	*window;
	char	**final_map;
	char	letter;
	t_img	img;
	t_ray	ray;
	t_cub	cub;
}			t_exec;

char		*get_next_line(int fd);
int			ft_check(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *str);
int			cut(char *str);
char		*ft_substr(char *s, int start, int len);
int			slen(char *str);
char		**ft_split(char const *s, char c);
char		**ft_split2(char const *s, char c);
int			check_id(t_cub *cub);
int			check_before(t_cub *cub, int i, int j);
int			ft_parsing(char **argv, t_cub *cub);
char		*copy_map2(char **argv);
char		*copy_map(char **argv, t_cub *cub);
int			verif_line(char *tmp);
int			check_before(t_cub *cub, int i, int j);
int			check_id(t_cub *cub);
int			verif_line2(char *tmp);
int			check_player(t_cub *cub);
int			check_player2(t_cub *cub);
int			check_spaces(t_cub *cub);
int			check_size(t_cub *cub);
int			ft_strlen(char *str);
int			ft_char(char c);
void		grep_last_line(t_cub *cub);
int			check_char_map(t_cub *cub);
int			check_up(t_cub *cub, int i, int j);
int			check_left(t_cub *cub, int i, int j);
int			check_down(t_cub *cub, int i, int j);
int			check_right(t_cub *cub, int i, int j);
int			verif_map(t_cub *cub);
char		**split_map(char **tab);
int			check_atoi_c(char *str, t_cub *cub);
int			check_atoi_f(char *str, t_cub *cub);
long long	ft_atoi(char *str);
int			check_zero(t_cub *cub);
char		**change_map2(char **map);
void		ft_init(t_exec *exec, t_cub *cub);
int			free_all(t_exec *exec);

#endif
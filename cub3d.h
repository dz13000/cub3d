/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:22:35 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 11:22:07 by cabouzir         ###   ########.fr       */
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
char		**split_map(char **tab, t_cub *cub);
int			check_atoi_c(char *str, t_cub *cub);
int			check_atoi_f(char *str, t_cub *cub);
long long	ft_atoi(char *str);
int			check_zero(t_cub *cub);
char		**change_map2(char **map);
void		ft_init(t_exec *exec, t_cub *cub);
int			free_all(t_exec *exec);
void		all_free(t_cub *cub);
void		copy_map_utils(char *tmp, int *fd, t_cub *cub);
int			check_last_line(char *tmp, t_cub *cub);
int			ft_strlen3(char *str);
char		*ft_strdup3(char *str);
void		ft_check_id_parsing(t_cub *cub);
void		free_2(t_cub *cub);
void		free_1(t_cub *cub);
void		free_path(t_cub *cub);
void		check_f_utils(t_cub *cub, int *i, int *j);
int			check_c(t_cub *cub);
void		check_c_utils(t_cub *cub, int *i, int *j);
long long	ft_atoi(char *str);
int			check_atoi_c(char *str, t_cub *cub);
int			check_atoi_f(char *str, t_cub *cub);
int			check_space_number(char *str);
int			check_space_number2(char *str, int i);
int			ft_check_nb(char *str, int i);
void		ft_check_nb2(char *str, int i, int *nb);
int			check_number(char *str);
void		check_number2(char *str, int i, int *nb);
int			check_char_line(char *str);
int			ft_isdigit(int nb);
int			check_virgule(char *str);
int			check_we(t_cub *cub);
void		check_we2(t_cub *cub, int *i, int *j);
int			check_ea(t_cub *cub);
void		check_ea2(t_cub *cub, int *i, int *j);
int			check_so(t_cub *cub);
void		check_so2(t_cub *cub, int *i, int *j);
int			check_no(t_cub *cub);
void		check_no2(t_cub *cub, int *i, int *j);
void		grep_last_line(t_cub *cub);
void		move_down(t_exec *exec);
void		move_left(t_exec *exec);
void		move_right(t_exec *exec);
void		rotate_left(t_exec *exec);
void		rotate_right(t_exec *exec);
void		move_up(t_exec *exec);
void		define_vector(t_exec *exec);
void		malloc_map(t_exec *exec);
void		load_image(t_exec *exec, int *texture, char *path, t_img *img);
void		load_texture(t_exec *exec);
void		define_texture(t_exec *exec, t_cub *cub);
int			set_rgb(int rgb[3]);
void		ceiling_or_floor(t_exec *exec, int x, int q);
void		calc(t_exec *exec);
void		draw(t_exec *exec);
int			main_loop(t_exec *exec);
void		on_draw(t_exec *exec, int x, int texNum, int texX);
void		define_wallx(t_exec *exec, double *wallx, int *texnum, int x);
int			choose_texture(t_exec *exec, int texNum);
void		define_draw(t_exec *exec);
void		define_side(t_exec *exec);
void		define(t_ray *ray);
void		init_values(t_exec *exec, int x);
void		init_buff(t_exec *exec);
void		view_letter(t_exec *exec);
void		check_letter(t_exec *exec);
void		check_letter2(t_exec *exec, int *i, int *j, int *nb);
int			check_letter_e(t_exec *exec, int *i, int *j, int *nb);

#endif
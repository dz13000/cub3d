/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:22:35 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/09 20:22:41 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D
# define CUB_3D

# include "mlx/mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// # ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
// # endif

#define ROTATE_LEFT 65361
#define ROTATE_RIGHT 65363
#define FORWARD_W_Z 119
#define BACK_S_S 115
#define RIGHT_D_D 100
#define LEFT_A_Q 97
# define WIDTH 1680
# define HEIGHT 680

typedef struct		s_img
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int		size_l;
	int				endian;
	int		img_width;
	int		img_height;
}					t_img;

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


}			t_cub;

typedef struct	s_ray
{
	int		**buf;
	int		**texture;
	double	movespeed;
	double	rotspeed;
	char	*paths[4];
	double		posx; //position x du joueur
	double		posy; //position y du joueur
	double		dirx; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double		diry; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double		planx; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double		plany; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	double		raydirx; //calcul de direction x du rayon
	double		raydiry; //calcul de direction y du rayon
	double		camerax; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int		mapx; // coordonée x du carré dans lequel est pos
	int		mapy; // coordonnée y du carré dans lequel est pos
	double		sidedistx; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double		sidedisty; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double		deltadistx; //distance que rayon parcours entre chaque point d'intersection vertical
	double		deltadisty; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int		stepx; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int		stepy; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int		hit; // 1 si un mur a ete touche, 0 sinon
	int		side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double		perpwalldist; // distance du joueur au mur
	int		lineheight; //hauteur de la ligne a dessiner
	int		drawstart; //position de debut ou il faut dessiner
	int		drawend; //position de fin ou il faut dessiner
	int		x; //permet de parcourir tous les rayons
}					t_ray;

typedef struct t_exec
{
	void	*mlx;
	void	*window;
	char	**final_map;
	char 	letter;
	t_img	img;
	t_ray	ray;
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
int			check_atoi(char *str);
long long	ft_atoi(char *str);
int			check_zero(t_cub *cub);
char		**change_map2(char **map);
void    ft_init(t_exec *exec, t_cub *cub);

#endif
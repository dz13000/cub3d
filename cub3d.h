/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:22:35 by cabouzir          #+#    #+#             */
/*   Updated: 2023/11/27 01:30:25 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D
# define CUB_3D

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_cub
{
	char	*map;
	char	**map2;
	int		count;
    int     line_no;
    int     line_so;
    int     line_we;
    int     line_ea;
    int     line_f;
    int     line_c;
    
}			t_cub;

char		*get_next_line(int fd);
int			ft_check(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *str);
int			cut(char *str);
char		*ft_substr(char *s, int start, int len);
int			slen(char *str);
char		**ft_split(char const *s, char c);

#endif
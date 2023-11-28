/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 02:46:42 by cabouzir          #+#    #+#             */
/*   Updated: 2023/11/28 13:06:45 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	verif_line(char *tmp)
{
	int	i;

	i = 0;
	while (tmp && tmp[i])
	{
		if (tmp[i] != ' ' && tmp[i] != '\t' && tmp[i + 1] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int	check_before(t_cub *cub, int i, int j)
{
	if (j == 0)
		return (0);
	if (j == 1)
	{
		if (cub->map2[i][j - 1] != ' ' && cub->map2[i][j - 1] != '\t')
			return (1);
		else
			return (0);
	}
	if (j > 1)
		j--;
	while (j && j >= 0)
	{
		if (cub->map2[i][j] != ' ' && cub->map2[i][j] != '\t')
			return (1);
		j--;
	}
	return (0);
}

int	check_id(t_cub *cub)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (cub->map2[i])
	{
		j = 0;
		while (cub->map2[i][j])
		{
			if (cub->map2[i][j] == 'N' && cub->map2[i][j + 1] == 'O'
				&& (cub->map2[i][j + 2] == ' ' || cub->map2[i][j + 2] == '\t'))
			{
				if (check_before(&*cub, i, j) == 0 && cub->line_no == 0)
				{
					// printf("----------------->je rentre NO\n");
					cub->line_no = i;
					cub->count++;
					cub->line_no++;
					break ;
				}
			}
			else if (cub->map2[i][j] == 'S' && cub->map2[i][j + 1] == 'O'
					&& (cub->map2[i][j + 2] == ' ' || cub->map2[i][j
						+ 2] == '\t'))
			{
				if (check_before(&*cub, i, j) == 0 && cub->line_so == 0)
				{
					// printf("----------------->je rentre SO\n");
					cub->line_so = i;
					cub->count++;
					cub->line_so++;
					break ;
				}
			}
			else if (cub->map2[i][j] == 'W' && cub->map2[i][j + 1] == 'E'
					&& (cub->map2[i][j + 2] == ' ' || cub->map2[i][j
						+ 2] == '\t'))
			{
				if (check_before(&*cub, i, j) == 0 && cub->line_we == 0)
				{
					// printf("----------------->je rentre WE\n");
					cub->line_we = i;
					cub->count++;
					cub->line_we++;
					break ;
				}
			}
			else if (cub->map2[i][j] == 'E' && cub->map2[i][j + 1] == 'A'
					&& (cub->map2[i][j + 2] == ' ' || cub->map2[i][j
						+ 2] == '\t'))
			{
				if (check_before(&*cub, i, j) == 0 && cub->line_ea == 0)
				{
					// printf("----------------->je rentre EA\n");
					cub->line_ea = i;
					cub->count++;
					cub->line_ea++;
					break ;
				}
			}
			else if (cub->map2[i][j] == 'F' && (cub->map2[i][j + 1] == ' '
						|| cub->map2[i][j + 1] == '\t'))
			{
				if (check_before(&*cub, i, j) == 0 && cub->line_f == 0)
				{
					// printf("----------------->je rentre F\n");
					cub->line_no = i;
					cub->count++;
					cub->line_f++;
					break ;
				}
			}
			else if (cub->map2[i][j] == 'C' && (cub->map2[i][j + 1] == ' '
						|| cub->map2[i][j + 1] == '\t'))
			{
				if (check_before(&*cub, i, j) == 0 && cub->line_c == 0)
				{
					// printf("----------------->je rentre C\n");
					cub->count++;
					cub->line_c++;
					break ;
				}
			}
			j++;
		}
		i++;
	}
	// printf("--------------%d\n", cub->count);
	if (cub->count == 6)
	{
		printf("--------------->good\n");
		return (0);
	}
	return (1);
}
void	grep_last_line(t_cub *cub)
{
	int	i;
	int	j;

	cub->last_line = malloc(sizeof(char) * 3);
	i = 0;
	j = 0;
	while (cub->map2[i])
		i++;
	i--;
	while (cub->map[i] && (cub->map2[i][j] == '\t' || cub->map2[i][j] == ' '))
	{
		j++;
	}
	cub->last_line[0] = cub->map2[i][j];
	cub->last_line[1] = cub->map2[i][j + 1];
	cub->last_line[2] = '\0';
	printf("------%s\n", cub->last_line);
}
int	check_fisrt_wall(t_cub *cub)
{
	int	j;

	j = 0;
	while (cub->maps_finish[0][j])
	{
		if (cub->maps_finish[0][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	check_last_wall(t_cub *cub)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (cub->maps_finish[i])
		i++;
	i--;
	while (cub->maps_finish[i][j])
	{
		if (cub->maps_finish[i][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	check_wall(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	// printf("-----%s\n", cub->map2_bis[i]);
	while (cub->maps_finish[i])
	{
		j = 0;
		while (cub->maps_finish[i][j] && (cub->maps_finish[i][j] == ' '
				|| cub->maps_finish[i][j] == '\t'))
			j++;
		if (cub->maps_finish[i][j] != '1')
		{
			puts("je rentre\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_wall_end(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cub->maps_finish[i])
	{
		j = 0;
		while (cub->maps_finish[i][j])
			j++;
		j--;
		if (cub->maps_finish[i][j] != '1')
		{
			puts("je rentre2\n");
			return (1);
		}
		i++;
	}
	return (0);
}
int	ft_char(char c)
{
	if(c == '1')
		return(0);
	if(c == '0')
		return(0);
	if(c == 'N')
		return(0);
	if(c == 'S')
		return(0);
	if(c == 'E')
		return(0);
	if(c == 'W')
		return(0);
	if(c == ' ')
		return(0);
	return(1);
}

int	check_char_map(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (cub->maps_finish[i])
	{
		j = 0;
		while (cub->maps_finish[i][j])
		{
			if(ft_char(cub->maps_finish[i][j]) == 1)
				return(1);
			j++;
		}
		i++;
	}
	return(0);
}

int ft_strlen(char *str)
{
	int i;
	
	if(!str || str[0] == '\0')
		return(0);
	i = 0;
	while (str[i])
	{
		i++;
	}
	return(i);
}
int check_size(t_cub *cub)
{
	int i;

	i = 0;
	while(cub->maps_finish[i])
	{
		if(ft_strlen(cub->maps_finish[i]) < 3)
			return(1);
		i++;
	}
	return(0);
}

int	verif_map(t_cub *cub)
{
	if (check_wall(&*cub) == 1)
		return (1);
	if (check_wall_end(&*cub) == 1)
		return (1);
	if (check_fisrt_wall(&*cub) == 1)
		return (1);
	if (check_last_wall(&*cub) == 1)
		return (1);
	if (check_char_map(&*cub) == 1)
		return(1);
	if (check_size(&*cub) == 1)
		return(1);
	return (0);
}

int	verif_line2(char *tmp)
{
	int	i;

	i = 0;
	if (!tmp || tmp[0] == '\0')
		return (1);
	while (tmp && tmp[i])
	{
		if (tmp[i] != ' ' && tmp[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

char	**split_map(char **tab)
{
	int		i;
	int		j;
	int		k;
	char	**map;

	i = 0;
	j = 0;
	k = 0;
	while (tab[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (verif_line2(tab[i]) == 0)
			break ;
		i--;
	}
	while (tab[k])
	{
		if (verif_line2(tab[k]) == 0)
			break ;
		k++;
	}
	printf("----->>>%d\n", k);
	map = malloc(sizeof(char **) * ((i - k) + 1));
	// j = i;
	// i = 0;
	while (k <= i)
	{
		map[j] = ft_strdup(tab[k]);
		k++;
		j++;
	}
	map[j] = NULL;
	return (map);
}

int	ft_parsing(char **argv, t_cub *cub)
{
	// int i = 0;

	//parcing des ID
	cub->map = copy_map2(argv);
	cub->map2 = ft_split2(cub->map, '\n');
	if (check_id(&*cub) == 1)
	{
		//free tt ici;
		dprintf(2, "Pas les bons identifiants mon reuf\n");
		exit(1);
	}

	//parcing de la map
	grep_last_line(&*cub);
	cub->map_bis = copy_map(argv, &*cub);
	cub->map2_bis = ft_split(cub->map_bis, '\n');
	cub->maps_finish = split_map(cub->map2_bis);
	if (verif_map(&*cub) == 1)
	{
		//free tt ici;
		puts("IIIIIIIIVVVVVVIIII\n");
		exit(1);
	}

	// while (cub->maps_finish[i])
	// {
	// 	printf("%s\n", cub->maps_finish[i]);
	// 	i++;
	// }
	puts("GOOOOOOOOOOOD\n");

	// i = 0;
	// while(cub->map2[i])
	// {
	//     printf("%s\n", cub->map2[i]);
	//     i++;
	// }
	// while (i && i--)
	// 	free(map2[i]);
	// free(map);
	// free(map2);
	return (0);
}
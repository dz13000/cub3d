/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:11:53 by cabouzir          #+#    #+#             */
/*   Updated: 2023/11/27 01:32:38 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*copy_map(char **argv)
{
	int		fd;
	char	*map;
	char	*tmp;

	map = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = get_next_line(fd);
	while (1)
	{
		tmp = get_next_line(fd);
		map = ft_strjoin(map, tmp);
		free(tmp);
		if (tmp == NULL)
			break ;
	}
	close(fd);
	return (map);
}
int verif_line(char *tmp)
{
	int i;

	i = 0;
	while(tmp && tmp[i])
	{
		if(tmp[i] != ' ' && tmp[i] != '\t' && tmp[i + 1] != '\0')
			return(0);
		i++;
	}
	return(1);
}

char	*copy_map2(char **argv)
{
	int		fd;
	char	*map;
	char	*tmp;
	int		nb;

	map = NULL;
	nb = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = get_next_line(fd);
	while (1)
	{
		tmp = get_next_line(fd);
		if((verif_line(tmp) == 0) && (nb != 6))
		{
			nb++;
			map = ft_strjoin(map, tmp);
		}
		free(tmp);
		if (tmp == NULL)
			break ;
	}
	close(fd);
	return (map);
}

int	check_before(t_cub *cub, int i, int j)
{
	if(j == 0)
		return(0);
	if (j == 1)
	{
		if (cub->map2[i][j - 1] != ' ' && cub->map2[i][j - 1] != '\t')
			return(1);
		else
			return(0);
	}
	if (j > 1)
		j--;
	while (j && j >= 0)
	{
		if (cub->map2[i][j] != ' ' && cub->map2[i][j] != '\t')
			return(1);
		j--;
	}
	return(0);
	
}
int check_id(t_cub *cub)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (cub->map2[i])
	{
		j = 0;
		while (cub->map2[i][j])
		{
			if (cub->map2[i][j] == 'N' && cub->map2[i][j + 1] == 'O' && (cub->map2[i][j + 2] == ' ' || cub->map2[i][j + 2] ==  '\t'))
			{
				if(check_before(&*cub, i, j) == 0 && cub->line_no == 0)
				{
					// printf("----------------->je rentre NO\n");
					cub->line_no = i;
					cub->count++;
					cub->line_no++;
					break;
				}
			}
			else if (cub->map2[i][j] == 'S' && cub->map2[i][j + 1] == 'O' && (cub->map2[i][j + 2] == ' ' || cub->map2[i][j + 2] ==  '\t'))
			{
				if(check_before(&*cub, i, j) == 0 && cub->line_so == 0)
				{
					// printf("----------------->je rentre SO\n");
					cub->line_so = i;
					cub->count++;
					cub->line_so++;
					break;
				}
			}
			else if (cub->map2[i][j] == 'W' && cub->map2[i][j + 1] == 'E' && (cub->map2[i][j + 2] == ' ' || cub->map2[i][j + 2] ==  '\t'))
			{
				if(check_before(&*cub, i, j) == 0 && cub->line_we == 0)
				{
					// printf("----------------->je rentre WE\n");
					cub->line_we = i;
					cub->count++;
					cub->line_we++;
					break;
				}
			}
			else if (cub->map2[i][j] == 'E' && cub->map2[i][j + 1] == 'A' && (cub->map2[i][j + 2] == ' ' || cub->map2[i][j + 2] ==  '\t'))
			{
				if(check_before(&*cub, i, j) == 0 && cub->line_ea == 0)
				{
					// printf("----------------->je rentre EA\n");
					cub->line_ea = i;
					cub->count++;
					cub->line_ea++;
					break;
				}
			}
			else if (cub->map2[i][j] == 'F' && (cub->map2[i][j + 1] == ' ' || cub->map2[i][j + 1] ==  '\t'))
			{
				if(check_before(&*cub, i, j) == 0 && cub->line_f == 0)
				{
					// printf("----------------->je rentre F\n");
					cub->line_no = i;
					cub->count++;
					cub->line_f++;
					break;	
				}
			}
			else if (cub->map2[i][j] == 'C' && (cub->map2[i][j + 1] == ' ' || cub->map2[i][j + 1] ==  '\t'))
			{
				if(check_before(&*cub, i, j) == 0 && cub->line_c == 0)
				{
					// printf("----------------->je rentre C\n");
					cub->count++;
					cub->line_c++;
					break;
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
		return(0);
	}
	return(1);
}

int	ft_parsing(char **argv, t_cub *cub)
{
   
	int i = 0;

    cub->map = copy_map2(argv);
    cub->map2 = ft_split2(cub->map, '\n');
	if (check_id(&*cub) == 1)
	{
		//free ici;
		dprintf(2, "Pas les bons identifiants mon reuf\n");
		exit(1);
	}
	
	printf("on est bon gros---->\n");
	
	
	while(cub->map2[i])
	{
	    printf("%s\n", cub->map2[i]);
	    i++;
	}
	// while (i && i--)
	// 	free(map2[i]);
	// free(map);
	// free(map2);
    return(0);
}

int	main(int ac, char **argv, char **env)
{
	t_cub cub = {0};
	cub.count = 0;
	if (!env)
		return (1);
	if (ac != 2)
		return (printf("Pas assez d'arguments"), 1);
	if (ft_parsing(argv, &cub) == 1)
		return (1);
    return(0);
}

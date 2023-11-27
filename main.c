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
	return (map);

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
				printf("----------------->je rentre NO\n");
				cub->line_no = i;
				cub->count++;
				break;
			}
			else if (cub->map2[i][j] == 'S' && cub->map2[i][j + 1] == 'O' && (cub->map2[i][j + 2] == ' ' || cub->map2[i][j + 2] ==  '\t'))
			{
				printf("----------------->je rentre SO\n");
				cub->line_so = i;
				cub->count++;
				break;
			}
			else if (cub->map2[i][j] == 'W' && cub->map2[i][j + 1] == 'E' && (cub->map2[i][j + 2] == ' ' || cub->map2[i][j + 2] ==  '\t'))
			{
				printf("----------------->je rentre WE\n");
				cub->line_we = i;
				cub->count++;
				break;
			}
			else if (cub->map2[i][j] == 'E' && cub->map2[i][j + 1] == 'A' && (cub->map2[i][j + 2] == ' ' || cub->map2[i][j + 2] ==  '\t'))
			{
				printf("----------------->je rentre EA\n");
				cub->line_ea = i;
				cub->count++;
				break;
			}
			else if (cub->map2[i][j] == 'F' && (cub->map2[i][j + 1] == ' ' || cub->map2[i][j + 1] ==  '\t'))
			{
				printf("----------------->je rentre F\n");
				cub->line_no = i;
				cub->count++;
				break;	
			}
			else if (cub->map2[i][j] == 'C' && (cub->map2[i][j + 1] == ' ' || cub->map2[i][j + 1] ==  '\t'))
			{
				printf("----------------->je rentre C\n");
				cub->count++;
				break;
			}
			j++;			
		}
		i++;
	}
	printf("--------------%d\n", cub->count);
	if (cub->count == 6)
	{
		printf("--------------->good\n");
		return(0);
	}
	return(1);
}

int	ft_parsing(char **argv, t_cub *cub)
{
    // char *map;
    // char **map2;
	int i = 0;

    cub->map = copy_map(argv);
    cub->map2 = ft_split(cub->map, '\n');
	check_id(&*cub);
	
	
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
	t_cub cub;
	cub.count = 0;
	if (!env)
		return (1);
	if (ac != 2)
		return (printf("Pas assez d'arguments"), 1);
	if (ft_parsing(argv, &cub) == 1)
		return (1);
    return(0);
}

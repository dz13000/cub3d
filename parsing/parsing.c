/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:05:36 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/02 08:20:35 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int check_no(t_cub *cub)
{
	int i;
	int j;
	int fd;

	i = 0;
	j = 0;
	while (cub->map2[i])
	{
		j = 0;
		while(cub->map2[i][j])
		{
			if(cub->map2[i][j] == 'N' && cub->map2[i][j + 1] == 'O')
				break;
			j++;
		}
		if(cub->map2[i][j] == 'N' && cub->map2[i][j + 1] == 'O')
				break;
		i++;
	}
	j++;
	if(cub->map2[i][j + 1] != ' ' && cub->map2[i][j + 1] != '\t')
		return(1);
	j++;
	while(cub->map2[i][j] && cub->map2[i][j] != '.')
	{
		if(cub->map2[i][j] != ' ' && cub->map2[i][j] != '\t' )
		{
			printf("---->>>>%c\n", cub->map2[i][j]);
			puts("IIICCII\n");
			return(1);
		}
		j++;
	}
	printf("---->>>>%s\n", &cub->map2[i][j]);
	fd = open(&cub->map2[i][j], O_RDONLY);
	if(fd == -1)
	{
		puts("SA EXISTE PAS\n");
		return(1);
	}
	return(0);
}

int check_so(t_cub *cub)
{
	int i;
	int j;
	int fd;

	i = 0;
	j = 0;
	while (cub->map2[i])
	{
		j = 0;
		while(cub->map2[i][j])
		{
			if(cub->map2[i][j] == 'S' && cub->map2[i][j + 1] == 'O')
				break;
			j++;
		}
		if(cub->map2[i][j] == 'S' && cub->map2[i][j + 1] == 'O')
				break;
		i++;
	}
	j++;
	if(cub->map2[i][j + 1] != ' ' && cub->map2[i][j + 1] != '\t')
		return(1);
	j++;
	while(cub->map2[i][j] && cub->map2[i][j] != '.')
	{
		if(cub->map2[i][j] != ' ' && cub->map2[i][j] != '\t' )
		{
			printf("---->>>>%c\n", cub->map2[i][j]);
			puts("IIICCII\n");
			return(1);
		}
		j++;
	}
	printf("---->>>>%s\n", &cub->map2[i][j]);
	fd = open(&cub->map2[i][j], O_RDONLY);
	if(fd == -1)
	{
		puts("SA EXISTE PAS\n");
		return(1);
	}
	return(0);
}

int check_ea(t_cub *cub)
{
	int i;
	int j;
	int fd;

	i = 0;
	j = 0;
	while (cub->map2[i])
	{
		j = 0;
		while(cub->map2[i][j])
		{
			if(cub->map2[i][j] == 'E' && cub->map2[i][j + 1] == 'A')
				break;
			j++;
		}
		if(cub->map2[i][j] == 'E' && cub->map2[i][j + 1] == 'A')
				break;
		i++;
	}
	j++;
	if(cub->map2[i][j + 1] != ' ' && cub->map2[i][j + 1] != '\t')
		return(1);
	j++;
	while(cub->map2[i][j] && cub->map2[i][j] != '.')
	{
		if(cub->map2[i][j] != ' ' && cub->map2[i][j] != '\t' )
		{
			printf("---->>>>%c\n", cub->map2[i][j]);
			puts("IIICCII\n");
			return(1);
		}
		j++;
	}
	printf("---->>>>%s\n", &cub->map2[i][j]);
	fd = open(&cub->map2[i][j], O_RDONLY);
	if(fd == -1)
	{
		puts("SA EXISTE PAS\n");
		return(1);
	}
	return(0);
}

int check_we(t_cub *cub)
{
	int i;
	int j;
	int fd;

	i = 0;
	j = 0;
	while (cub->map2[i])
	{
		j = 0;
		while(cub->map2[i][j])
		{
			if(cub->map2[i][j] == 'W' && cub->map2[i][j + 1] == 'E')
				break;
			j++;
		}
		if(cub->map2[i][j] == 'W' && cub->map2[i][j + 1] == 'E')
				break;
		i++;
	}
	j++;
	if(cub->map2[i][j + 1] != ' ' && cub->map2[i][j + 1] != '\t')
		return(1);
	j++;
	while(cub->map2[i][j] && cub->map2[i][j] != '.')
	{
		if(cub->map2[i][j] != ' ' && cub->map2[i][j] != '\t' )
		{
			printf("---->>>>%c\n", cub->map2[i][j]);
			puts("IIICCII\n");
			return(1);
		}
		j++;
	}
	printf("---->>>>%s\n", &cub->map2[i][j]);
	fd = open(&cub->map2[i][j], O_RDONLY);
	if(fd == -1)
	{
		puts("SA EXISTE PAS\n");
		return(1);
	}
	return(0);
}

int check_c(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (cub->map2[i])
	{
		j = 0;
		while(cub->map2[i][j])
		{
			if(cub->map2[i][j] == 'C')
				break;
			j++;
		}
		if(cub->map2[i][j] == 'C')
				break;
		i++;
	}
	j++;
	if(cub->map2[i][j] != ' ' && cub->map2[i][j] != '\t')
		return(1);
	while(cub->map2[i][j])
	{
		if(cub->map2[i][j] != ' ' && cub->map2[i][j] != '\t' )
			break;
		j++;
	}
	printf("---->>>>%s\n", &cub->map2[i][j]);
	
	return(0);
}

int check_id2(t_cub *cub)
{
	if(check_c(&*cub) == 1)
		return(1);
	if(check_so(&*cub) == 1)
		return(1);
	if(check_no(&*cub) == 1)
		return(1);
	if(check_ea(&*cub) == 1)
		return(1);
	if(check_we(&*cub) == 1)
		return(1);
	// if(check_f(&*cub) == 1)
	// 	return(1);
	return(0);
}

int	ft_parsing(char **argv, t_cub *cub)
{
	// int i = 0;

	//parcing des ID
	cub->map = copy_map2(argv);
	cub->map2 = ft_split2(cub->map, '\n');
	
	// while(cub->map2[i])
	// {
	//     printf("%s\n", cub->map2[i]);
	//     i++;
	// }
	if (check_id(&*cub) == 1)
	{
		//free tt ici;
		dprintf(2, "Pas les bons identifiants mon reuf\n");
		exit(1);
	}
	if (check_id2(&*cub) == 1)
	{
		//free tt ici;
		dprintf(2, "Pas les bons identifiants mon reuf 2\n");
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
		puts("NNNOOOOOOOOOOOOONN\n");
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

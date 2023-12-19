/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:11:53 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/19 06:03:30 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_last_line(char *tmp, t_cub *cub)
{
	int	i;

	i = 0;
	if (!tmp || tmp[0] == '\0')
		return (0);
	while (tmp[i] && (tmp[i] == ' ' || tmp[i] == '\n'))
		i++;
	if (tmp[i] == cub->last_line[0] && tmp[i + 1] == cub->last_line[1])
		return (1);
	return (0);
}

char	*copy_map(char **argv, t_cub *cub)
{
	int		fd;
	char	*map;
	char	*tmp;

	map = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		tmp = get_next_line(fd);
		if (check_last_line(tmp, &*cub) == 1)
		{
			free(tmp);
			break ;
		}
		free(tmp);
		if (tmp == NULL)
			break ;
	}
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
	while (1)
	{
		tmp = get_next_line(fd);
		if ((verif_line(tmp) == 0) && (nb != 6))
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

void	all_free(t_cub *cub)
{
	int i;
	
	i = 0;
	free(cub->map);
	while (cub->map2[i])
		i++;
	while(i >= 0)
	free(cub->map2[i--]);
	free(cub->map2);
	// free(cub->path_so);
	// free(cub->path_no);
	// free(cub->path_ea);
	// free(cub->path_we);
	free(cub->map_bis);
	i = 0;
	while(cub->map2_bis[i])
		i++;
	while(i >= 0)
			free(cub->map2_bis[i--]);
		free(cub->map2_bis);
		i = 0;
		while(cub->maps_finish[i])
			i++;
		i--;
		while(i >= 0)
		{
			free(cub->maps_finish[i]);
			i--;
		}
		free(cub->maps_finish);
		free(cub->last_line);
}

int	main(int ac, char **argv, char **env)
{
	t_cub	cub = {0};
	t_exec  exec = {0};
	int i;
	
	i = 0;
	// cub.count = 0;
	if (!env)
		return (1);
	if (ac != 2)
		return (printf("Pas assez d'arguments"), 1);
	if (ft_parsing(argv, &cub) == 1)
		return (1);
	//tt free sauf maps_finish et les chemins;

	// exec.final_map = cub.maps_finish;
	while (cub.maps_finish[i])
		i++;
	exec.final_map = malloc(sizeof(char **) * (i + 1));
	i = 0;
	while(cub.maps_finish[i])
	{
		exec.final_map[i] = ft_strdup(cub.maps_finish[i]);
		i++;
	}
	exec.final_map[i] = NULL;
	all_free(&cub);
	
	// int i = 0;
	// while (exec.final_map[i])
	// {
	// 	printf("%s\n", exec.final_map[i]);
	// 	i++;
	// }
	ft_init(&exec, &cub);
	return (0);
}

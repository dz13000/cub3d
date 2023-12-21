/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:11:53 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 00:36:35 by cabouzir         ###   ########.fr       */
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

// void	copy_map_utils(char *tmp, int *fd, t_cub *cub)
// {
// 	while (1)
// 	{
// 		tmp = get_next_line(*fd);
// 		if (check_last_line(tmp, &*cub) == 1)
// 		{
// 			free(tmp);
// 			break ;
// 			return ;
// 		}
// 		free(tmp);
// 		if (tmp == NULL)
// 		{
// 			break ;
// 			return ;
// 		}
// 	}
// }

char	*copy_map(char **argv, t_cub *cub)
{
	int		fd;
	char	*map;
	char	*tmp;

	map = NULL;
	tmp = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(1);
	copy_map_utils(tmp, &fd, &*cub);
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
		exit(1);
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

// void	all_free(t_cub *cub)
// {
// 	int	i;

// 	i = 0;
// 	free(cub->map);
// 	while (cub->map2[i])
// 		i++;
// 	while (i >= 0)
// 		free(cub->map2[i--]);
// 	free(cub->map2);
// 	free(cub->map_bis);
// 	i = 0;
// 	while (cub->map2_bis[i])
// 		i++;
// 	while (i >= 0)
// 		free(cub->map2_bis[i--]);
// 	free(cub->map2_bis);
// 	i = 0;
// 	while (cub->maps_finish[i])
// 		i++;
// 	i--;
// 	while (i >= 0)
// 		free(cub->maps_finish[i--]);
// 	free(cub->maps_finish);
// 	free(cub->last_line);
// }

int	cheak_name_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i < 5)
		return (1);
	i--;
	if (str[i] != 'b')
		return (1);
	if (str[i - 1] != 'u')
		return (1);
	if (str[i - 2] != 'c')
		return (1);
	if (str[i - 3] != '.')
		return (1);
	return (0);
}

int	main(int ac, char **argv, char **env)
{
	static t_cub	cub = {0};
	static t_exec	exec = {0};
	int				i;

	i = 0;
	if (!env)
		return (1);
	if (ac != 2)
		return (printf("Pas le bon nombre d'arguments"), 1);
	if (cheak_name_map(argv[1]) == 1)
		return (1);
	if (ft_parsing(argv, &cub) == 1)
		return (1);
	while (cub.maps_finish[i])
		i++;
	exec.final_map = malloc(sizeof(char **) * (i + 1));
	i = -1;
	while (cub.maps_finish[++i])
		exec.final_map[i] = ft_strdup(cub.maps_finish[i]);
	exec.final_map[i] = NULL;
	all_free(&cub);
	ft_init(&exec, &cub);
	return (0);
}

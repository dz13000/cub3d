/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:11:53 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/10 01:55:58 by cabouzir         ###   ########.fr       */
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
// void ft_free_all(t_cub *cub)
// {
		
// }

// int	ft_strlen2(char *str)
// {
// 	int	i;
// 	int j;

// 	j = 0;
// 	if (!str || str[0] == '\0')
// 		return (0);
// 	i = 0;
// 	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
// 		i++;
	
// 	while (str[i])
// 	{
// 		i++;
// 		j++;
// 	}
// 	return (j);
// }

// char	*ft_strdup2(char *str)
// {
// 	int		i;
// 	int		j;
// 	char	*cpy;

// 	i = 0;
// 	j = 0;
// 	cpy = malloc(sizeof(char) * (slen(str) + 1));
// 	if (!cpy)
// 		return (NULL);
// 	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
// 		i++;
	
// 	while (str[i])
// 	{
// 		cpy[j] = str[i];
// 		i++;
// 		j++;
// 	}
// 	cpy[i] = '\0';
// 	return (cpy);
// }

// char **change_map(char **map)
// {
// 	int i;
// 	int j;
// 	int k;
// 	int nb;
// 	int max;
// 	char *tmp;
// 	char **final;

// 	max = 0;
// 	nb = 0;
// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	max = ft_strlen2(map[i]);
// 	while(map[i])
// 	{
// 		nb = ft_strlen2(map[i]);
// 		if(nb > max)
// 			max = nb;
// 		// printf("ligne n %d  nb = %d >> %s\n", i, nb, map[i]);
// 		i++;
// 	}
// 	final = malloc(sizeof(char **) * (i + 1));
// 	i = 0;
// 	nb = 0;
// 	while (map[i])
// 	{
// 		// final[j] = malloc(sizeof(char *) * (max + 1));
// 		final[j] = ft_strdup2(map[i]);
// 		k = 0;
// 		if(ft_strlen2(map[i]) < max)
// 		{
// 			nb = max - ft_strlen2(map[i]);
// 			tmp = malloc(sizeof(char *) * (nb + 1));
// 			while (k < nb)
// 			{
// 				tmp[k] = '1';
// 				k++;
// 			}
// 			tmp[k] = '\0';
// 			final[j] = ft_strjoin(final[j], tmp);
// 		}
// 		i++;
// 		j++;
// 	}
// 	final[j] = NULL;
// 	return(final);
// }

int	main(int ac, char **argv, char **env)
{
	t_cub	cub = {0};
	t_exec  exec = {0};
	
	// cub.count = 0;
	if (!env)
		return (1);
	if (ac != 2)
		return (printf("Pas assez d'arguments"), 1);
	if (ft_parsing(argv, &cub) == 1)
		return (1);
	//tt free sauf maps_finish et les chemins;

	exec.final_map = cub.maps_finish;
	int i = 0;
	while (exec.final_map[i])
	{
		printf("%s\n", exec.final_map[i]);
		i++;
	}
	ft_init(&exec, &cub);
	return (0);
}

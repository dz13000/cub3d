/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:11:53 by cabouzir          #+#    #+#             */
/*   Updated: 2023/11/28 04:59:48 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_last_line(char *tmp, t_cub *cub)
{
	int i;

	i = 0;
	if (!tmp || tmp[0] == '\0')
		return(0);
	while(tmp[i] && (tmp[i] == ' ' || tmp[i] == '\n'))
		i++;
	if(tmp[i] == cub->last_line[0] && tmp[i + 1] == cub->last_line[1])
		return(1);
	return(0);
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
		if(check_last_line(tmp, &*cub) == 1)
		{
			free(tmp);
			break;
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

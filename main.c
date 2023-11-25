/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:11:53 by cabouzir          #+#    #+#             */
/*   Updated: 2023/11/26 00:09:28 by cabouzir         ###   ########.fr       */
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

int	ft_parsing(char **argv)
{
    char *map;
    char **map2;
	int i = 0;

    map = copy_map(argv);
    map2 = ft_split(map, '\n');
	while(map2[i])
	{
	    printf("%s\n", map2[i]);
	    i++;
	}
    return(0);
}

int	main(int ac, char **argv, char **env)
{
	if (!env)
		return (1);
	if (ac != 2)
		return (1);
	if (ft_parsing(argv) == 1)
		return (1);
	// int fd;
	// char *map;
	// char *tmp;
	// map = NULL;
	// fd = open(argv[1], O_RDONLY);
	// if (fd == -1)
	//     return(1);
	// map = get_next_line(fd);
	// while (1)
	// {
	//     tmp = get_next_line(fd);
	//     map = ft_strjoin(map, tmp);
	//     free(tmp);
	//     if(tmp == NULL)
	//         break ;
	// }
    return(0);
}

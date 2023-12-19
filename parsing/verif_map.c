/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:10:11 by cabouzir  # include "../mlx/mlx/mlx.h"                                 */
/* ************************************************************************** */

#include "../cub3d.h"

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
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_strlen3(char *str)
{
	int	i;
	int j;

	j = 0;
	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	
	while (str[i])
	{
		i++;
		j++;
	}
	return (j);
}

char	*ft_strdup3(char *str)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	cpy = malloc(sizeof(char) * (slen(str) + 1));
	if (!cpy)
		return (NULL);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	
	while (str[i])
	{
		cpy[j] = str[i];
		i++;
		j++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char **change_map2(char **map)
{
	int i;
	int j;
	int k;
	int nb;
	int max;
	char *tmp;
	char **final;

	max = 0;
	nb = 0;
	i = 0;
	j = 0;
	k = 0;
	max = ft_strlen(map[i]);
	while(map[i])
	{
		nb = ft_strlen(map[i]);
		if(nb > max)
			max = nb;
		i++;
	}
	final = malloc(sizeof(char **) * (i + 1));
	i = 0;
	nb = 0;
	while (map[i])
	{
		final[j] = ft_strdup(map[i]);
		k = 0;
		if(ft_strlen(map[i]) < max)
		{
			nb = max - ft_strlen(map[i]);
			tmp = malloc(sizeof(char *) * (nb + 1));
			while (k < nb)
			{
				tmp[k] = 'v';
				k++;
			}
			tmp[k] = '\0';
			final[j] = ft_strjoin(final[j], tmp);
		}
		i++;
		j++;
	}
	final[j] = NULL;
	return(final);
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
		return (1);
	if (check_size(&*cub) == 1)
		return (1);
	if (check_spaces(&*cub) == 1)
		return (1);
	if (check_zero(&*cub) == 1)
		return (1);
	if (check_player(&*cub) == 1)
		return (1);
	return (0);
}

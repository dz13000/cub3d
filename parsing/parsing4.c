/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 08:40:19 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 08:44:52 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_we(t_cub *cub)
{
	int	i;
	int	j;
	int	fd;

	i = 0;
	j = 0;
	check_we2(&*cub, &i, &j);
	if (cub->map2[i][j + 1] != ' ' && cub->map2[i][j + 1] != '\t')
		return (1);
	j++;
	while (cub->map2[i][j] && cub->map2[i][j] != '.')
	{
		if (cub->map2[i][j] != ' ' && cub->map2[i][j] != '\t')
			return (1);
		j++;
	}
	fd = open(&cub->map2[i][j], O_RDONLY);
	if (fd == -1)
	{
		cub->nb_fr = 3;
		return (1);
	}
	cub->path_we = ft_strdup(&cub->map2[i][j]);
	close(fd);
	return (0);
}

int	check_virgule(char *str)
{
	int	i;
	int	vir;

	i = 0;
	vir = 0;
	while (str[i])
	{
		if (str[i] == ',')
			vir++;
		i++;
	}
	if (vir != 2)
		return (1);
	return (0);
}

int	ft_isdigit(int nb)
{
	if (nb >= 48 && nb <= 57)
		return (1);
	return (0);
}

int	check_char_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] != ' ') && (str[i] != ',') && (ft_isdigit(str[i]) == 0))
			return (1);
		i++;
	}
	return (0);
}

void	check_number2(char *str, int i, int *nb)
{
	while (str[i] && str[i] != ',')
	{
		if (ft_isdigit(str[i]) == 1 && *nb == 1)
			*nb += 1;
		i++;
	}
	i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
		{
			*nb += 1;
			break ;
		}
		i++;
	}
}

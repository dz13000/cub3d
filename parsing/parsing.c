/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:05:36 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 06:25:22 by cabouzir         ###   ########.fr       */
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
}

int	check_no(t_cub *cub)
{
	int	i;
	int	j;
	int	fd;

	i = 0;
	j = 0;
	while (cub->map2[i])
	{
		j = 0;
		while (cub->map2[i][j])
		{
			if (cub->map2[i][j] == 'N' && cub->map2[i][j + 1] == 'O')
				break ;
			j++;
		}
		if (cub->map2[i][j] == 'N' && cub->map2[i][j + 1] == 'O')
			break ;
		i++;
	}
	j++;
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
		cub->nb_fr = 1;
		return (1);
	}
	cub->path_no = ft_strdup(&cub->map2[i][j]);
	close(fd);
	return (0);
}

int	check_so(t_cub *cub)
{
	int	i;
	int	j;
	int	fd;

	i = 0;
	j = 0;
	while (cub->map2[i])
	{
		j = 0;
		while (cub->map2[i][j])
		{
			if (cub->map2[i][j] == 'S' && cub->map2[i][j + 1] == 'O')
				break ;
			j++;
		}
		if (cub->map2[i][j] == 'S' && cub->map2[i][j + 1] == 'O')
			break ;
		i++;
	}
	j++;
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
		return (1);
	cub->path_so = ft_strdup(&cub->map2[i][j]);
	close(fd);
	return (0);
}

int	check_ea(t_cub *cub)
{
	int	i;
	int	j;
	int	fd;

	i = 0;
	j = 0;
	while (cub->map2[i])
	{
		j = 0;
		while (cub->map2[i][j])
		{
			if (cub->map2[i][j] == 'E' && cub->map2[i][j + 1] == 'A')
				break ;
			j++;
		}
		if (cub->map2[i][j] == 'E' && cub->map2[i][j + 1] == 'A')
			break ;
		i++;
	}
	j++;
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
		cub->nb_fr = 2;
		return (1);
	}
	cub->path_ea = ft_strdup(&cub->map2[i][j]);
	close(fd);
	return (0);
}

int	check_we(t_cub *cub)
{
	int	i;
	int	j;
	int	fd;

	i = 0;
	j = 0;
	while (cub->map2[i])
	{
		j = 0;
		while (cub->map2[i][j])
		{
			if (cub->map2[i][j] == 'W' && cub->map2[i][j + 1] == 'E')
				break ;
			j++;
		}
		if (cub->map2[i][j] == 'W' && cub->map2[i][j + 1] == 'E')
			break ;
		i++;
	}
	j++;
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

int	check_number(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] && str[i] != ',')
	{
		if (ft_isdigit(str[i]) == 1 && nb == 0)
			nb++;
		i++;
	}
	i++;
	check_number2(str, i, &nb);
	if (nb != 3)
		return (1);
	return (0);
}

void	ft_check_nb2(char *str, int i, int *nb)
{
	while (str[i] && str[i] != ',')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			*nb += 1;
			break ;
		}
		i++;
	}
}

int	ft_check_nb(char *str, int i)
{
	int	i2;
	int	nb;

	nb = 0;
	i2 = i;
	ft_check_nb2(str, i, &nb);
	i = i2;
	while (i >= 0 && str[i] != ',')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			nb++;
			break ;
		}
		i--;
	}
	if (nb > 1)
		return (1);
	return (0);
}

int	check_space_number2(char *str, int i)
{
	while (str[i] && str[i] != ',')
	{
		if (str[i] == ' ')
		{
			if (ft_check_nb(str, i) == 1)
				return (1);
		}
		i++;
	}
	while (str[i])
	{
		if (str[i] == ' ')
		{
			if (ft_check_nb(str, i) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_space_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ',')
	{
		if (str[i] == ' ')
		{
			if (ft_check_nb(str, i) == 1)
				return (1);
		}
		i++;
	}
	if (check_space_number2(str, i) == 1)
		return (1);
	return (0);
}
void	check_c_utils(t_cub *cub, int *i, int *j)
{
	while (cub->map2[*i])
	{
		*j = 0;
		while (cub->map2[*i][*j])
		{
			if (cub->map2[*i][*j] == 'C')
				break ;
			*j += 1;
		}
		if (cub->map2[*i][*j] == 'C')
			break ;
		*i += 1;
	}
	*j += 1;
}

int	check_c(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	check_c_utils(&*cub, &i, &j);
	if (cub->map2[i][j] != ' ' && cub->map2[i][j] != '\t')
		return (1);
	while (cub->map2[i][j])
	{
		if (cub->map2[i][j] != ' ' && cub->map2[i][j] != '\t')
			break ;
		j++;
	}
	if (check_virgule(&cub->map2[i][j]) == 1)
		return (1);
	if (check_char_line(&cub->map2[i][j]) == 1)
		return (1);
	if (check_number(&cub->map2[i][j]) == 1)
		return (1);
	if (check_space_number(&cub->map2[i][j]) == 1)
		return (1);
	if (check_atoi_c(&cub->map2[i][j], &*cub) == 1)
		return (1);
	return (0);
}

long long	ft_atoi(char *str)
{
	int			i;
	long long	sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	check_atoi_c(char *str, t_cub *cub)
{
	long long	nb;
	int			i;

	i = 0;
	nb = ft_atoi(str);
	cub->c[0] = (int)nb;
	if (nb > 255)
		return (1);
	while ((str[i]) && str[i] != ',')
		i++;
	i++;
	nb = 0;
	nb = ft_atoi(&str[i]);
	cub->c[1] = (int)nb;
	if (nb > 255)
		return (1);
	while ((str[i]) && str[i] != ',')
		i++;
	i++;
	nb = 0;
	nb = ft_atoi(&str[i]);
	cub->c[2] = (int)nb;
	if (nb > 255)
		return (1);
	return (0);
}

int	check_atoi_f(char *str, t_cub *cub)
{
	long long	nb;
	int			i;

	i = 0;
	nb = ft_atoi(str);
	cub->f[0] = (int)nb;
	if (nb > 255)
		return (1);
	while ((str[i]) && str[i] != ',')
		i++;
	i++;
	nb = 0;
	nb = ft_atoi(&str[i]);
	cub->f[1] = (int)nb;
	if (nb > 255)
		return (1);
	while ((str[i]) && str[i] != ',')
		i++;
	i++;
	nb = 0;
	nb = ft_atoi(&str[i]);
	cub->f[2] = (int)nb;
	if (nb > 255)
		return (1);
	return (0);
}

void	check_f_utils(t_cub *cub, int *i, int *j)
{
	while (cub->map2[*i])
	{
		*j = 0;
		while (cub->map2[*i][*j])
		{
			if (cub->map2[*i][*j] == 'F')
				break ;
			*j += 1;
		}
		if (cub->map2[*i][*j] == 'F')
			break ;
		*i += 1;
	}
	*j += 1;
}

int	check_f(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	check_f_utils(&*cub, &i, &j);
	if (cub->map2[i][j] != ' ' && cub->map2[i][j] != '\t')
		return (1);
	while (cub->map2[i][j])
	{
		if (cub->map2[i][j] != ' ' && cub->map2[i][j] != '\t')
			break ;
		j++;
	}
	if (check_virgule(&cub->map2[i][j]) == 1)
		return (1);
	if (check_char_line(&cub->map2[i][j]) == 1)
		return (1);
	if (check_number(&cub->map2[i][j]) == 1)
		return (1);
	if (check_space_number(&cub->map2[i][j]) == 1)
		return (1);
	if (check_atoi_f(&cub->map2[i][j], &*cub) == 1)
		return (1);
	return (0);
}

int	check_id2(t_cub *cub)
{
	if (check_f(&*cub) == 1)
		return (1);
	if (check_c(&*cub) == 1)
		return (1);
	if (check_so(&*cub) == 1)
		return (1);
	if (check_no(&*cub) == 1)
		return (1);
	if (check_ea(&*cub) == 1)
		return (1);
	if (check_we(&*cub) == 1)
		return (1);
	return (0);
}

void	free_1(t_cub *cub)
{
	int	i;

	i = 0;
	free(cub->map);
	while (cub->map2[i])
		i++;
	while (i >= 0)
		free(cub->map2[i--]);
	free(cub->map2);
	if (cub->nb_fr == 1)
		free(cub->path_so);
	if (cub->nb_fr == 2)
	{
		free(cub->path_so);
		free(cub->path_no);
	}
	if (cub->nb_fr == 3)
	{
		free(cub->path_so);
		free(cub->path_no);
		free(cub->path_ea);
	}
}

void	free_2(t_cub *cub)
{
	int	i;

	i = 0;
	free(cub->map);
	while (cub->map2[i])
		i++;
	while (i >= 0)
		free(cub->map2[i--]);
	free(cub->map2);
	free(cub->path_so);
	free(cub->path_no);
	free(cub->path_ea);
	free(cub->path_we);
	free(cub->map_bis);
	i = 0;
	while (cub->map2_bis[i])
		i++;
	while (i >= 0)
		free(cub->map2_bis[i--]);
	free(cub->map2_bis);
	i = 0;
	while (cub->maps_finish[i])
		i++;
	while (i >= 0)
		free(cub->maps_finish[i--]);
	free(cub->maps_finish);
	free(cub->last_line);
}

void	ft_check_id_parsing(t_cub *cub)
{
	int	i;

	i = 0;
	if (check_id(&*cub) == 1)
	{
		free(cub->map);
		i = 0;
		while (cub->map2[i])
			i++;
		while (i >= 0)
			free(cub->map2[i--]);
		free(cub->map2);
		dprintf(2, "Pas les bons identifiants mon reuf\n");
		exit(1);
	}
	if (check_id2(&*cub) == 1)
	{
		free_1(&*cub);
		dprintf(2, "Pas les bons identifiants mon reuf 2\n");
		exit(1);
	}
}

int	ft_parsing(char **argv, t_cub *cub)
{
	cub->map = copy_map2(argv);
	cub->map2 = ft_split2(cub->map, '\n');
	ft_check_id_parsing(&*cub);
	grep_last_line(&*cub);
	cub->map_bis = copy_map(argv, &*cub);
	cub->map2_bis = ft_split(cub->map_bis, '\n');
	cub->maps_finish = split_map(cub->map2_bis);
	if (verif_map(&*cub) == 1)
	{
		free_2(&*cub);
		exit(1);
	}
	return (0);
}

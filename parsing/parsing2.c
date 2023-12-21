/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 08:24:51 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 08:27:36 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

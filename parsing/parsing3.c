/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 08:36:27 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 08:46:00 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

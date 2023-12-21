/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:27:14 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/21 11:30:58 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_letter_e(t_exec *exec, int *i, int *j, int *nb)
{
	if (exec->final_map[*i][*j] == 'E')
	{
		exec->letter = 'E';
		*nb += 1;
		return (1);
	}
	return (0);
}

void	check_letter2(t_exec *exec, int *i, int *j, int *nb)
{
	while (exec->final_map[*i][*j])
	{
		if (exec->final_map[*i][*j] == 'N')
		{
			exec->letter = 'N';
			*nb += 1;
			break ;
		}
		if (exec->final_map[*i][*j] == 'S')
		{
			exec->letter = 'S';
			*nb += 1;
			break ;
		}
		if (exec->final_map[*i][*j] == 'W')
		{
			exec->letter = 'W';
			*nb += 1;
			break ;
		}
		if (check_letter_e(&*exec, i, j, nb) == 1)
			break ;
		*j += 1;
	}
}

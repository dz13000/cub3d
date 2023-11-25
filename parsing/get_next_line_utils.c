/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:32:57 by cabouzir          #+#    #+#             */
/*   Updated: 2023/11/25 21:19:26 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	cpy = malloc(sizeof(char) * ((slen(s1) + slen(s2)) + 1));
	if (!cpy)
		return (NULL);
	while (s1 && s1[i])
		cpy[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		cpy[j++] = s2[i++];
	cpy[j] = '\0';
	free(s1);
	return (cpy);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = malloc(sizeof(char) * (slen(str) + 1));
	if (!cpy)
		return (NULL);
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int	cut(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

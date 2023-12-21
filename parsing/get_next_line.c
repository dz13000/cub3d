/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:47:29 by cabouzir          #+#    #+#             */
/*   Updated: 2023/12/20 03:03:38 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*mem;
	int		i;

	if (!s[0])
		return (NULL);
	if (!s)
		return (NULL);
	i = slen(s);
	if (len > i)
		len = i;
	if (start > i)
		len = 0;
	mem = malloc(sizeof(char) * (len + 1));
	if (!mem)
		return (NULL);
	i = 0;
	while (i < len)
	{
		mem[i] = s[start + i];
		++i;
	}
	mem[i] = 0;
	return (mem);
}

char	*get_next_line(int fd)
{
	static char	*position;
	char		*buffer;
	char		*line;
	ssize_t		i;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 1024)
		return (NULL);
	i = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_check(position) && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (free(buffer), NULL);
		buffer[i] = '\0';
		tmp = position;
		position = ft_strjoin(tmp, buffer);
	}
	line = ft_substr(position, 0, cut(position) + 1);
	tmp = position;
	position = ft_substr(tmp, cut(tmp) + 1, (slen(tmp) - (cut(tmp) + 1)));
	return (free(tmp), free(buffer), line);
}

int	slen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

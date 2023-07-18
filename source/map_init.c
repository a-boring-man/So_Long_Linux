/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 10:07:31 by jrinna            #+#    #+#             */
/*   Updated: 2023/07/18 10:25:21 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static long	ft_strlen_g(const char *s, int mode)
{
	long	i;

	i = 0;
	if (!s)
		return (0);
	if (!mode)
	{
		while (s[i])
			i++;
		return (i);
	}
	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (i);
	return (-1);
}

static char	*ft_strjoin_g(char *s1, char *s2, int mode, long i)
{
	char	*new_s;
	long	j;

	new_s = malloc(ft_strlen_g(s1, 0) + ft_strlen_g(s2, mode) + 1 + mode / 10);
	if (!new_s)
		return (NULL);
	j = -1;
	if (s1)
		while (s1[++j])
			new_s[j] = s1[j];
	else
		j = 0;
	while (s2[++i] != mode)
	{
		new_s[j + i] = s2[i];
		s2[i] = '\0';
	}
	s2[i] = 0;
	new_s[j + i++] = mode;
	if (mode)
		new_s[j + i] = '\0';
	if (s1)
		free(s1);
	return (new_s);
}

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][43] = {{0}};
	char		*line;
	long		read_return_value;
	long		i;

	i = 0;
	line = NULL;
	while (fd >= 0 && fd < FOPEN_MAX && !buff[fd][i] && i < 42)
		i++;
	if (fd >= 0 && i != 42 && ft_strlen_g(buff[fd] + i, 1) == -1)
		line = ft_strjoin_g(line, buff[fd] + i, 0, -1);
	else if (fd >= 0 && fd < FOPEN_MAX && i != 42)
		return (ft_strjoin_g(line, buff[fd] + i, 10, -1));
	read_return_value = read(fd, buff[fd], 42);
	if (fd >= 0 && fd < FOPEN_MAX)
		buff[fd][read_return_value] = '\0';
	while (fd >= 0 && fd < FOPEN_MAX && read_return_value > 0)
	{
		if (ft_strlen_g(buff[fd], 1) == -1)
			line = ft_strjoin_g(line, buff[fd], 0, -1);
		else
			return (ft_strjoin_g(line, buff[fd], 10, -1));
		read_return_value = read(fd, buff[fd], 42);
	}
	return (line);
}

char	*ft_get_file(int fd)
{
	char	*line;
	char	*next_line;
	int		i;

	i = -1;
	line = NULL;
	next_line = get_next_line(fd);
	while (next_line)
	{
		line = ft_strjoin_f(line, next_line);
		free(next_line);
		next_line = get_next_line(fd);
	}
	return (line);
}

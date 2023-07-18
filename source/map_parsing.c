/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 10:07:38 by jrinna            #+#    #+#             */
/*   Updated: 2022/02/02 14:05:19 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_name(char *path, t_vars *ref)
{
	int	len;

	len = ft_strlen_s(path);
	if (len > 3)
	{
		if (path[len - 1] != 'r' || path[len - 2] != 'e' || path[len - 3]
			!= 'b' || path[len - 4] != '.')
			ft_error(8);
	}
}

static int	ft_map_error_checker(t_vars *ref, int i, int j)
{
	if ((i == 0 || j == ref->map.size.x - 1) && ref->map.tab[i][j] != '1')
		ft_error(3);
	else if (ref->map.tab[i][j] != 'E' && ref->map.tab[i][j] != '0' &&
		ref->map.tab[i][j] != 'P' && ref->map.tab[i][j] !=
		'C' && ref->map.tab[i][j] != '1')
		ft_error(5);
	if (ref->map.tab[i][j] == 'E')
		ref->map.counter.e_counter++;
	if (ref->map.tab[i][j] == 'P')
	{
		ref->img.playerpos.x = j * SS_X;
		ref->img.playerpos.y = i * SS_Y;
		ref->map.counter.p_counter++;
	}
	if (ref->map.tab[i][j] == 'C')
		ref->map.counter.c_counter++;
	return (0);
}

int	ft_map_parsing(t_vars *ref, int i, int j)
{
	while (ref->map.tab[++i])
	{
		if (ref->map.tab[i][0] != '1')
			ft_error(3);
	}
	ref->map.size.y = i--;
	while (ref->map.tab[i][++j])
	{
		if (ref->map.tab[i][j] != '1')
			ft_error(3);
	}
	ref->map.size.x = j;
	while (--i > -1)
	{
		j = 0;
		while (ref->map.tab[i][++j])
			if (ft_map_error_checker(ref, i, j))
				return (0);
		if (j != ref->map.size.x)
			ft_error(6);
	}
	if (ref->map.counter.c_counter < 1 || ref->map.counter.p_counter < 1
		|| ref->map.counter.e_counter < 1)
		ft_error(7);
	return (1);
}

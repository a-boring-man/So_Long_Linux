/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:17:05 by jrinna            #+#    #+#             */
/*   Updated: 2023/07/18 11:44:56 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_move_right(t_vars *ref)
{
	if (ref->map.tab[ref->img.playerpos.y / SS_Y]
		[(ref->img.playerpos.x / SS_X) + 1] != '1')
		ref->img.playerpos.x += SS_X;
	if (ref->map.tab[ref->img.playerpos.y / SS_Y]
		[(ref->img.playerpos.x / SS_X)] == 'C')
	{
		ref->map.counter.c_counter--;
		if (ref->map.counter.c_counter == 0)
			ref->img.exit = mlx_xpm_file_to_image(ref->mlx,
					"./sprite/door_open.xpm", &ref->img.size.x,
					&ref->img.size.y);
		ref->map.tab[ref->img.playerpos.y / SS_Y]
		[(ref->img.playerpos.x / SS_X)] = '0';
	}
	ref->player_move_count++;
	if (ref->map.tab[ref->img.playerpos.y / SS_Y][(ref->img.playerpos.x
			/ SS_X)] == 'E' && ref->map.counter.c_counter == 0)
		ft_end(ref);
}

static void	ft_move_left(t_vars *ref)
{
	if (ref->map.tab[ref->img.playerpos.y / SS_Y]
		[(ref->img.playerpos.x / SS_X) - 1] != '1')
		ref->img.playerpos.x -= SS_X;
	if (ref->map.tab[ref->img.playerpos.y / SS_Y]
		[(ref->img.playerpos.x / SS_X)] == 'C')
	{
		ref->map.counter.c_counter--;
		if (ref->map.counter.c_counter == 0)
			ref->img.exit = mlx_xpm_file_to_image(ref->mlx,
					"./sprite/door_open.xpm", &ref->img.size.x,
					&ref->img.size.y);
		ref->map.tab[ref->img.playerpos.y / SS_Y]
		[(ref->img.playerpos.x / SS_X)] = '0';
	}
	ref->player_move_count++;
	if (ref->map.tab[ref->img.playerpos.y / SS_Y][(ref->img.playerpos.x
			/ SS_X)] == 'E' && ref->map.counter.c_counter == 0)
		ft_end(ref);
}

static void	ft_move_down(t_vars *ref)
{
	if (ref->map.tab[(ref->img.playerpos.y / SS_Y) + 1]
		[ref->img.playerpos.x / SS_X] != '1')
		ref->img.playerpos.y += SS_Y;
	if (ref->map.tab[ref->img.playerpos.y / SS_Y]
		[(ref->img.playerpos.x / SS_X)] == 'C')
	{
		ref->map.counter.c_counter--;
		if (ref->map.counter.c_counter == 0)
			ref->img.exit = mlx_xpm_file_to_image(ref->mlx,
					"./sprite/door_open.xpm", &ref->img.size.x,
					&ref->img.size.y);
		ref->map.tab[ref->img.playerpos.y / SS_Y]
		[(ref->img.playerpos.x / SS_X)] = '0';
	}
	ref->player_move_count++;
	if (ref->map.tab[ref->img.playerpos.y / SS_Y][(ref->img.playerpos.x
			/ SS_X)] == 'E' && ref->map.counter.c_counter == 0)
		ft_end(ref);
}

static void	ft_move_up(t_vars *ref)
{
	if (ref->map.tab[(ref->img.playerpos.y / SS_Y) - 1]
		[ref->img.playerpos.x / SS_X] != '1')
		ref->img.playerpos.y -= SS_Y;
	if (ref->map.tab[ref->img.playerpos.y / SS_Y]
		[(ref->img.playerpos.x / SS_X)] == 'C')
	{
		ref->map.counter.c_counter--;
		if (ref->map.counter.c_counter == 0)
			ref->img.exit = mlx_xpm_file_to_image(ref->mlx,
					"./sprite/door_open.xpm", &ref->img.size.x,
					&ref->img.size.y);
		ref->map.tab[ref->img.playerpos.y / SS_Y]
		[(ref->img.playerpos.x / SS_X)] = '0';
	}
	ref->player_move_count++;
	if (ref->map.tab[ref->img.playerpos.y / SS_Y][(ref->img.playerpos.x
			/ SS_X)] == 'E' && ref->map.counter.c_counter == 0)
		ft_end(ref);
}

int	ft_input(int key, void *para)
{
	t_vars	*ref;

	ref = (t_vars *)para;
	mlx_clear_window(ref->mlx, ref->win.ptr);
	if (key == K_D)
		ft_move_right(ref);
	if (key == K_A)
		ft_move_left(ref);
	if (key == K_S)
		ft_move_down(ref);
	if (key == K_W)
		ft_move_up(ref);
	if (key == K_ESC)
		exit (0);
	ft_image_init(ref);
	printf("number of move-> %d\n", ref->player_move_count);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 10:07:53 by jrinna            #+#    #+#             */
/*   Updated: 2023/07/18 11:45:07 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_create_image(t_vars *ref)
{
	ref->img.player = mlx_xpm_file_to_image(ref->mlx, "./sprite/player.xpm",
			&ref->img.size.x, &ref->img.size.y);
	ref->img.ground = mlx_xpm_file_to_image(ref->mlx, "./sprite/dark_soil.xpm",
			&ref->img.size.x, &ref->img.size.y);
	ref->img.wall = mlx_xpm_file_to_image(ref->mlx, "./sprite/stone2.xpm",
			&ref->img.size.x, &ref->img.size.y);
	ref->img.collectible = mlx_xpm_file_to_image(ref->mlx,
			"./sprite/adventurer.xpm", &ref->img.size.x, &ref->img.size.y);
	ref->img.exit = mlx_xpm_file_to_image(ref->mlx, "./sprite/door_closed.xpm",
			&ref->img.size.x, &ref->img.size.y);
}

void	ft_construct_image(t_vars *ref, int i, int j)
{
	mlx_put_image_to_window(ref->mlx, ref->win.ptr, ref->img.ground,
		ref->img_pos.x, ref->img_pos.y);
	if (ref->map.tab[i][j] == '1')
		mlx_put_image_to_window(ref->mlx, ref->win.ptr, ref->img.wall,
			ref->img_pos.x, ref->img_pos.y);
	if (ref->map.tab[i][j] == 'C')
		mlx_put_image_to_window(ref->mlx, ref->win.ptr,
			ref->img.collectible, ref->img_pos.x, ref->img_pos.y);
	if (ref->map.tab[i][j] == 'E')
		mlx_put_image_to_window(ref->mlx, ref->win.ptr, ref->img.exit,
			ref->img_pos.x, ref->img_pos.y);
	mlx_put_image_to_window(ref->mlx, ref->win.ptr, ref->img.player,
		ref->img.playerpos.x, ref->img.playerpos.y);
}

void	ft_image_init(t_vars *ref)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ref->map.size.y)
	{
		j = -1;
		while (++j < ref->map.size.x)
		{
			ref->img_pos.x = j * SS_X;
			ref->img_pos.y = i * SS_Y;
			ft_construct_image(ref, i, j);
		}
	}
}

static void	ft_map_init(char *path, t_vars *ref)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	i = -1;
	ft_check_name(path, ref);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error(2);
	ref->map.counter.c_counter = 0;
	ref->map.counter.e_counter = 0;
	ref->map.counter.p_counter = 0;
	ref->player_move_count = 0;
	line = ft_get_file(fd);
	ref->map.tab = ft_split(line, '\n');
	free(line);
	if (!ft_map_parsing(ref, -1, 0))
		ft_error(4);
	ref->win.size.x = ref->map.size.x * SS_X;
	ref->win.size.y = ref->map.size.y * SS_Y;
	ft_create_image(ref);
	close (fd);
}

int	main(int ac, char **av)
{
	t_vars	ref;

	if (ac != 2)
		ft_error(1);
	ref.mlx = mlx_init();
	ft_map_init(av[1], &ref);
	ref.win.ptr = mlx_new_window(ref.mlx, ref.win.size.x,
			ref.win.size.y, "adventurer's misadventure");
	ft_image_init(&ref);
	mlx_hook(ref.win.ptr, 2, 1L<<0, ft_input, &ref);
	mlx_hook(ref.win.ptr, 17, 1L<<0, please_stop, &ref);
	mlx_loop(ref.mlx);
}

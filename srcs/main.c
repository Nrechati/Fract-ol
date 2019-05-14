/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 08:52:20 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/13 15:46:12 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
int				key_hook(int key, t_map *map)
{
	if (key == 53)
		ft_close(map);
	if (key == 69 || key == 24 || key == 78 || key == 27)
		ft_zoom(map, key);
	if (key == 124 || key == 126 || key == 123 || key == 125)
		ft_alt(map, key);
	if (key == 13 || key == 0 || key == 1 || key == 2)
		ft_move(map, key);
	if (key == 36)
		ft_proj(map);
	if (key == 49)
		ft_color(map);
	if (key == 12 || key == 14)
		ft_rotate(map, key);
	return (0);
}
*/
static int		fractol_init(t_mlx *mlx, t_map *map, char **av)
{
	(void)av;
	(void)map;
	init_mlx(mlx);
	return (1);
}

int				main(int ac, char **av)
{
	t_mlx	mlx;
	t_map	map;

	if (ac != 2)
	{
		ft_putendl(USAGE);
		return (0);
	}
	fractol_init(&mlx, &map, av);
	draw_fractol(&mlx, &map, 1, av);
//	mlx_hook(mlx.win, KEYPRESS, KEYPRESSMASK, &key_hook, &map);
	mlx_loop(mlx.ptr);
	return (0);
}

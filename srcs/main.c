/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 08:52:20 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/14 11:39:06 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		key_hook(int key, t_mlx *mlx)
{
	if (key == 53)
		ft_close(mlx);
	if (key == 69 || key == 24 || key == 78 || key == 27)
		ft_zoom(mlx, key);
	if (key == 47 || key == 43)
		ft_iterate(mlx,key);
	if (key == 0 || key == 1 || key == 2 || key == 13
			|| key == 123 || key == 124 || key == 125 || key == 126)
		ft_move(mlx, key);
	return (SUCCESS);
}

static void		init_mlx(t_mlx *mlx)
{
	mlx->h = 720;
	mlx->w = 1280;
	mlx->c = BLUE;
	mlx->x_pad = - 0.5;
	mlx->y_pad = 0;
	mlx->zoom = 1;
	mlx->iter = 100;
	mlx->img = NULL;
	mlx->img_str = NULL;
	mlx->img_size = mlx->w * mlx->h;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, mlx->w, mlx->h, "Fractol");
}

static int		input(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Usage: ./Fractol [fractal_name]\n");
		ft_printf("Possible choices:\n\t. -h [help]\n\t. Mandelbrot\n");
		return (FAILURE);
	}
	if (ft_strequ(av[1], "-h") == TRUE)
	{
		ft_printf("Help: ./Fractol [fractal_name]\n");
		ft_printf("Possible choices:\n\t. -h [help]\n\t. Mandelbrot\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int				main(int ac, char **av)
{
	t_mlx	mlx;

	if (input(ac, av) == FAILURE)
		return (FAILURE);
	init_mlx(&mlx);
	draw_fractol(&mlx, FALSE);
	mlx_hook(mlx.win, KEYPRESS, KEYPRESSMASK, &key_hook, &mlx);
	mlx_loop(mlx.ptr);
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 08:52:20 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/17 09:54:11 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		key_hook(int key, t_mlx *mlx)
{
	if (key == 53)
		ft_close(mlx);
	if (key == 257)
		ft_freeze_julia(mlx);
	if (key == 15)
		ft_reset(mlx);
	if (key == 48)
		ft_next(mlx);
	if (key == 49)
		ft_color(mlx);
	if (key == 259)
		ft_menu_color(mlx);
	if (key == 261)
		ft_ret_color(mlx);
	if (key == 256)
		ft_info(mlx);
	if (key == 69 || key == 24 || key == 78 || key == 27)
		ft_zoom(mlx, key);
	if (key == 47 || key == 43)
		ft_iterate(mlx,key);
	if (key == 0 || key == 1 || key == 2 || key == 13
			|| key == 123 || key == 124 || key == 125 || key == 126)
		ft_move(mlx, key);
	return (SUCCESS);
}

static int		choose_fractal(t_mlx *mlx, char **av)
{
	char *fractal;

	fractal = ft_strdup(av[1]);
	ft_strupper(fractal);
	if (ft_strequ((fractal), "MANDELBROT"))
	{
		mlx->fractal = is_mandelbrot;
		mlx->frac_nbr = MANDELBROT;
		ft_strdel(&fractal);
		return (SUCCESS);
	}
	else if (ft_strequ((fractal), "JULIA"))
	{
		mlx->fractal = is_julia;
		mlx->frac_nbr = JULIA;
		ft_strdel(&fractal);
		return (SUCCESS);
	}
	else if (ft_strequ((fractal), "BURNINGSHIP"))
	{
		mlx->fractal = is_burning_ship;
		mlx->frac_nbr = BURNING_SH;
		ft_strdel(&fractal);
		return (SUCCESS);
	}
	ft_strdel(&fractal);
	ft_printf("\x1b[41m%s \x1b[0m", av[1]);
	usage("is not a valid input");
	return(FAILURE);
}

static int		input(t_mlx *mlx, int ac, char **av)
{
	if (ac != 2)
		return (usage("Wrong Number of Arguments"));
	if (ft_strequ(av[1], "-h") == TRUE)
		return (usage("HELP:"));
	return (choose_fractal(mlx, av));
}

int				main(int ac, char **av)
{
	t_mlx	mlx;

	mlx.fractal = NULL;
	if (input(&mlx, ac, av) == FAILURE)
		return (FAILURE);
	init_mlx(&mlx);
	init_scope(&mlx);
	draw_fractol(&mlx, FALSE, mlx.fractal);
	mlx_hook(mlx.win, KEYPRESS, KEYPRESSMASK, &key_hook, &mlx);
	mlx_hook(mlx.win, MOTIONNOTIFY, MOTIONNOTIFYMASK, &ft_mouse_julia, &mlx);
	mlx_hook(mlx.win, BUTTONPRESS, BUTTONPRESSMASK, &ft_mouse_zoom, &mlx);
	mlx_loop(mlx.ptr);
	return (SUCCESS);
}

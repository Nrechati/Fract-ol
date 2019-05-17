/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:17:51 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/17 12:51:00 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move(t_mlx *mlx, int key)
{
	if ((key == 126 || key == 13) && mlx->y_pad > -10000)
		mlx->y_pad += 0.05 / mlx->zoom;
	else if ((key == 125 || key == 1) && mlx->y_pad < 10000)
		mlx-> y_pad -= 0.05 / mlx->zoom;
	else if ((key == 123 || key == 0) && mlx->x_pad > -10000)
		mlx->x_pad -= 0.05 / mlx->zoom;
	else if ((key == 124 || key == 2) && mlx->x_pad < 10000)
		mlx->x_pad += 0.05 / mlx->zoom;
	draw_fractol(mlx, TRUE, mlx->fractal);
}

void	ft_close(t_mlx *mlx)
{
	int		i;

	i = 0;
	mlx_destroy_image(mlx->ptr, mlx->img);
	exit(0);
}

void	ft_color(t_mlx *mlx)
{
	if (mlx->c == BLUE)
		mlx->c = GREEN;
	else if (mlx->c == GREEN)
		mlx->c = RED;
	else if (mlx->c == RED)
		mlx->c = BLUE;
	draw_fractol(mlx, TRUE, mlx->fractal);
}

void	ft_next(t_mlx *mlx)
{
	if (mlx->frac_nbr == MANDELBROT)
	{
		mlx->frac_nbr = JULIA;
		mlx->fractal = is_julia;
		init_scope(mlx);
	}
	else if (mlx->frac_nbr == JULIA)
	{
		mlx->frac_nbr = BURNING_SH;
		mlx->fractal = is_burning_ship;
		init_scope(mlx);
	}
	else if (mlx->frac_nbr == BURNING_SH)
	{
		mlx->frac_nbr = MANDELBROT;
		mlx->fractal = is_mandelbrot;
		init_scope(mlx);
	}
	draw_fractol(mlx, TRUE, mlx->fractal);
}

int		ft_mouse_zoom(int key, int x, int y, t_mlx *mlx)
{
	if (x > 0 && x < mlx->w && y > 0 && y < mlx->w)
	{
		if (key == 4)
			mlx->zoom *= 1.5;
		else if (key == 5)
			mlx->zoom /= 1.5;
	}
	draw_fractol(mlx, TRUE, mlx->fractal);
	return (0);
}

int		ft_mouse_julia(int x, int y, t_mlx *mlx)
{
	if (mlx->frac_nbr != JULIA || mlx->freeze == TRUE)
		return (SUCCESS);
	if (x > 0 && x < mlx->w && y > 0 && y < mlx->w)
	{
		mlx->julia.re = (double)x / mlx->w * 2 - 1;
		mlx->julia.im = (double)y / mlx->h * 2 - 1;
	}
	draw_fractol(mlx, TRUE, mlx->fractal);
	return (0);
}

void	ft_freeze_julia(t_mlx *mlx)
{
	if (mlx->freeze == FALSE)
		mlx->freeze = TRUE;
	else
		mlx->freeze = FALSE;
}

void	ft_menu_color(t_mlx *mlx)
{
	if (mlx->menu_color == BLACK)
		mlx->menu_color = WHITE;
	else
		mlx->menu_color = BLACK;
	draw_fractol(mlx, TRUE, mlx->fractal);
}

void	ft_ret_color(t_mlx *mlx)
{
	if (mlx->ret == FALSE)
		mlx->ret = TRUE;
	else
		mlx->ret = FALSE;
	draw_fractol(mlx, TRUE, mlx->fractal);
}

void	ft_info(t_mlx *mlx)
{
	if (mlx->info == FALSE)
		mlx->info = TRUE;
	else
		mlx->info = FALSE;
	draw_fractol(mlx, TRUE, mlx->fractal);
}

void	ft_zoom(t_mlx *mlx, int key)
{
	if (key == 69 || key == 24)
		mlx->zoom *= 1.5;
	else
		mlx->zoom /= 1.5;
	draw_fractol(mlx, TRUE, mlx->fractal);
}

void	ft_iterate(t_mlx *mlx, int key)
{
	if (key == 47 && mlx->iter < INT_MAX - 100)
		mlx->iter += 100;
	else if (mlx->iter > 100)
		mlx->iter -= 100;
	draw_fractol(mlx, TRUE, mlx->fractal);
}

void	ft_reset(t_mlx *mlx)
{
	mlx->x_pad = 0.5;
	mlx->y_pad = 0;
	mlx->zoom = 1;
	mlx->iter = 100;
	draw_fractol(mlx, TRUE, mlx->fractal);
}

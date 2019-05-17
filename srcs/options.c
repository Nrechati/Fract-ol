/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:02:33 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/17 16:04:49 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_close(t_mlx *mlx)
{
	int		i;

	i = 0;
	mlx_destroy_image(mlx->ptr, mlx->img);
	exit(0);
}

void	ft_menu_color(t_mlx *mlx)
{
	if (mlx->menu_color == BLACK)
		mlx->menu_color = WHITE;
	else
		mlx->menu_color = BLACK;
	draw_fractol(mlx, TRUE, mlx->fractal);
}

void	ft_reticule(t_mlx *mlx)
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

void	ft_freeze_julia(t_mlx *mlx)
{
	if (mlx->freeze == FALSE)
		mlx->freeze = TRUE;
	else
		mlx->freeze = FALSE;
}

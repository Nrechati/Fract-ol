/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:17:51 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/14 11:35:37 by nrechati         ###   ########.fr       */
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
		mlx->x_pad += 0.05 / mlx->zoom;
	else if ((key == 124 || key == 2) && mlx->x_pad < 10000)
		mlx->x_pad -= 0.05 / mlx->zoom;
	draw_fractol(mlx, TRUE);
}

void	ft_close(t_mlx *mlx)
{
	int		i;

	i = 0;
	mlx_destroy_image(mlx->ptr, mlx->img);
	exit(0);
}

void	ft_zoom(t_mlx *mlx, int key)
{
	if (key == 69 || key == 24)
		mlx->zoom += 1;
	else
		mlx->zoom -= 1;
	draw_fractol(mlx, TRUE);
}

void	ft_iterate(t_mlx *mlx, int key)
{
	if (key == 47 && mlx->iter < INT_MAX - 100)
		mlx->iter += 100;
	else if (mlx->iter > 100)
		mlx->iter -= 100;
	draw_fractol(mlx, TRUE);
}

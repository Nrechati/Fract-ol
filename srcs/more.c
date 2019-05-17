/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:34:03 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/17 16:38:06 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		draw_rectangle(t_mlx *mlx, int size, int i, int j)
{
	int		mem_i;
	int		mem_j;

	mem_i = i;
	mem_j = j;
	while (i++ < size + size + size + mem_i)
	{
		mlx_pixel_put(mlx->ptr, mlx->win, i, j, mlx->menu_color);
		mlx_pixel_put(mlx->ptr, mlx->win, i, j + 1, mlx->menu_color);
		mlx_pixel_put(mlx->ptr, mlx->win, i, size + mem_j, mlx->menu_color);
		mlx_pixel_put(mlx->ptr, mlx->win, i, size + mem_j - 1, mlx->menu_color);
	}
	i = mem_i;
	j = mem_j;
	while (j++ < size + mem_j)
	{
		mlx_pixel_put(mlx->ptr, mlx->win, i, j, mlx->menu_color);
		mlx_pixel_put(mlx->ptr, mlx->win, i + 1, j, mlx->menu_color);
		mlx_pixel_put(mlx->ptr, mlx->win
				, size + size + size + mem_i, j, mlx->menu_color);
		mlx_pixel_put(mlx->ptr, mlx->win
				, size + size + size + mem_i - 1, j, mlx->menu_color);
	}
}

void			zoom_info(t_mlx *mlx)
{
	char *zoom;
	char *zoom_plus;

	zoom = NULL;
	zoom_plus = NULL;
	ft_asprintf(&zoom, "x %.1f", mlx->zoom);
	if (ft_strlen(zoom) >= 15)
		mlx_string_put(mlx->ptr, mlx->win, 220, 80, mlx->menu_color, "OOR");
	else if (mlx->zoom >= 10)
	{
		ft_asprintf(&zoom_plus, "%.3s.%.1sE%d"
				, zoom, zoom + 3, ft_strlen(zoom) - 5);
		mlx_string_put(mlx->ptr, mlx->win, 200, 80, mlx->menu_color, zoom_plus);
		free(zoom_plus);
	}
	else
		mlx_string_put(mlx->ptr, mlx->win, 220, 80, mlx->menu_color, zoom);
	free(zoom);
}

void			info_on(t_mlx *mlx)
{
	char *iterations;

	iterations = NULL;
	draw_rectangle(mlx, 75, 55, 40);
	ft_asprintf(&iterations, "%.0f", mlx->iter);
	mlx_string_put(mlx->ptr, mlx->win, 65, 50, mlx->menu_color, "Iterations :");
	mlx_string_put(mlx->ptr, mlx->win, 220, 50, mlx->menu_color, iterations);
	mlx_string_put(mlx->ptr, mlx->win, 65, 80, mlx->menu_color, "Zoom       :");
	zoom_info(mlx);
	free(iterations);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 11:10:34 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/15 18:00:11 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		draw_square(t_mlx *mlx, int size, int i, int j)
{
	int		mem_i;
	int		mem_j;
	int		color;

	mem_i = i;
	mem_j = j;
	if (size == 10)
		color = mlx->ret_color;
	else
		color = mlx->menu_color;
	while (i++ < size + mem_i)
	{
		mlx_pixel_put(mlx->ptr, mlx->win, i, j, color);
		mlx_pixel_put(mlx->ptr, mlx->win, i, j + 1, color);
		mlx_pixel_put(mlx->ptr, mlx->win, i, size + mem_j, color);
		mlx_pixel_put(mlx->ptr, mlx->win, i, size + mem_j - 1, color);
	}
	i = mem_i;
	j = mem_j;
	while (j++ < size + mem_j)
	{
		mlx_pixel_put(mlx->ptr, mlx->win, i, j, color);
		mlx_pixel_put(mlx->ptr, mlx->win, i + 1, j, color);
		mlx_pixel_put(mlx->ptr, mlx->win, size + mem_i, j, color);
		mlx_pixel_put(mlx->ptr, mlx->win, size + mem_i - 1, j, color);
	}
}

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
		mlx_pixel_put(mlx->ptr, mlx->win, size + size + size + mem_i, j, mlx->menu_color);
		mlx_pixel_put(mlx->ptr, mlx->win, size + size + size + mem_i - 1, j, mlx->menu_color);
	}
}

static void		info_on(t_mlx *mlx)
{
	char *iterations;
	char *zoom;
	char *zoom_plus  = NULL;

	iterations = NULL;
	zoom = NULL;
	zoom_plus = NULL;
	draw_rectangle(mlx, 75, 55, 40);
	ft_asprintf(&iterations, "%.0f", mlx->iter);
	ft_asprintf(&zoom, "x %.1f", mlx->zoom);
	mlx_string_put(mlx->ptr, mlx->win, 65, 50, mlx->menu_color, "Iterations :");
	mlx_string_put(mlx->ptr, mlx->win, 220, 50, mlx->menu_color, iterations);
	mlx_string_put(mlx->ptr, mlx->win, 65, 80, mlx->menu_color, "Zoom       :");
	if (ft_strlen(zoom) >= 15)
		mlx_string_put(mlx->ptr, mlx->win, 220, 80, mlx->menu_color, "OOR");
	else if (mlx->zoom >= 10)
	{
		ft_asprintf(&zoom_plus, "%.3s.%.1sE%d", zoom, zoom + 3, ft_strlen(zoom) - 5);
		mlx_string_put(mlx->ptr, mlx->win, 200, 80, mlx->menu_color, zoom_plus);
		free(zoom_plus);
	}
	else
		mlx_string_put(mlx->ptr, mlx->win, 220, 80, mlx->menu_color, zoom);
	free(iterations);
	free(zoom);
}

void			draw_menu(t_mlx *mlx)
{
	if (mlx->info == TRUE)
		info_on(mlx);
	if (mlx->ret == TRUE)
		draw_square(mlx, 10, (mlx->w / 2) - 5 , (mlx->h / 2) - 5);
	draw_square(mlx, 40, 180, 160);
	mlx_string_put(mlx->ptr, mlx->win, 65, 170, mlx->menu_color, "Exit     :  ESC");
	draw_square(mlx, 40, 180, 210);
	mlx_string_put(mlx->ptr, mlx->win, 65, 220, mlx->menu_color, "Freeze   :  MAJ");
	draw_square(mlx, 40, 180, 260);
	mlx_string_put(mlx->ptr, mlx->win, 65, 270, mlx->menu_color, "Reset    :   R");
	draw_square(mlx, 40, 180, 310);
	mlx_string_put(mlx->ptr, mlx->win, 65, 320, mlx->menu_color, "Iter +   :   >");
	draw_square(mlx, 40, 180, 360);
	mlx_string_put(mlx->ptr, mlx->win, 65, 370, mlx->menu_color, "Iter -   :   <");
	draw_square(mlx, 40, 180, 410);
	mlx_string_put(mlx->ptr, mlx->win, 65, 420, mlx->menu_color, "Color    :  SPA");
	draw_square(mlx, 40, 180, 460);
	mlx_string_put(mlx->ptr, mlx->win, 65, 470, mlx->menu_color, "Next     :  TAB");
	draw_square(mlx, 20, 190, 510);
	mlx_string_put(mlx->ptr, mlx->win, 65, 510, mlx->menu_color, "             W      ");
	draw_square(mlx, 20, 160, 540);
	draw_square(mlx, 20, 190, 540);
	draw_square(mlx, 20, 220, 540);
	mlx_string_put(mlx->ptr, mlx->win, 65, 540, mlx->menu_color, "Move      A  S  D   ");
}

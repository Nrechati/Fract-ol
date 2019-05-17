/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 11:10:34 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/17 16:36:46 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		get_square_color(t_mlx *mlx, int size)
{
	if (size == 10)
		return (mlx->ret_color);
	else
		return (mlx->menu_color);
}

static void		draw_square(t_mlx *mlx, int size, int i, int j)
{
	int		mem_i;
	int		mem_j;
	int		color;

	mem_i = i;
	mem_j = j;
	color = get_square_color(mlx, size);
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

static void		draw_menu_squares(t_mlx *mlx)
{
	draw_square(mlx, 40, 180, 160);
	draw_square(mlx, 40, 180, 210);
	draw_square(mlx, 40, 180, 260);
	draw_square(mlx, 40, 180, 310);
	draw_square(mlx, 40, 180, 360);
	draw_square(mlx, 40, 180, 410);
	draw_square(mlx, 40, 180, 460);
	draw_square(mlx, 20, 190, 510);
	draw_square(mlx, 20, 160, 540);
	draw_square(mlx, 20, 190, 540);
	draw_square(mlx, 20, 220, 540);
}

void			draw_menu(t_mlx *mlx)
{
	if (mlx->info == TRUE)
		info_on(mlx);
	if (mlx->ret == TRUE)
		draw_square(mlx, 10, (mlx->w / 2) - 5, (mlx->h / 2) - 5);
	mlx_string_put(mlx->ptr, mlx->win, 65, 170, mlx->menu_color
			, "Exit     :  ESC");
	mlx_string_put(mlx->ptr, mlx->win, 65, 220, mlx->menu_color
			, "Freeze   :  MAJ");
	mlx_string_put(mlx->ptr, mlx->win, 65, 270, mlx->menu_color
			, "Reset    :   R");
	mlx_string_put(mlx->ptr, mlx->win, 65, 320, mlx->menu_color
			, "Iter +   :   >");
	mlx_string_put(mlx->ptr, mlx->win, 65, 370, mlx->menu_color
			, "Iter -   :   <");
	mlx_string_put(mlx->ptr, mlx->win, 65, 420, mlx->menu_color
			, "Color    :  SPA");
	mlx_string_put(mlx->ptr, mlx->win, 65, 470, mlx->menu_color
			, "Next     :  TAB");
	mlx_string_put(mlx->ptr, mlx->win, 65, 510, mlx->menu_color
			, "             W      ");
	mlx_string_put(mlx->ptr, mlx->win, 65, 540, mlx->menu_color
			, "Move      A  S  D   ");
	draw_menu_squares(mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 11:10:34 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/14 15:43:55 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		draw_square(t_mlx *mlx, int size, int i, int j)
{
	int		mem_i;
	int		mem_j;

	mem_i = i;
	mem_j = j;
	while (i++ < size + mem_i)
	{
		mlx_pixel_put(mlx->ptr, mlx->win, i, j, WHITE);
		mlx_pixel_put(mlx->ptr, mlx->win, i, j + 1, WHITE);
		mlx_pixel_put(mlx->ptr, mlx->win, i, size + mem_j, WHITE);
		mlx_pixel_put(mlx->ptr, mlx->win, i, size + mem_j - 1, WHITE);
	}
	i = mem_i;
	j = mem_j;
	while (j++ < size + mem_j)
	{
		mlx_pixel_put(mlx->ptr, mlx->win, i, j, WHITE);
		mlx_pixel_put(mlx->ptr, mlx->win, i + 1, j, WHITE);
		mlx_pixel_put(mlx->ptr, mlx->win, size + mem_i, j, WHITE);
		mlx_pixel_put(mlx->ptr, mlx->win, size + mem_i - 1, j, WHITE);
	}
}

void			draw_menu(t_mlx *mlx)
{
	draw_square(mlx, 40, 180, 160);
	mlx_string_put(mlx->ptr, mlx->win, 65, 170, WHITE, "Exit     :  ESC");
	draw_square(mlx, 40, 180, 210);
	mlx_string_put(mlx->ptr, mlx->win, 65, 220, WHITE, "Zoom in  :   +");
	draw_square(mlx, 40, 180, 260);
	mlx_string_put(mlx->ptr, mlx->win, 65, 270, WHITE, "Zoom out :   -");
	draw_square(mlx, 40, 180, 310);
	mlx_string_put(mlx->ptr, mlx->win, 65, 320, WHITE, "Iter +   :   >");
	draw_square(mlx, 40, 180, 360);
	mlx_string_put(mlx->ptr, mlx->win, 65, 370, WHITE, "Iter -   :   <");
	draw_square(mlx, 40, 180, 410);
	mlx_string_put(mlx->ptr, mlx->win, 65, 420, WHITE, "Color    :  SPA");
	draw_square(mlx, 40, 180, 460);
	mlx_string_put(mlx->ptr, mlx->win, 65, 470, WHITE, "Next     :  TAB");
	draw_square(mlx, 20, 190, 510);
	mlx_string_put(mlx->ptr, mlx->win, 65, 510, WHITE, "             W      ");
	draw_square(mlx, 20, 160, 540);
	draw_square(mlx, 20, 190, 540);
	draw_square(mlx, 20, 220, 540);
	mlx_string_put(mlx->ptr, mlx->win, 65, 540, WHITE, "Move      A  S  D   ");
}

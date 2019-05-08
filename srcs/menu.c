/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 11:10:34 by nrechati          #+#    #+#             */
/*   Updated: 2019/01/08 11:13:09 by nrechati         ###   ########.fr       */
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
		mlx_pixel_put(mlx->ptr, mlx->win, i, j, mlx->c);
		mlx_pixel_put(mlx->ptr, mlx->win, i, j + 1, mlx->c);
		mlx_pixel_put(mlx->ptr, mlx->win, i, size + mem_j, mlx->c);
		mlx_pixel_put(mlx->ptr, mlx->win, i, size + mem_j - 1, mlx->c);
	}
	i = mem_i;
	j = mem_j;
	while (j++ < size + mem_j)
	{
		mlx_pixel_put(mlx->ptr, mlx->win, i, j, mlx->c);
		mlx_pixel_put(mlx->ptr, mlx->win, i + 1, j, mlx->c);
		mlx_pixel_put(mlx->ptr, mlx->win, size + mem_i, j, mlx->c);
		mlx_pixel_put(mlx->ptr, mlx->win, size + mem_i - 1, j, mlx->c);
	}
}

void			draw_menu(t_mlx *mlx)
{
	draw_square(mlx, 40, 180, 330);
	mlx_string_put(mlx->ptr, mlx->win, 65, 340, mlx->c, "Exit     :  ESC");
	draw_square(mlx, 40, 180, 380);
	mlx_string_put(mlx->ptr, mlx->win, 65, 390, mlx->c, "Zoom in  :   +");
	draw_square(mlx, 40, 180, 430);
	mlx_string_put(mlx->ptr, mlx->win, 65, 440, mlx->c, "Zoom out :   -");
	draw_square(mlx, 40, 180, 480);
	mlx_string_put(mlx->ptr, mlx->win, 65, 490, mlx->c, "Alt +    :   >");
	draw_square(mlx, 40, 180, 530);
	mlx_string_put(mlx->ptr, mlx->win, 65, 540, mlx->c, "Alt -    :   <");
	draw_square(mlx, 40, 180, 580);
	mlx_string_put(mlx->ptr, mlx->win, 65, 590, mlx->c, "Color    :  SPA");
	draw_square(mlx, 40, 180, 630);
	mlx_string_put(mlx->ptr, mlx->win, 65, 640, mlx->c, "Proj     :  ENT");
	draw_square(mlx, 20, 190, 710);
	mlx_string_put(mlx->ptr, mlx->win, 65, 710, mlx->c, "             W      ");
	draw_square(mlx, 20, 160, 740);
	draw_square(mlx, 20, 190, 740);
	draw_square(mlx, 20, 220, 740);
	mlx_string_put(mlx->ptr, mlx->win, 65, 740, mlx->c, "Move      A  S  D   ");
}

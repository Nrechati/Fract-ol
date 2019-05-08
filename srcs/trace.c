/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:31:22 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/08 15:05:57 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		trace_dna(t_mlx *mlx, t_pt *origin, t_pt *end)
{
	t_dna dna;

	init_dna(&dna);
	if (ft_abs(end->x - origin->x) >= ft_abs(end->y - origin->y))
		dna.len = ft_abs(end->x - origin->x);
	else
		dna.len = ft_abs(end->y - origin->y);
	dna.dx = (end->x - origin->x) / dna.len;
	dna.dy = (end->y - origin->y) / dna.len;
	dna.x = origin->x + 0.5;
	dna.y = origin->y + 0.5;
	while (dna.i <= dna.len)
	{
		fill_pixel(mlx, dna.x, dna.y);
		dna.x = dna.x + dna.dx;
		dna.y = dna.y + dna.dy;
		dna.i++;
	}
	return ;
}

static void		project_map(t_pt *pt, t_map *map, int index_x, int index_y)
{
	if (map->mlx->proj == 1)
		iso_project(pt, map, index_x, index_y);
	if (map->mlx->proj == 2)
		para_project(pt, map, index_x, index_y);
}

static void		do_draw(t_mlx *mlx, t_map *map, int index_x, int index_y)
{
	t_pt origin;
	t_pt end;

	origin.x = (index_x * map->pad);
	origin.y = (index_y * map->pad);
	project_map(&origin, map, index_x, index_y);
	if (index_x < map->col - 1)
	{
		end.x = ((index_x + 1) * map->pad);
		end.y = (index_y * map->pad);
		project_map(&end, map, index_x + 1, index_y);
		trace_dna(mlx, &origin, &end);
	}
	if (index_y < map->row - 1)
	{
		end.x = (index_x * map->pad);
		end.y = ((index_y + 1) * map->pad);
		project_map(&end, map, index_x, index_y + 1);
		trace_dna(mlx, &origin, &end);
	}
}

int				draw_fractol(t_mlx *mlx, t_map *map, int flag)
{
	int index_x;
	int index_y;

	if (flag == 0)
		mlx_destroy_image(mlx->ptr, mlx->img);
	init_img(mlx);
	index_y = -1;
	while (++index_y < map->row)
	{
		index_x = -1;
		while (++index_x < map->col)
			do_draw(mlx, map, index_x, index_y);
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	draw_menu(mlx);
	return (1);
}

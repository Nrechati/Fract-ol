/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 10:43:20 by nrechati          #+#    #+#             */
/*   Updated: 2019/01/08 11:20:43 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iso_project(t_pt *pt, t_map *map, int index_x, int index_y)
{
	pt->x = (pt->x - pt->y) * sin(map->mlx->iso_rot);
	pt->y = (pt->x + pt->y) * cos(map->mlx->iso_rot);
	pt->y /= 2;
	pt->y -= map->tab[index_y][index_x] * map->hpad;
	pt->x += map->w_xpad;
	pt->y += map->w_ypad;
}

void	para_project(t_pt *pt, t_map *map, int index_x, int index_y)
{
	pt->x = pt->x - ((map->tab[index_y][index_x] / 2) * map->hpad);
	pt->y = pt->y - ((map->tab[index_y][index_x] / 2) * map->hpad);
	pt->x += map->w_xpad;
	pt->y += map->w_ypad;
}

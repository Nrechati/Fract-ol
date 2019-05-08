/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 13:40:38 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/08 15:05:57 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_proj(t_map *map)
{
	if (map->mlx->proj < 2)
		map->mlx->proj++;
	else
		map->mlx->proj = 1;
	init_view(map);
	draw_fractol(map->mlx, map, 0);
}

void	ft_color(t_map *map)
{
	if (map->mlx->c == RED)
		map->mlx->c = GREEN;
	else if (map->mlx->c == GREEN)
		map->mlx->c = BLUE;
	else if (map->mlx->c == BLUE)
		map->mlx->c = ORANGE;
	else if (map->mlx->c == ORANGE)
		map->mlx->c = RED;
	draw_fractol(map->mlx, map, 0);
}

void	ft_alt(t_map *map, int key)
{
	if (key == 124 || key == 126)
		map->hpad += 1;
	else
		map->hpad -= 1;
	draw_fractol(map->mlx, map, 0);
}

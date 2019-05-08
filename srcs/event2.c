/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:08:08 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/08 15:05:57 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move(t_map *map, int key)
{
	if (key == 1)
		map->w_ypad += 10;
	else if (key == 13)
		map->w_ypad -= 10;
	else if (key == 2)
		map->w_xpad += 10;
	else
		map->w_xpad -= 10;
	draw_fractol(map->mlx, map, 0);
}

void	ft_rotate(t_map *map, int key)
{
	if (key == 12)
		map->mlx->iso_rot -= 0.1;
	else
		map->mlx->iso_rot += 0.1;
	draw_fractol(map->mlx, map, 0);
}

void	ft_close(t_map *map)
{
	int		i;

	i = 0;
	mlx_destroy_image(map->mlx->ptr, map->mlx->img);
	while (i < map->row)
		free(map->tab[i++]);
	free(map->tab);
	exit(0);
}

void	ft_zoom(t_map *map, int key)
{
	if (key == 69 || key == 24)
		map->pad += 1;
	else
		map->pad -= 1;
	draw_fractol(map->mlx, map, 0);
}

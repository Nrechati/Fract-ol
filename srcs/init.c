/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:36:36 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/08 15:05:57 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->l = 1080;
	mlx->w = 1920;
	mlx->c = BLUE;
	mlx->proj = 1;
	mlx->iso_rot = M_PI / 6;
	mlx->img = NULL;
	mlx->img_str = NULL;
	mlx->img_size = mlx->w * mlx->l;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, mlx->w, mlx->l, "fractol");
}

void	init_dna(t_dna *dna)
{
	dna->len = 0;
	dna->dx = 0;
	dna->dy = 0;
	dna->x = 0;
	dna->y = 0;
	dna->i = 0;
}

void	init_map(t_mlx *mlx, t_map *map)
{
	map->tab = NULL;
	map->pad = 0;
	map->w_xpad = 0;
	map->w_ypad = 0;
	map->hpad = 0;
	map->row = 0;
	map->col = 0;
	map->mlx = mlx;
}

void	init_view(t_map *map)
{
	map->mlx->iso_rot = M_PI / 6;
	map->pad = 1500 / map->col;
	map->hpad = map->pad / 10;
	if (map->mlx->proj == 1)
	{
		map->w_xpad = map->mlx->w / 2;
		map->w_ypad = map->mlx->l / 3;
	}
	if (map->mlx->proj == 2)
	{
		map->w_xpad = map->mlx->w / 5;
		map->w_ypad = map->mlx->l / 5;
	}
}

int		init_parsing(t_map *map, char *line, char **av, int *fd)
{
	int fd_init;

	fd_init = open(av[1], O_RDONLY);
	while (get_next_line(fd_init, &line) > 0)
	{
		map->row++;
		free(line);
	}
	free(line);
	close(fd_init);
	if (!(map->tab = (int **)malloc(sizeof(int *) * (map->row))))
		return (0);
	if ((*fd = open(av[1], O_RDONLY)) < 0)
		return (0);
	return (1);
}

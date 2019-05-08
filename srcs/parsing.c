/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:35:03 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/08 15:05:57 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_splitlen(char **split)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (split[i++] != NULL)
		len++;
	return (len);
}

static int		check_length(int len, char **split, int i)
{
	if (i != 0)
		if (len != ft_splitlen(split))
			return (0);
	return (1);
}

static	int		do_parse(t_map *map, char *line, int fd, char **split)
{
	int		i;
	int		j;
	int		res;

	i = 0;
	while ((res = get_next_line(fd, &line)) > 0)
	{
		split = ft_strsplit(line, " ");
		if (!check_length(map->col, split, i) && (j = -1))
			return (0);
		map->col = ft_splitlen(split);
		if (!(map->tab[i] = (int *)malloc(sizeof(int) * (map->col))))
			return (0);
		while (++j < map->col)
			map->tab[i][j] = ft_atoi(split[j]);
		while (--j >= 0)
			free(split[j]);
		free(split);
		free(line);
		i++;
	}
	if (res == -1)
		return (0);
	free(line);
	return (1);
}

int				fractol_parsing(t_mlx *mlx, t_map *map, char *line, char **av)
{
	int			fd;

	init_map(mlx, map);
	if (!init_parsing(map, line, av, &fd))
		return (0);
	if (!do_parse(map, line, fd, NULL))
		return (0);
	if (close(fd) != 0)
		return (0);
	init_mlx(mlx);
	init_view(map);
	return (1);
}

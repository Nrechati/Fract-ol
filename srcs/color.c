/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:43:05 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/17 12:46:09 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(t_mlx *mlx, int iter)
{
	int	 color;

	color = (1 - (iter / mlx->iter)) * mlx->c;
	return (color);
}

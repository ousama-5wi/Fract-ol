/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dessiner.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:15:06 by oelkhams          #+#    #+#             */
/*   Updated: 2019/11/16 21:15:18 by oelkhams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *fractol, int x, int y, int color)
{
	if (x < 600 && x >= 0 && y >= 0 && y < 600)
		fractol->data[x + y * 600] = color;
}

void	draw(t_fractol *fractol)
{
	int i;
	int j;

	fractol->color = get_color(fractol->palette);
	i = 0;
	while (i < 600)
	{
		j = 0;
		while (j < 600)
		{
			fractol->funk_ptr(fractol, i, j);
			j++;
		}
		i++;
	}
	mlx_clear_window(fractol->mlx_ptr, fractol->win_ptr);
	mlx_put_image_to_window(fractol->mlx_ptr,\
			fractol->win_ptr, fractol->img_ptr, 0, 0);
}

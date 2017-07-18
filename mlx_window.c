/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:55:55 by kboucaud          #+#    #+#             */
/*   Updated: 2017/03/22 16:35:43 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			my_key_func(int key, void *param)
{
	if (key == 53)
		exit(1);
	return (0);
}

void		open_new(t_file *file)
{
	t_data		data;

	if ((data.mlx = mlx_init()) == NULL)
		ft_error();
	if ((data.mlx_window = mlx_new_window(data.mlx, 1500, 1200, "Fdf")) == NULL)
		ft_error();
	file->data = data;
	if (file->first_y != NULL)
		ft_draw_y(file);
	if (file->first_x != NULL)
		ft_draw_x(file);
	mlx_key_hook(data.mlx_window, my_key_func, 0);
	mlx_loop(data.mlx);
}

double		smll(int x)
{
	return (x * 0.2);
}

double		x_iso(double x, double y)
{
	return ((x - y + 10) * 40);
}

double		y_iso_up(double x, double y)
{
	return ((x + y + 3) * 20);
}

double		y_iso(double x, double y)
{
	return ((x + y + 4) * 20);
}

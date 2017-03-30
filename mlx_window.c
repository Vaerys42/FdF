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

int		my_key_func(int key, void *param)
{
	if (key == 53)
		exit(1);
	return (0);
}

int		open_new(int coo[5][6])
{
	t_data		data;

	if ((data.mlx = mlx_init()) == NULL)
		return (-1);
	if ((data.mlx_window = mlx_new_window(data.mlx, 800, 600, "Fdf")) == NULL)
		return (-2);
	ft_draw_y(coo, data);
	ft_draw_x(coo, data);
	mlx_key_hook(data.mlx_window, my_key_func, 0);
	mlx_loop(data.mlx);
	return (0);
}

void		ft_draw_x(int coo[5][6], t_data data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (coo[y][x] != -2)
	{
		x = 0;
		while (coo[y][x] != -1 && coo[y][x] != -2)
		{
			ft_draw_seg(x_iso(x, y - coo[y][x]), x_iso(x + 1, y - coo[y][x + 1]), y_iso(y - coo[y][x], x), y_iso(y - coo[y][x + 1], x + 1), data);
			x++;
		}
		if (coo[y][x] != -2)
			y++;
	}
	x = 0;
	while (coo[y][x] != -2)
	{
		ft_draw_seg(x_iso(x, y - coo[y][x]), x_iso(x + 1, y - coo[y][x + 1]), y_iso(y - coo[y][x], x), y_iso(y - coo[y][x + 1], x + 1), data);
		x++;
	}
}

void		ft_draw_y(int coo[5][6], t_data data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (coo[y + 1][x] != -2)
	{
		x = 0;
		while (coo[y][x] != -1)
		{
			ft_draw_seg(x_iso(x + coo[y + 1][x], y + 1), x_iso(x, y), y_iso(y + 1, x), y_iso(y, x), data);
			x++;
		}
		if (coo[y + 1][x] != -2)
			y++;
	}
	x = 0;
	while (coo[y][x] != -1)
	{
		ft_draw_seg(x_iso(x, y + 1), x_iso(x, y), y_iso(y + 1, x), y_iso(y, x), data);
		x++;
	}
}

int		x_iso(int x, int y)
{
	return ((x - y + 5) * 40);
}

int		y_iso(int y, int x)
{
	return ((x + y + 1) * 20);
}

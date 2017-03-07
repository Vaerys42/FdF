/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:55:55 by kboucaud          #+#    #+#             */
/*   Updated: 2017/03/07 15:55:57 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	my_key_func(int key, void *param)
{
	if (key == 53)
		exit(1);
	return (0);
}

int		open_new()
{
	t_data		mlx_info;
	int 		x;
	int 		y;
	int 		color;

	x = 200;
	y = 200;
	color = BLUE;
	if ((mlx_info.mlx = mlx_init()) == NULL)
		return (-1);
	if ((mlx_info.mlx_window = mlx_new_window(mlx_info.mlx, 800, 600, "Fdf")) == NULL)
		return (-2);
	while (x++ < 300 && y-- > 0)
	{
		mlx_pixel_put(mlx_info.mlx, mlx_info.mlx_window, x, y, color);
		if (x == 250)
			color = GREEN;
	}
	mlx_key_hook(mlx_info.mlx_window, my_key_func, 0);
	mlx_loop(mlx_info.mlx);
	return (0);
}

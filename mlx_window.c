/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:55:55 by kboucaud          #+#    #+#             */
/*   Updated: 2017/03/08 18:52:00 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_key_func(int key, void *param)
{
	if (key == 53)
		exit(1);
	return (0);
}

int		open_new(void)
{
	t_data		data;
	int			x;
	int			y;
	int			color;

	x = 200;
	y = 200;
	color = BLUE;
	if ((data.mlx = mlx_init()) == NULL)
		return (-1);
	if ((data.mlx_window = mlx_new_window(data.mlx, 800, 600, "Fdf")) == NULL)
		return (-2);
	while (x++ < 300 && y-- > 0)
	ft_draw_seg(100, 200, 100, 100, data);
	mlx_key_hook(data.mlx_window, my_key_func, 0);
	mlx_loop(data.mlx);
	return (0);
}

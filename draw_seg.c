/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_seg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 19:00:36 by kboucaud          #+#    #+#             */
/*   Updated: 2017/03/09 19:00:39 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_seg(int xa, int xb, int ya, int yb, t_data data)
{
	int		dx;
	int		dy;
	int		cumul;
	int		x;
	int		y;

	x = xa;
	y = ya;
	dx = xb - xa;
	dy = yb - ya;
	mlx_pixel_put(data.mlx, data.mlx_window, x, y, WHITE);
	cumul = dx / 2;
	x = xa + 1;
	while (x <= xb)
	{
		cumul = cumul + dy;
		if (cumul >= dx)
		{
			cumul = cumul - dx;
			y++;
		}
		mlx_pixel_put(data.mlx, data.mlx_window, x, y, WHITE);
		x++;
	}
}


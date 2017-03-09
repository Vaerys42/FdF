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
	int		x;
	int		y;
	double	a;
	double	b;

	if (xa >= xb)
		return ;
	x = xa;
	a = (double)((yb - ya)/(xb - xa));
	b = yb - (a * xa);
	while (x <= xb)
	{
		y = (int)((a * x) + b);
		mlx_pixel_put(data.mlx, data.mlx_window, x, y, GREEN);
		x++;
	}
}


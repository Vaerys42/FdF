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

void		ft_draw_seg(double xa, double xb, double ya, double yb, t_data data)
{
	t_coo	d;
	t_coo	incr;
	t_coo	a;

	incr.x = -1;
	incr.y = -1;
	a.x = xa;
	a.y = ya;
	d.x = fabs(xb - xa);
	d.y = fabs(yb - ya);
	if (xa < xb)
		incr.x = 1;
	if (ya < yb)
		incr.y = 1;
	if (d.x > d.y)
		dx_sup(data, d, incr, a);
	else
		dy_sup(data, d, incr, a);
	mlx_pixel_put(data.mlx, data.mlx_window, xa, ya, WHITE);
	mlx_pixel_put(data.mlx, data.mlx_window, xb, yb, WHITE);
}

void		dx_sup(t_data data, t_coo d, t_coo incr, t_coo a)
{
	double		i;
	double		erreur;
	double		x;
	double		y;

	i = 0;
	x = a.x;
	y = a.y;
	erreur = d.x / 2;
	while (i < d.x)
	{
		x = x + incr.x;
		erreur = erreur + d.y;
		if (erreur > d.x)
		{
			erreur = erreur - d.x;
			y = y + incr.y;
		}
		mlx_pixel_put(data.mlx, data.mlx_window, x, y, WHITE);
		i++;
	}
}

void		dy_sup(t_data data, t_coo d, t_coo incr, t_coo a)
{
	double		i;
	double		erreur;
	double		x;
	double		y;

	i = 0;
	x = a.x;
	y = a.y;
	erreur = d.y / 2;
	while (i < d.y)
	{
		y = y + incr.y;
		erreur = erreur + d.x;
		if (erreur > d.y)
		{
			erreur = erreur - d.y;
			x = x + incr.x;
		}
		mlx_pixel_put(data.mlx, data.mlx_window, x, y, WHITE);
		i++;
	}
}

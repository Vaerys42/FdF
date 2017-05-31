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

void		ft_draw_seg(t_seg send)
{
	t_coo	d;
	t_coo	incr;
	t_coo	a;

	incr.x = -1;
	incr.y = -1;
	a.x = send.xa;
	a.y = send.ya;
	d.x = fabs(send.xb - send.xa);
	d.y = fabs(send.yb - send.ya);
	if (send.xa < send.xb)
		incr.x = 1;
	if (send.ya < send.yb)
		incr.y = 1;
	if (d.x > d.y)
		dx_sup(send.data, d, incr, a);
	else
		dy_sup(send.data, d, incr, a);
	mlx_pixel_put(send.data.mlx, send.data.mlx_window, send.xa, send.ya, WHITE);
	mlx_pixel_put(send.data.mlx, send.data.mlx_window, send.xb, send.yb, WHITE);
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

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

int		get_color(int z)
{
	if (z > 0 && z < 5)
		return (GREEN);
	if (z >= 5 && z < 10)
		return (BROWN);
	return (WHITE);
}

void	put_pxl(t_data *data, int x, int y, unsigned int c)
{
	int		i;

	i = (x * 4) + (y * data->s_l);
	data->image_string[i] = c;
	data->image_string[++i] = c >> 8;
	data->image_string[++i] = c >> 16;
}

void		ft_draw_seg(t_seg send, t_fdf *fdf)
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
		dx_sup(fdf->data, d, incr, a);
	else
		dy_sup(fdf->data, d, incr, a);
	put_pxl(fdf->data, send.xa, send.ya, WHITE);
	put_pxl(fdf->data, send.xb, send.yb, WHITE);
}

void		dx_sup(t_data *data, t_coo d, t_coo incr, t_coo a)
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
		put_pxl(data, x, y, WHITE);
		i++;
	}
}

void		dy_sup(t_data *data, t_coo d, t_coo incr, t_coo a)
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
		put_pxl(data, x, y, WHITE);
		i++;
	}
}

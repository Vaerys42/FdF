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

void		put_pxl(t_data *data, int x, int y, unsigned int c)
{
	int		i;

	i = (x * 4) + (y * data->s_l);
	data->image_string[i] = c;
	data->image_string[++i] = c >> 8;
	data->image_string[++i] = c >> 16;
}

void		ft_draw_seg(t_fdf *fdf)
{
	fdf->seg->incr_x = -1;
	fdf->seg->incr_y = -1;
	fdf->seg->a_x = fdf->file->current->win_x;
	fdf->seg->a_y = fdf->file->current->win_y;
	fdf->seg->d_x = fabs(fdf->file->current->next->win_x -
	fdf->file->current->win_x);
	fdf->seg->d_y = fabs(fdf->file->current->next->win_y -
	fdf->file->current->win_y);
	if (fdf->file->current->win_x < fdf->file->current->next->win_x)
		fdf->seg->incr_x = 1;
	if (fdf->file->current->win_y < fdf->file->current->next->win_y)
		fdf->seg->incr_y = 1;
	if (fdf->seg->d_x > fdf->seg->d_y)
		dx_sup(fdf);
	else
		dy_sup(fdf);
	put_pxl(fdf->data, fdf->file->current->win_x, fdf->file->current->win_y,
	fdf->file->current->color);
	put_pxl(fdf->data, fdf->file->current->next->win_x,
	fdf->file->current->next->win_y, fdf->file->current->next->color);
}

void		dx_sup(t_fdf *fdf)
{
	double		i;
	double		erreur;
	double		x;
	double		y;

	i = 0;
	x = fdf->seg->a_x;
	y = fdf->seg->a_y;
	erreur = fdf->seg->d_x / 2;
	while (i < fdf->seg->d_x)
	{
		x = x + fdf->seg->incr_x;
		erreur = erreur + fdf->seg->d_y;
		if (erreur > fdf->seg->d_x)
		{
			erreur = erreur - fdf->seg->d_x;
			y = y + fdf->seg->incr_y;
		}
		put_pxl(fdf->data, x, y, fdf->file->current->color);
		i++;
	}
}

void		dy_sup(t_fdf *fdf)
{
	double		i;
	double		erreur;
	double		x;
	double		y;

	i = 0;
	x = fdf->seg->a_x;
	y = fdf->seg->a_y;
	erreur = fdf->seg->d_y / 2;
	while (i < fdf->seg->d_y)
	{
		y = y + fdf->seg->incr_y;
		erreur = erreur + fdf->seg->d_x;
		if (erreur > fdf->seg->d_y)
		{
			erreur = erreur - fdf->seg->d_y;
			x = x + fdf->seg->incr_x;
		}
		put_pxl(fdf->data, x, y, fdf->file->current->color);
		i++;
	}
}

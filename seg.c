/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:39:33 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/27 17:39:36 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		down_to_down(t_fdf *fdf)
{
	fdf->file->current->win_x = x_iso(fdf->file->current->x,
	fdf->file->current->y, fdf);
	fdf->file->current->next->win_x = x_iso(fdf->file->current->next->x,
	fdf->file->current->next->y, fdf);
	fdf->file->current->win_y = y_iso(fdf->file->current->x,
	fdf->file->current->y, fdf);
	fdf->file->current->next->win_y = y_iso(fdf->file->current->next->x,
	fdf->file->current->next->y, fdf);
}

void		down_to_up(t_fdf *fdf)
{
	fdf->file->current->win_x = x_iso(fdf->file->current->x,
	fdf->file->current->y - smll(fdf->file->current->z), fdf);
	fdf->file->current->next->win_x = x_iso(fdf->file->current->next->x,
	fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
	fdf->file->current->win_y = y_iso(fdf->file->current->x,
	fdf->file->current->y - smll(fdf->file->current->z), fdf);
	fdf->file->current->next->win_y = y_iso_up(fdf->file->current->next->x,
	fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
	fdf->file->current->color = fdf->file->current->next->color;
}

void		up_to_down(t_fdf *fdf)
{
	fdf->file->current->win_x = x_iso(fdf->file->current->x,
	fdf->file->current->y - smll(fdf->file->current->z), fdf);
	fdf->file->current->next->win_x = x_iso(fdf->file->current->next->x,
	fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
	fdf->file->current->win_y = y_iso_up(fdf->file->current->x,
	fdf->file->current->y - smll(fdf->file->current->z), fdf);
	fdf->file->current->next->win_y = y_iso(fdf->file->current->next->x,
	fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
}

void		up_to_up(t_fdf *fdf)
{
	fdf->file->current->win_x = x_iso(fdf->file->current->x,
	fdf->file->current->y - smll(fdf->file->current->z), fdf);
	fdf->file->current->next->win_x = x_iso(fdf->file->current->next->x,
	fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
	fdf->file->current->win_y = y_iso_up(fdf->file->current->x,
	fdf->file->current->y - smll(fdf->file->current->z), fdf);
	fdf->file->current->next->win_y = y_iso_up(fdf->file->current->next->x,
	fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
}

void		ft_co_win(t_fdf *fdf)
{
	if (fdf->file->current->z == fdf->file->current->next->z
	&& fdf->file->current->z == 0)
		down_to_down(fdf);
	else if (fdf->file->current->z < fdf->file->current->next->z
	&& fdf->file->current->z == 0)
		down_to_up(fdf);
	else if (fdf->file->current->z > fdf->file->current->next->z
	&& fdf->file->current->next->z == 0)
		up_to_down(fdf);
	else
		up_to_up(fdf);
}

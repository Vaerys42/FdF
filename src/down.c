/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:01:11 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/28 14:01:12 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		zero_to_down(t_fdf *fdf)
{
	fdf->file->current->win_x = x_iso(fdf->file->current->x,
	fdf->file->current->y - smll(fdf->file->current->z), fdf);
	fdf->file->current->next->win_x = x_iso(fdf->file->current->next->x,
	fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
	fdf->file->current->win_y = y_iso(fdf->file->current->x,
	fdf->file->current->y - smll(fdf->file->current->z), fdf);
	fdf->file->current->next->win_y = y_iso_down(fdf->file->current->next->x,
	fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
	fdf->file->current->color = fdf->file->current->next->color;
}

void		down_to_zero(t_fdf *fdf)
{
	fdf->file->current->win_x = x_iso(fdf->file->current->x,
	fdf->file->current->y - smll(fdf->file->current->z), fdf);
	fdf->file->current->next->win_x = x_iso(fdf->file->current->next->x,
	fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
	fdf->file->current->win_y = y_iso_down(fdf->file->current->x,
	fdf->file->current->y - smll(fdf->file->current->z), fdf);
	fdf->file->current->next->win_y = y_iso(fdf->file->current->next->x,
	fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
}

void		down_to_down(t_fdf *fdf)
{
	fdf->file->current->win_x = x_iso(fdf->file->current->x,
	fdf->file->current->y - smll(fdf->file->current->z), fdf);
	fdf->file->current->next->win_x = x_iso(fdf->file->current->next->x,
	fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
	fdf->file->current->win_y = y_iso_down(fdf->file->current->x,
	fdf->file->current->y - smll(fdf->file->current->z), fdf);
	fdf->file->current->next->win_y = y_iso_down(fdf->file->current->next->x,
	fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
}

void		down_to_up(t_fdf *fdf)
{
	fdf->file->current->win_x = x_iso(fdf->file->current->x,
	fdf->file->current->y - smll(fdf->file->current->z), fdf);
	fdf->file->current->next->win_x = x_iso(fdf->file->current->next->x,
	fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
	fdf->file->current->win_y = y_iso_down(fdf->file->current->x,
	fdf->file->current->y - smll(fdf->file->current->z), fdf);
	fdf->file->current->next->win_y = y_iso_up(fdf->file->current->next->x,
	fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
}

void		up_to_down(t_fdf *fdf)
{
	fdf->file->current->win_x = x_iso(fdf->file->current->x,
	fdf->file->current->y - smll(fdf->file->current->z), fdf);
	fdf->file->current->next->win_x = x_iso(fdf->file->current->next->x,
	fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
	fdf->file->current->win_y = y_iso_up(fdf->file->current->x,
	fdf->file->current->y - smll(fdf->file->current->z), fdf);
	fdf->file->current->next->win_y = y_iso_down(fdf->file->current->next->x,
	fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
}

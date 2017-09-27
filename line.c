/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:45:06 by kboucaud          #+#    #+#             */
/*   Updated: 2017/06/09 15:45:07 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_co_win(t_fdf *fdf)
{
	if (fdf->file->current->z == fdf->file->current->next->z && fdf->file->current->z == 0)
	{
		fdf->file->current->win_x = x_iso(fdf->file->current->x, fdf->file->current->y, fdf);
		fdf->file->current->next->win_x = x_iso(fdf->file->current->next->x, fdf->file->current->next->y, fdf);
		fdf->file->current->win_y = y_iso(fdf->file->current->x, fdf->file->current->y, fdf);
		fdf->file->current->next->win_y = y_iso(fdf->file->current->next->x, fdf->file->current->next->y, fdf);
	}
	else if (fdf->file->current->z < fdf->file->current->next->z && fdf->file->current->z == 0)
	{
		fdf->file->current->win_x = x_iso(fdf->file->current->x, fdf->file->current->y - smll(fdf->file->current->z), fdf);
		fdf->file->current->next->win_x = x_iso(fdf->file->current->next->x, fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
		fdf->file->current->win_y = y_iso(fdf->file->current->x, fdf->file->current->y - smll(fdf->file->current->z), fdf);
		fdf->file->current->next->win_y = y_iso_up(fdf->file->current->next->x, fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
	}
	else if (fdf->file->current->z > fdf->file->current->next->z && fdf->file->current->next->z == 0)
	{
		fdf->file->current->win_x = x_iso(fdf->file->current->x, fdf->file->current->y - smll(fdf->file->current->z), fdf);
		fdf->file->current->next->win_x = x_iso(fdf->file->current->next->x, fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
		fdf->file->current->win_y = y_iso_up(fdf->file->current->x, fdf->file->current->y - smll(fdf->file->current->z), fdf);
		fdf->file->current->next->win_y = y_iso(fdf->file->current->next->x, fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
	}
	else
	{
		fdf->file->current->win_x = x_iso(fdf->file->current->x, fdf->file->current->y - smll(fdf->file->current->z), fdf);
		fdf->file->current->next->win_x = x_iso(fdf->file->current->next->x, fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
		fdf->file->current->win_y = y_iso_up(fdf->file->current->x, fdf->file->current->y - smll(fdf->file->current->z), fdf);
		fdf->file->current->next->win_y = y_iso_up(fdf->file->current->next->x, fdf->file->current->next->y - smll(fdf->file->current->next->z), fdf);
	}
}

void		ft_draw_x(t_fdf *fdf)
{
	int		i;

	i = 0;
	fdf->file->current = fdf->file->first_x;
	while (fdf->file->current->next != NULL)
	{
		while (fdf->file->current->next != NULL && i == fdf->file->current->next->x)
		{
				ft_co_win(fdf);
				ft_draw_seg(fdf);
				fdf->file->current = fdf->file->current->next;
		}
		if (fdf->file->current->next != NULL && i != fdf->file->current->next->x)
			fdf->file->current = fdf->file->current->next;
		i++;
	}
}

void		ft_draw_y(t_fdf *fdf)
{
	int		i;

	i = 0;
	fdf->file->current = fdf->file->first_y;
	while (fdf->file->current->next != NULL)
	{
		while (fdf->file->current->next != NULL && i == fdf->file->current->next->y)
		{
				ft_co_win(fdf);
				ft_draw_seg(fdf);
				fdf->file->current = fdf->file->current->next;
		}
		if (fdf->file->current->next != NULL && i != fdf->file->current->next->y)
			fdf->file->current = fdf->file->current->next;
		i++;
	}
}

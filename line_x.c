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

void		ft_line_x(t_coo co, int val1, int val2, t_fdf *fdf)
{
	t_seg	send;

	send = ft_line_x_under_1(co, val1, val2, fdf);
	if (send.xa != -1)
	{
		ft_draw_seg(send, fdf);
		return ;
	}
	else
		send = ft_line_x_under_2(co, val1, val2, fdf);
	ft_draw_seg(send, fdf);
	return ;
}

void		ft_draw_x(t_fdf *fdf)
{
	int		i;
	t_coo	co;

	i = 0;
	fdf->file->current = fdf->file->first_x;
	while (fdf->file->current->next != NULL)
	{
		while (fdf->file->current->next != NULL && fdf->file->current->next->x == i)
		{
			co.x = fdf->file->current->x;
			co.y = fdf->file->current->y;
			ft_line_x(co, fdf->file->current->z, fdf->file->current->next->z, fdf);
			fdf->file->current = fdf->file->current->next;
		}
		if (fdf->file->current->next != NULL && fdf->file->current->next->x != i)
			fdf->file->current = fdf->file->current->next;
		i++;
	}
}

t_seg		ft_line_x_under_1(t_coo co, int val1, int val2, t_fdf *fdf)
{
	t_seg		send;

	if (val1 == val2 && val1 == 0)
	{
		send.xa = x_iso(co.x, co.y, fdf);
		send.xb = x_iso(co.x, co.y + 1, fdf);
		send.ya = y_iso(co.x, co.y, fdf);
		send.yb = y_iso(co.x, co.y + 1, fdf);
		return (send);
	}
	if (val1 < val2 && val1 == 0)
	{
		send.xa = x_iso(co.x, co.y - smll(val1), fdf);
		send.xb = x_iso(co.x, co.y + 1 - smll(val2), fdf);
		send.ya = y_iso(co.x, co.y - smll(val1), fdf);
		send.yb = y_iso_up(co.x, co.y + 1 - smll(val2), fdf);
		return (send);
	}
	send.xa = -1;
	return (send);
}

t_seg		ft_line_x_under_2(t_coo co, int val1, int val2, t_fdf *fdf)
{
	t_seg	send;

	if (val1 > val2 && val2 == 0)
	{
		send.xa = x_iso(co.x, co.y - smll(val1), fdf);
		send.xb = x_iso(co.x, co.y + 1 - smll(val2), fdf);
		send.ya = y_iso_up(co.x, co.y - smll(val1), fdf);
		send.yb = y_iso(co.x, co.y + 1 - smll(val2), fdf);
		return (send);
	}
	else
	{
		send.xa = x_iso(co.x, co.y - smll(val1), fdf);
		send.xb = x_iso(co.x, co.y + 1 - smll(val2), fdf);
		send.ya = y_iso_up(co.x, co.y - smll(val1), fdf);
		send.yb = y_iso_up(co.x, co.y + 1 - smll(val2), fdf);
	}
	return (send);
}

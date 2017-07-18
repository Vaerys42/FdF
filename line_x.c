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

void		ft_line_x(t_coo co, int val1, int val2)
{
	t_seg	send;

	send = ft_line_x_under_1(co, val1, val2);
	if (send.xa != -1)
	{
		ft_draw_seg(send);
		return ;
	}
	else
		send = ft_line_x_under_2(co, val1, val2);
	ft_draw_seg(send);
	return ;
}

void		ft_draw_x(t_file *file)
{
	int		i;
	t_coo	co;

	i = 0;
	co.data = file->data;
	file->current =file->first_x;
	while (file->current->next != NULL)
	{
		while (file->current->next != NULL && file->current->next->x == i)
		{
			co.x = file->current->x;
			co.y = file->current->y;
			ft_line_x(co, file->current->z, file->current->next->z);
			file->current = file->current->next;
		}
		if (file->current->next != NULL && file->current->next->x != i)
			file->current = file->current->next;
		i++;
	}
}

t_seg		ft_line_x_under_1(t_coo co, int val1, int val2)
{
	t_seg		send;

	send.data = co.data;
	if (val1 == val2 && val1 == 0)
	{
		send.xa = x_iso(co.x, co.y);
		send.xb = x_iso(co.x, co.y + 1);
		send.ya = y_iso(co.x, co.y);
		send.yb = y_iso(co.x, co.y + 1);
		return (send);
	}
	if (val1 < val2 && val1 == 0)
	{
		send.xa = x_iso(co.x, co.y - smll(val1));
		send.xb = x_iso(co.x, co.y + 1 - smll(val2));
		send.ya = y_iso(co.x, co.y - smll(val1));
		send.yb = y_iso_up(co.x, co.y + 1 - smll(val2));
		return (send);
	}
	send.xa = -1;
	return (send);
}

t_seg		ft_line_x_under_2(t_coo co, int val1, int val2)
{
	t_seg	send;

	send.data = co.data;
	if (val1 > val2 && val2 == 0)
	{
		send.xa = x_iso(co.x, co.y - smll(val1));
		send.xb = x_iso(co.x, co.y + 1 - smll(val2));
		send.ya = y_iso_up(co.x, co.y - smll(val1));
		send.yb = y_iso(co.x, co.y + 1 - smll(val2));
		return (send);
	}
	else
	{
		send.xa = x_iso(co.x, co.y - smll(val1));
		send.xb = x_iso(co.x, co.y + 1 - smll(val2));
		send.ya = y_iso_up(co.x, co.y - smll(val1));
		send.yb = y_iso_up(co.x, co.y + 1 - smll(val2));
	}
	return (send);
}

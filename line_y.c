/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_y.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:45:17 by kboucaud          #+#    #+#             */
/*   Updated: 2017/06/09 15:45:18 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_line_y(t_coo co, int val1, int val2)
{
	t_seg		send;

	send = ft_line_y_under_1(co, val1, val2);
	if (send.xa != -1)
	{
		ft_draw_seg(send);
		return ;
	}
	else
		send = ft_line_y_under_2(co, val1, val2);
	ft_draw_seg(send);
	return ;
}

void		ft_draw_y(t_file *file)
{
	int		i;
	t_coo	co;

	i = 0;
	co.data = file->data;
	file->current = file->first_y;
	while (file->current->next != NULL)
	{
		while (file->current->next != NULL && file->current->next->y == i)
		{
			co.x = file->current->x;
			co.y = file->current->y;
			ft_line_y(co, file->current->z, file->current->next->z);
			file->current = file->current->next;
		}
		if (file->current->next != NULL && file->current->next->y != i)
			file->current = file->current->next;
		i++;
	}
}

t_seg		ft_line_y_under_1(t_coo co, int val1, int val2)
{
	t_seg		send;

	send.data = co.data;
	if (val1 == val2 && val1 == 0)
	{
		send.xa = x_iso(co.x, co.y);
		send.xb = x_iso(co.x + 1, co.y);
		send.ya = y_iso(co.x, co.y);
		send.yb = y_iso(co.x + 1, co.y);
		return (send);
	}
	if (val1 < val2 && val1 == 0)
	{
		send.xa = x_iso(co.x, co.y - smll(val1));
		send.xb = x_iso(co.x + 1, co.y - smll(val2));
		send.ya = y_iso(co.x, co.y - smll(val1));
		send.yb = y_iso_up(co.x + 1, co.y - smll(val2));
		return (send);
	}
	send.xa = -1;
	return (send);
}

t_seg		ft_line_y_under_2(t_coo co, int val1, int val2)
{
	t_seg		send;

	send.data = co.data;
	if (val1 > val2 && val2 == 0)
	{
		send.xa = x_iso(co.x, co.y - smll(val1));
		send.xb = x_iso(co.x + 1, co.y - smll(val2));
		send.ya = y_iso_up(co.x, co.y - smll(val1));
		send.yb = y_iso(co.x + 1, co.y - smll(val2));
		return (send);
	}
	else
	{
		send.xa = x_iso(co.x, co.y - smll(val1));
		send.xb = x_iso(co.x + 1, co.y - smll(val2));
		send.ya = y_iso_up(co.x, co.y - smll(val1));
		send.yb = y_iso_up(co.x + 1, co.y - smll(val2));
	}
	return (send);
}


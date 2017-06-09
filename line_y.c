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

int			ft_lst_len(t_file *file)
{
	int		max;

	max = 0;
	file->current = file->first;
	while (file->current->next != NULL)
	{
		while (file->current->y == max)
			file->current = file->current->next;
		max++;
	}
	return (max);
}

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
	int		y;
	int		max;
	int		prevz;
	t_coo	co;

	y = -1;
	max = ft_lst_len(file);
	prevz = -1;
	co.data = file->data;
	while (++y <= max)
	{
		file->current = file->first;
		while (file->current->next != NULL)
		{
			if (file->current->y == y && prevz != -1)
			{
				ft_line_y(co, prevz, file->current->z);
				prevz = -1;
			}
			if (file->current->y == y && prevz == -1)
			{
				co.x = file->current->x;
				co.y = y;
				prevz = file->current->z;
			}
			file->current = file->current->next;
		}
	}
}

t_seg		ft_line_y_under_1(t_coo co, int val1, int val2)
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

t_seg		ft_line_y_under_2(t_coo co, int val1, int val2)
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


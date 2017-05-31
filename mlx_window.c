/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:55:55 by kboucaud          #+#    #+#             */
/*   Updated: 2017/03/22 16:35:43 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			my_key_func(int key, void *param)
{
	if (key == 53)
		exit(1);
	return (0);
}

int			open_new(t_file *file)
{
	t_data		data;

	if ((data.mlx = mlx_init()) == NULL)
		return (-1);
	if ((data.mlx_window = mlx_new_window(data.mlx, 1000, 800, "Fdf")) == NULL)
		return (-2);
	file->data = data;
	//ft_draw_y(file);
	ft_draw_x(coo, data);
	mlx_key_hook(data.mlx_window, my_key_func, 0);
	mlx_loop(data.mlx);
	return (0);
}

double		smll(int x)
{
	return (x * 0.2);
}

void		ft_line_x(t_coo co, int val1, int val2)
{
	if (val1 == val2 && val1 == 0)
		ft_draw_seg(x_iso(co.x, co.y), x_iso(co.x + 1, co.y), y_iso(co.x, co.y), y_iso(co.x + 1, co.y), data);
	else if (val1 < val2 && val1 == 0)
		ft_draw_seg(x_iso(co.x, co.y - smll(val1)), x_iso(co.x + 1, co.y - smll(val2)), y_iso(co.x, co.y - smll(val1)), y_iso_up(co.x + 1, co.y - smll(val2)), data);
	else if (val1 > val2 && val2 == 0)
		ft_draw_seg(x_iso(co.x, co.y - smll(val1)), x_iso(co.x + 1, co.y - smll(val2)), y_iso_up(co.x, co.y - smll(val1)), y_iso(co.x + 1, co.y - smll(val2)), data);
	else
		ft_draw_seg(x_iso(co.x, co.y - smll(val1)), x_iso(co.x + 1, co.y - smll(val2)), y_iso_up(co.x, co.y - smll(val1)), y_iso_up(co.x + 1, co.y - smll(val2)), data);
	return ;
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
	return (NULL);
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

void		ft_line_y(t_coo co, int val1, int val2)
{
	t_seg		send;

	if (ft_line_y_under_1(co, val1, val2) != NULL)
		send = ft_line_y_under_1(co, val1, val2);
	else
		send = ft_line_y_under_2(co, val1, val2);
	ft_draw_seg(send);
	return ;
}

void		ft_draw_x(int **coo, t_data data)
{
	t_coo_int	co;

	co.x = 0;
	co.y = 0;
	while (coo[co.y][co.x] != -2)
	{
		while (coo[co.y][co.x] != -1 && coo[co.y][co.x] != -2)
		{
			//ft_line_x(co, coo[co.y][co.x], coo[co.y][co.x + 1], data);
			co.x++;
		}
		if (coo[co.y][co.x] == -1)
		{
			co.x = 0;
			co.y++;
		}
	}
}

void		ft_draw_y(t_file *file)
{
	int		i;
	t_coo 	co;

	i = 0;
	co.data = file->data;
	while (file->current->next != NULL)
	{
		while (file->current->y == i && file->current != NULL)
		{
			co.x = file->current->x;
			co.y = file->current->y;
			ft_line_y(co, file->current->z, file->current->next->z);
			file->current = file->current->next;
		}
		i++;
	}
}

double		x_iso(double x, double y)
{
	return ((x - y + 10) * 40);
}

double		y_iso_up(double x, double y)
{
	return ((x + y + 3) * 20);
}

double		y_iso(double x, double y)
{
	return ((x + y + 4) * 20);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:55:55 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/27 15:49:00 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

double		smll(int x)
{
	return (x * 0.2);
}

double		x_iso(double x, double y, t_fdf *fdf)
{
	return ((x - y + fdf->space + fdf->key->x) * fdf->scale);
}

double		y_iso_up(double x, double y, t_fdf *fdf)
{
	return ((x + y + 3 + fdf->key->y) * fdf->scale / 2);
}

double		y_iso_down(double x, double y, t_fdf *fdf)
{
	return ((x + y + 5 + fdf->key->y) * fdf->scale / 2);
}

double		y_iso(double x, double y, t_fdf *fdf)
{
	return ((x + y + 4 + fdf->key->y) * fdf->scale / 2);
}

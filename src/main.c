/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:35:08 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/28 16:24:16 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		ft_scale(t_fdf *fdf)
{
	int		len_y;
	int		len_x;

	fdf->file->current = fdf->file->first_y;
	len_x = ft_line_len_x(fdf->file);
	fdf->file->current = fdf->file->first_x;
	len_y = ft_line_len_y(fdf->file);
	fdf->space = len_y + 2;
	if (len_x > len_y)
		fdf->scale = 550 / len_x;
	else if (len_y >= len_x)
		fdf->scale = 550 / len_y;
	else
		fdf->scale = 0;
}

void		open_new(t_fdf *fdf)
{
	ft_scale(fdf);
	if (fdf->file->first_y != NULL)
		ft_draw_y(fdf);
	if (fdf->file->first_x != NULL)
		ft_draw_x(fdf);
}

int			main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
	{
		write(1, "Usage : ./fdf <filename> [ case_size z_size ]\n", 46);
		return (0);
	}
	if ((fdf = (t_fdf*)malloc(sizeof(t_fdf))) == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	fdf->file = ft_get_coord(argv[1]);
	ft_create(fdf);
	open_new(fdf);
	mlx_expose_hook(fdf->data->mlx_window, my_expose_hook, fdf);
	mlx_key_hook(fdf->data->mlx_window, my_key_func, fdf);
	mlx_put_image_to_window(fdf->data->mlx, fdf->data->mlx_window,
	fdf->data->mlx_image, 0, 0);
	mlx_loop(fdf->data->mlx);
	return (0);
}

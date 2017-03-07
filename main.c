/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:35:08 by kboucaud          #+#    #+#             */
/*   Updated: 2017/03/03 14:35:09 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	char	**file;
	int		x;
	int		y;

	x = 200;
	y = 200;
	if (argc != 2)
	{
		write(1, "Usage : ./fdf <filename> [ case_size z_size ]\n", 46);
		return (0);
	}
	file = ft_get_file(argv[1]);
	open_new();
}

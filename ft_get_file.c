/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:09:24 by kboucaud          #+#    #+#             */
/*   Updated: 2017/03/03 15:09:26 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		**ft_get_file(char *path)
{
	char	**file;
	int		fd;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, file[i]) > 0)
		i++;
	file[i] = 0;
	return (file);
}

t_coord		*ft_to_struct(char	**file)
{
	t_coord		*coo;
	char		**line;
	int			x;
	int			y;

	y = 0;
	x = 0;
	while (file[y] != 0)
	{
		x = 0;
		line = ft_strsplit(file[y], ' ');
		while (line[x++] != NULL)
		{
			coo->x = x;
			coo->y = y;
			coo->z = ft_atoi(line[x]);
			x++;
			coo = coo->next;
		}
		y++;
	}
	coo->next = NULL;
	return (coo);
}
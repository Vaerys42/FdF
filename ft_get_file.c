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
	int		i;
	int		j;
	t_coord		*cord_list;

	i = 0;
	while (file[i] != 0)
	{
		j = 0;
		while (file[i][j] != 0)
		{
			coord_list->x = j;
			coord_list->y = i;
			coord_list->z = ft_atoi(file[i][j]);
			coord_list = coord_list->next;
			j++;
		}
		i++;
	}
	coord_list->next = NULL;
}
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
	file = NULL;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, file[i]) > 0)
		i++;
	file[i] = 0;
	return (file);
}

int			**ft_coo_tab(char **tab, int length, int height)
{
	int		**coo_tab;
	char	**split;
	int		i;
	int		j;

	i = 0;
	coo_tab = (int**)malloc(sizeof(int) * (height - 1));
	while (tab[i] != 0)
	{
		j = 0;
		split = ft_strsplit(tab[i], ' ');
		coo_tab[i] = (int*)malloc(sizeof(int) * (length));
		while (split[j] != 0)
		{
			coo_tab[i][j] = ft_atoi(split[j]);
			j++;
		}
		coo_tab[i][j] = -1;
		free(split);
	}
	coo_tab[i - 1][j] = -2;
	return (coo_tab);
}

int			**ft_get_coo(char *path)
{
	char	**file;
	int		**coo;
	int		length;
	int		height;

	length = 0;
	height = 0;
	file = ft_get_file(path);
	while (file[height][length] != 0)
		length++;
	while (file[height] != 0)
		height++;
	coo = ft_coo_tab(file, length, height);
	return (coo);
}

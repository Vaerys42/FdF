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

void		ft_error(void)
{
	write(1, "error\n", 6);
	exit(1);
}

char		**read_file(char *path)
{
	int		fd;
	char	**line;
	char	*tmp;
	int		ret;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	while ((ret = get_next_line(fd, &tmp)) > 0)
		i++;
	if (ret == -1)
		ft_error();
	line = (char**)malloc(sizeof(char*) * (i + 1));
	close(fd);
	i = 0;
	fd = open(path, O_RDONLY);
	while ((ret = get_next_line(fd, &tmp)) > 0)
	{
		line[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	if (ret == -1)
		ft_error();
	line[i] = 0;
	close(fd);
	return (line);
}

void		ft_check_char(char **file)
{
	int		i;
	int		j;

	i = -1;
	while (file[++i] != 0)
	{
		j = -1;
		while (file[i][++j] != 0)
		{
			if (file[i][j] != ' ' && (file[i][j] < 60 && file[i][j] > 71))
				ft_error();
		}
	}
}

t_file		*ft_add_list(t_file *file, int x, int y, int z)
{
	t_one		*new;

	if (!file)
		ft_error();
	new = (t_one*)malloc(sizeof(*new));
	if (!new)
		ft_error();
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
	while (file->current->next != NULL)
		file->current = file->current->next;
	file->current->next = new;
	if (file->first->next == NULL)
		file->first->next = file->current->next;
	return (file);
}

t_file		*ft_new_list(int x, int y, int z)
{
	t_file		*file;
	t_one		*ini;

	file = (t_file*)malloc(sizeof(*file));
	if (!file)
		ft_error();
	ini = (t_one*)malloc(sizeof(*ini));
	if (!ini)
		ft_error();
	ini->x = x;
	ini->y = y;
	ini->z = z;
	ini->next = NULL;
	file->first = ini;
	file->current = ini;
	return (file);
}

t_file		*ft_parse(char **reader)
{
	int		x;
	int		y;
	char	**tab;
	t_file	*file;

	y = 0;
	while (reader[y] != 0)
	{
		x = 0;
		tab = ft_strsplit(reader[y], ' ');
		if (x == 0 && y == 0)
		{
			file = ft_new_list(0, 0, ft_atoi(tab[0]));
			x++;
		}
		while (tab[x] != NULL)
		{
			file = ft_add_list(file, x, y, ft_atoi(tab[x]));
			x++;
		}
		free(tab);
		y++;
	}
	return (file);
}

t_file		*ft_get_coord(char *path)
{
	char	**reader;
	t_file	*file;

	reader = read_file(path);
	write(1, "", 0);
	ft_check_char(reader);
	ft_putstr("read & check OK\n");
	file = ft_parse(reader);
	ft_putstr("parse OK\n");
	return (file);
}

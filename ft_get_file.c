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
	if ((line = (char**)malloc(sizeof(char*) * (i + 1))) == NULL)
		ft_error();
	close(fd);
	i = 0;
	fd = open(path, O_RDONLY);
	while ((ret = get_next_line(fd, &tmp)) > 0)
	{
		line[i++] = ft_strdup(tmp);
		free(tmp);
	}
	line[i] = 0;
	close(fd);
	return (line);
}

void		ft_check_char(char **file)
{
	int		i;
	int		j;

	i = 0;
	while (file[i] != 0)
	{
		j = 0;
		while (file[i][j] != 0)
		{
			if (file[i][j] != ' ' && ft_isdigit(file[i][j]) == 0)
				ft_error();
			j++;
		}
		i++;
	}
}

void		ft_check_len(t_file *file)
{
	int		len;
	int		i;

	len = 0;
	file->current = file->first_x;
	len = ft_line_len(file);
	while (file->current->next != NULL)
	{
		i = ft_line_len(file);
		if (file->current->y != file->current->next->y
		&& file->current->next != NULL)
			file->current = file->current->next;
		if (len != i)
			ft_error();
	}
}

t_file		*ft_parse(char **reader)
{
	t_file	*file;
	int		len;

	len = 0;
	while (reader[len] != 0)
		len++;
	file = ft_create_y(reader);
	ft_create_x(reader, file);
	return (file);
}

t_file		*ft_get_coord(char *path)
{
	char	**reader;
	t_file	*file;

	reader = read_file(path);
	write(1, "", 0);
	ft_check_char(reader);
	file = ft_parse(reader);
	ft_check_len(file);
	return (file);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:01:14 by vbrazas           #+#    #+#             */
/*   Updated: 2018/05/24 20:07:21 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	ssize_t	find_n(const char *mas)
{
	ssize_t		i;

	i = 0;
	while (mas[i] && mas[i] != '\n')
		i++;
	return (i);
}

static	int		write_arr(char **arr, ssize_t *ret, const int fd, char *fr_arr)
{
	char		*buf;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((*arr)[find_n(*arr)] != '\n' && (*ret = read(fd, buf, BUFF_SIZE)))
	{
		if (*ret < 0)
			return (-1);
		buf[(*ret)] = '\0';
		fr_arr = *arr;
		if (!((*arr) = ft_strjoin(*arr, buf)))
			return (-1);
		free(fr_arr);
	}
	free(buf);
	return (0);
}

static	int		get_first_line(char **arr, char **line, ssize_t ret)
{
	ssize_t			i;
	char			*free_old_arr;

	free_old_arr = NULL;
	i = find_n(*arr);
	if ((*arr)[i] == '\n' || (i && !ret))
	{
		if (!((*line) = ft_strsub(*arr, 0, i)))
			return (-1);
		free_old_arr = *arr;
		*arr = ft_strsub(*arr, (i + 1), (ft_strlen(*arr) - i));
		free(free_old_arr);
	}
	else
		return (0);
	return (1);
}

static	int		make_new_fd(const int fd, t_gnl **poi, t_gnl *l)
{
	if (!((*poi) = (t_gnl *)malloc(sizeof(t_gnl))))
		return (-1);
	if (!((*poi)->arr = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
	{
		free(*poi);
		return (-1);
	}
	(*poi)->fd = fd;
	(*poi)->next = NULL;
	while (l && l->next && fd != l->fd)
		l = l->next;
	if (l && !(l->next))
		l->next = *poi;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static	t_gnl	*l;
	t_gnl			*poi;
	char			*free_old_arr;
	ssize_t			ret;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	free_old_arr = NULL;
	if (!l && (make_new_fd(fd, &l, NULL) == -1))
		return (-1);
	poi = l;
	while (poi && fd != poi->fd)
		poi = poi->next;
	if (!poi && (make_new_fd(fd, &poi, l) == -1))
		return (-1);
	if (write_arr(&(poi->arr), &ret, fd, free_old_arr) == -1)
		return (-1);
	return (get_first_line(&(poi->arr), line, ret));
}

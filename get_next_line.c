/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 04:41:41 by vbrazas           #+#    #+#             */
/*   Updated: 2019/02/15 02:55:04 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define CSTR(x)		((char *)(x)->content)
#define STR(x)		(x)->content
#define FD(x)		(x)->content_size

static t_list		*get_node(int fd, t_list **head)
{
	t_list			*node;

	if (!*head)
	{
		*head = ft_memalloc(sizeof(t_list));
		FD(*head) = fd;
		return (*head);
	}
	node = *head;
	while (node)
	{
		if ((int)FD(node) == fd)
			return (node);
		if (!node->next)
			break ;
		node = node->next;
	}
	node->next = ft_memalloc(sizeof(t_list));
	FD(node->next) = fd;
	return (node->next);
}

static int			get_line(t_list *l, char **line, char *n_pos)
{
	char			*tmp;

	if (!STR(l) || !*CSTR(l))
		return (0);
	if (n_pos)
	{
		*line = ft_strsub(STR(l), 0, n_pos - CSTR(l));
		tmp = STR(l);
		STR(l) = ft_strdup(n_pos + 1);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(STR(l));
		ft_strdel((char**)&STR(l));
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*head = NULL;
	t_list			*l;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	l = get_node(fd, &head);
	if (STR(l) && (tmp = ft_strchr(STR(l), '\n')))
		return (get_line(l, line, tmp));
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = STR(l);
		STR(l) = ft_strjoin(STR(l), buf);
		ft_strdel(&tmp);
		if ((tmp = ft_strchr(STR(l), '\n')))
			break ;
	}
	return (get_line(l, line, tmp));
}

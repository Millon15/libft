/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:03:52 by vbrazas           #+#    #+#             */
/*   Updated: 2017/11/12 18:22:37 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*buf;
	t_list	*new_list;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	buf = f(lst);
	if (!(new_list = ft_lstnew(buf->content, buf->content_size)))
		return (NULL);
	start = new_list;
	lst = lst->next;
	while (lst)
	{
		buf = f(lst);
		if (!(new_list->next = ft_lstnew(buf->content, buf->content_size)))
		{
			ft_lstdel(&start, &ft_lstdelcont);
			return (NULL);
		}
		new_list = new_list->next;
		lst = lst->next;
	}
	return (start);
}

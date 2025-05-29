/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:07:02 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/06/18 18:30:48 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_gnl	*rest[MAX_FD + 1];
	t_gnl			*lst;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD || read(fd, NULL, 0) < 0)
		return (NULL);
	line = NULL;
	lst = rest[fd];
	if (lst)
		lst->nl = ft_strchr(lst->buf, '\n');
	else
		lst = ft_create_newnode(lst);
	if (!lst)
		return (NULL);
	if (!lst->nl && !lst->eof && ft_read_fd(fd, lst) == ERROR)
	{
		rest[fd] = NULL;
		return (ft_gnl_clear(&lst), NULL);
	}
	ft_create_line(lst, &line);
	if (!line && !lst->eof)
		return (ft_gnl_clear(&lst), NULL);
	ft_save_rest(lst, rest, fd);
	return (line);
}

int	ft_read_fd(int fd, t_gnl *lst)
{
	int	rd_sum;

	rd_sum = lst->len;
	while (!lst->nl)
	{
		if (lst->buf)
		{
			lst->next = ft_create_newnode(lst->next);
			if (!lst->next)
				return (ERROR);
			lst = lst->next;
		}
		lst->len = read(fd, lst->buf, BUFFER_SIZE);
		if (lst->len == ERROR)
			return (ERROR);
		else if (!lst->len)
			lst->eof = 1;
		lst->len_sum = rd_sum + lst->len;
		if (lst->eof)
			break ;
		rd_sum += lst->len;
		lst->nl = ft_strchr(lst->buf, '\n');
	}
	lst->len_sum = rd_sum;
	return (SUCCS);
}

void	ft_create_line(t_gnl *lst, char **line)
{
	t_gnl	*last;

	last = lst;
	while (last->next)
		last = last->next;
	if (last->nl)
		last->len_sum -= last->len - (last->nl - last->buf + 1);
	if (last->len_sum)
		*line = malloc(last->len_sum + 1);
	else if (last->eof)
		lst->eof = 1;
	if (!*line)
		return ;
	ft_bzero(*line, last->len_sum + 1);
	while (lst)
	{
		if (!lst->nl && *(lst->buf))
			ft_strncat(*line, lst->buf, last->len_sum + 1);
		else if (*(lst->buf))
			ft_strncat(*line, lst->buf, (lst->nl - lst->buf) + 2);
		lst = lst->next;
	}
}

void	ft_save_rest(t_gnl *lst, t_gnl *rest[], int fd)
{
	t_gnl	*last;

	last = lst;
	while (last->next)
		last = last->next;
	if (!last->nl)
	{
		if (lst->next)
			ft_gnl_clear(&lst);
		rest[fd] = NULL;
		return ;
	}
	last->nl++;
	*(lst->buf) = 0;
	ft_strncat(lst->buf, last->nl, ft_strlen(last->nl) + 1);
	if (lst->next)
		ft_gnl_clear(&(lst->next));
	lst->next = NULL;
	lst->len = ft_strlen(lst->buf);
	lst->len_sum = lst->len;
	rest[fd] = lst;
}

void	*ft_create_newnode(t_gnl *node)
{
	node = malloc(sizeof(t_gnl));
	if (!node)
		return (NULL);
	ft_bzero(node, sizeof(t_gnl));
	node->buf = malloc(BUFFER_SIZE + 1);
	if (!node->buf)
		return (NULL);
	ft_bzero(node->buf, BUFFER_SIZE + 1);
	return (node);
}

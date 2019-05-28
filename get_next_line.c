/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:59:54 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/25 17:06:54 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_bufffree(int fd, t_list **list, int ret)
{
	t_list	*head;
	t_list	*previous;
	t_buff	*buff;

	head = *list;
	previous = NULL;
	while (head)
	{
		buff = head->content;
		if (buff->fd == fd)
		{
			if (previous)
				previous->next = head->next;
			else
				*list = head->next;
			ft_memdel((void **)&(buff->data));
			ft_memdel((void **)&buff);
			ft_memdel((void **)&head);
			return (ret);
		}
		previous = head;
		head = head->next;
	}
	return (GNL_ERROR);
}

static int	ft_buffget(int fd, t_list **list, t_buff **buff)
{
	t_list	*head;

	head = *list;
	while (head)
	{
		*buff = head->content;
		if ((*buff)->fd == fd)
			return (GNL_OK);
		head = head->next;
	}
	if (!(*buff = (t_buff *)malloc(sizeof(t_buff))))
		return (0);
	(*buff)->fd = fd;
	(*buff)->size = 0;
	(*buff)->cmd = GNL_READ;
	if (!((*buff)->data = ft_strnew(BUFF_SIZE)))
		return (0);
	if (!(head = ft_lstnew(*buff, sizeof(t_buff))))
		return (0);
	ft_memdel((void **)buff);
	ft_lstadd(list, head);
	return (ft_buffget(fd, list, buff));
}

static int	ft_bufflock(t_buff **buff, char **line)
{
	size_t	section_len;
	char	*endl_position;
	size_t	new_line_len;

	endl_position = NULL;
	section_len = BUFF_SIZE;
	if ((endl_position = ft_strchr((*buff)->data, GNL_ENDL)))
	{
		(*buff)->cmd = GNL_SEND;
		section_len = endl_position - (*buff)->data;
	}
	new_line_len = ft_strlen(*line) + section_len + 1;
	if (!(*line = (char *)ft_memrealloc(*line, new_line_len)))
		return (0);
	ft_strncat(*line, (*buff)->data, section_len);
	if (endl_position)
		ft_strncpy((*buff)->data, endl_position + 1, BUFF_SIZE);
	else
		ft_bzero((*buff)->data, BUFF_SIZE + 1);
	(*buff)->size = BUFF_SIZE - section_len;
	return (GNL_OK);
}

static int	ft_lineread(int fd, char **line, t_list **list, t_buff **buff)
{
	while ((*buff)->cmd == GNL_READ)
	{
		if (!(*buff)->size)
		{
			(*buff)->size = read(fd, (*buff)->data, BUFF_SIZE);
			if ((*buff)->size <= 0)
			{
				if (!(*buff)->size && ft_strlen(*line))
					return (GNL_OK);
				return (ft_bufffree(fd, list, (*buff)->size));
			}
		}
		if (!ft_bufflock(buff, line))
			return (ft_bufffree(fd, list, GNL_ERROR));
	}
	if ((*buff)->cmd == GNL_SEND)
	{
		(*buff)->cmd = GNL_READ;
		return (GNL_OK);
	}
	return (ft_bufffree(fd, list, GNL_EOF));
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_buff			*buff;

	if (!line || fd < 0 || !BUFF_SIZE)
		return (ft_bufffree(fd, &list, GNL_ERROR));
	if (*line)
		ft_strdel(line);
	if (!(*line = ft_strnew(BUFF_SIZE)))
		return (ft_bufffree(fd, &list, GNL_ERROR));
	if (!ft_buffget(fd, &list, &buff))
		return (ft_bufffree(fd, &list, GNL_ERROR));
	return (ft_lineread(fd, line, &list, &buff));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 12:42:02 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/30 18:24:30 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>

/*
static int	line_concat(char **line, int *line_len, t_buf *buffer)
{
	char	*endl_pos;
	int		rest_len;

	rest_len = buffer->len;
	endl_pos = ft_memchr(buffer->arr, '\n', rest_len);
	if (endl_pos)
		rest_len = endl_pos - buffer->arr;
	*line = ft_memrealloc(*line, *line_len, *line_len + rest_len);
	if (!*line)
		return (FT_ERROR);
	ft_memmove(*line + *line_len, buffer->arr, rest_len);
	*line_len += rest_len;
	return (1);
}

static int	buffer_update(t_buf *buffer)
{
	char	*endl_pos;
	size_t	blank_len;

	endl_pos = ft_memchr(buffer->arr, '\n', buffer->len);
	if (!endl_pos)
	{
		ft_bzero(buffer->arr, BUFF_SIZE);
		buffer->len = 0;
		return (0);
	}
	blank_len = endl_pos - buffer->arr + 1;
	buffer->len = BUFF_SIZE - blank_len;
	ft_putnbr(buffer->len);
	ft_putendl("");
	ft_putnbr(blank_len);
	ft_putendl("");
	ft_memmove(buffer->arr, endl_pos + 1, buffer->len);
	ft_bzero(buffer->arr + buffer->len, blank_len);
	return (1);
}

static int	transfer_toline(char **line, int *line_len, t_buf *buffer)
{
	if (!buffer->len)
		return (0);
	if (line_concat(line, line_len, buffer) < 0)
		return (FT_ERROR);
	if (buffer_update(buffer))
		return (1);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_buf	buffer;
	int				newline;
	int				read_bytes;
	int				line_len;
	
	if (fd < 1 || !line)
		return (FT_ERROR);	
	ft_strdel(line);
	line_len = 0;
	if ((newline = transfer_toline(line, &line_len, &buffer)) != 0)
		return (newline);
	while ((read_bytes = read(fd, buffer.arr, BUFF_SIZE)))
	{
		if (read_bytes < 0)
			return (FT_ERROR);
		buffer.len = read_bytes;
		if ((newline = transfer_toline(line, &line_len, &buffer) != 0))
			return (newline);
		if (read_bytes < BUFF_SIZE)
			break ;
	}
	return ((read_bytes > 0));
}
*/


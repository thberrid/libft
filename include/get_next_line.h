/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 09:56:51 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/25 18:43:05 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <libft.h>

# define BUFF_SIZE 1

# define GNL_ERROR -1
# define GNL_EOF 0
# define GNL_OK	1
# define GNL_READ 2
# define GNL_SEND 3

# define GNL_ENDL '\n'

typedef struct	s_buff
{
	int		fd;
	char	*data;
	int		cmd;
	int		size;
}				t_buff;

int				get_next_line(const int fd, char **line);

#endif

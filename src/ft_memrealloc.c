/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:02:51 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/30 14:55:51 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memrealloc(void *src, size_t old_size, size_t new_size)
{
	char	*dst;

	dst = ft_memalloc(new_size);
	if (!dst)
		return (NULL);
	ft_bzero(dst, new_size);
	ft_memcpy(dst, src, old_size);
	ft_memdel(&src);
	return (dst);
}

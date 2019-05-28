/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:02:51 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/28 16:15:26 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memrealloc(void *src, size_t size)
{
	char	*dst;

	dst = ft_memalloc(size);
	if (dst)
		dst = ft_memcpy(dst, src, size);
	ft_memdel(&src);
	return (dst);
}

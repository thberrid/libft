/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:02:51 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/25 18:41:53 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memrealloc(void *ptr, size_t size)
{
	char	*new;

	new = ft_memalloc(size);
	if (new)
		new = ft_strcpy(new, ptr);
	ft_memdel(&ptr);
	return (new);
}

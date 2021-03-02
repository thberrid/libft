/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulonglen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:30:06 by thberrid          #+#    #+#             */
/*   Updated: 2021/03/01 14:30:08 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_ulonglen(unsigned long n, const char *base)
{
	int		len;
	int		base_len;

	base_len = ft_strlen(base);
	len = 0;
	while (n)
	{
		n /= base_len;
		len += 1;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 21:35:01 by thberrid          #+#    #+#             */
/*   Updated: 2021/02/24 21:35:03 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_intlen(int n, const char *base)
{
	int		len;
	int		base_len;

	base_len = ft_strlen(base);
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len += 1;
	}
	while (n)
	{
		n /= base_len;
		len += 1;
	}
	return (len);
}

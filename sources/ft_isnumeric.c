/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:22:38 by thberrid          #+#    #+#             */
/*   Updated: 2021/07/01 16:28:49 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_isnumeric(const char *s)
{
	int		index;
	int		len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	if (!len)
		return (0);
	index = 0;
	while (s[index])
	{
		if (index == 0)
		{
			if (!ft_isdigit(s[index]) && s[index] != '-')
				return (0);
		} else if (!ft_isdigit(s[index]))
			return (0);
		index += 1;
	}
	return (1);
}

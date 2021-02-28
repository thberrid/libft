/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:41:43 by thberrid          #+#    #+#             */
/*   Updated: 2021/02/28 14:41:46 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoabase(int n, const char *base)
{
	int		baselen;
	char	*str;
	int		strlen;
	int		index;
	
	if (!base)
		base = PFB_DEC;
	baselen = ft_strlen(base);
	strlen = ft_intlen(n, base);
	index = 0;
	if (!(str = ft_strnew(strlen)))
		return (NULL);
	while (n)
	{
		str[index] = base[n % baselen];
		n /= baselen;
		index += 1;
	}
	return (str);
}
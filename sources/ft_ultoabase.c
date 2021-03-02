/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:17:26 by thberrid          #+#    #+#             */
/*   Updated: 2021/03/01 14:17:27 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_ultoabase(unsigned long n, const char *base)
{
	int		baselen;
	char	*str;
	int		strlen;
	int		index;
	int		exponent;

	if (!base)
		base = BASE_DEC;
	baselen = ft_strlen(base);
	strlen = ft_ulonglen(n, base);
	index = 0;
	if (!(str = ft_strnew(strlen)))
		return (NULL);
	exponent = ft_longexponent(n, baselen);
	while (exponent)
	{
		str[index] = base[n / exponent];
		n %= exponent;
		exponent /= baselen;
		index += 1;
	}
	return (str);
}
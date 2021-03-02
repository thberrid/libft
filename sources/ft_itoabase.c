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
	int		exponent;

	if (!base)
		base = BASE_DEC;
	baselen = ft_strlen(base);
	strlen = ft_intlen(n, base);
	index = 0;
	if (!(str = ft_strnew(strlen)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		index += 1;
		n *= -1;
	}
	exponent = ft_intexponent(n, baselen);
	while (n)
	{
		str[index] = base[n / exponent];
		n %= exponent;
		exponent /= baselen;
		index += 1;
	}
	return (str);
}
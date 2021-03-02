/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:12:57 by thberrid          #+#    #+#             */
/*   Updated: 2021/02/28 15:13:00 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	put_radix(int radix, char *str)
{
	int		index = 0;
	int		decimal;

	index = 0;
	if (radix < 0)
	{
		index += 1;
		str[0] = '-';
		radix *= -1;
	}
	decimal = ft_intexponent(radix, 10);
	while (decimal)
	{
		str[index] = (radix / decimal) + '0';
		radix %= decimal;
		decimal /= 10;
		index += 1;
	}
	return (index);
}

char	*ft_ftoa(float f, int precision)
{
	char	*str;
	int		radix;
	int		index;
	int		len;

	radix = (int)f;
	f -= (float)radix;
	if (precision)
		precision += 1;
	len = ft_intlen(radix, BASE_DEC) + precision;
	if (!(str = ft_strnew(len)))
		return (NULL);
	index = put_radix(radix, str);
	if (!precision)
		return (str);
	str[index] = '.';
	index += 1;
	while (index < len)
	{
		f *= 10;
		radix = (int)f;
		str[index] = radix + '0';
		f -= (float)radix;
		index += 1;
	}
	return (str);
}
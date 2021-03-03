/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulongexponent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:42:19 by thberrid          #+#    #+#             */
/*   Updated: 2021/03/02 11:42:24 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_ulongexponent(unsigned long n, unsigned int baselen)
{
	unsigned long		exponent;

	exponent = 1;
	while (exponent && (n / exponent >= baselen))
		exponent *= baselen;
	return (exponent);
}

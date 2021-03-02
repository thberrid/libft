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

int	ft_ulongexponent(unsigned long n, int baselen)
{
	int		exponent;

	exponent = 1;
	while (n / exponent >= (unsigned int)baselen)
		exponent *= baselen;
	return (exponent);
}

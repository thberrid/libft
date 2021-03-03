/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longexponent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 23:07:03 by thberrid          #+#    #+#             */
/*   Updated: 2021/03/01 23:07:32 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_longexponent(long n, int baselen)
{
	long	exponent;

	exponent = 1;
	while (n / exponent >= baselen)
		exponent *= baselen;
	return (exponent);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intexponent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 23:06:22 by thberrid          #+#    #+#             */
/*   Updated: 2021/03/01 23:06:31 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_intexponent(int n, int baselen)
{
	int		exponent;

	exponent = 1;
	while (n / exponent >= baselen)
		exponent *= baselen;
	return (exponent);
}

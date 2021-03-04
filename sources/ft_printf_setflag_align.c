/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_setflag_align.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 00:05:49 by thberrid          #+#    #+#             */
/*   Updated: 2021/03/04 00:05:51 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		fset_zero(t_pf_flag *flags, const char *fmt)
{
	(void)fmt;
	if (flags->padd_fill)
		return (0);
	flags->padd_fill = '0';
	return (1);
}

int		fset_space(t_pf_flag *flags, const char *fmt)
{
	(void)fmt;
	if (flags->padd_fill)
		return (0);
	flags->padd_fill = ' ';
	return (1);
}

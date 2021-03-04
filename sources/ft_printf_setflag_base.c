/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_setflag_base.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 00:03:44 by thberrid          #+#    #+#             */
/*   Updated: 2021/03/04 00:03:46 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		fset_oct(t_pf_flag *flags, const char *fmt)
{
	(void)fmt;
	if (flags->base)
		return (0);
	flags->base = BASE_OCT;
	if (!flags->type)
		flags->type = PFT_INT;
	return (1);
}

int		fset_dec(t_pf_flag *flags, const char *fmt)
{
	(void)fmt;
	if (flags->base)
		return (0);
	if (!flags->type)
		flags->type = PFT_INT;
	flags->base = BASE_DEC;
	return (1);
}

int		fset_bin(t_pf_flag *flags, const char *fmt)
{
	(void)fmt;
	if (flags->base)
		return (0);
	flags->base = BASE_BIN;
	if (!flags->type)
		flags->type = PFT_INT;
	return (1);
}

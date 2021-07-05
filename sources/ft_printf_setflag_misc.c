/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_setflag_misc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 00:07:00 by thberrid          #+#    #+#             */
/*   Updated: 2021/03/04 00:07:02 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		fset_percent(t_pf_flag *flags, const char *fmt)
{
	(void)fmt;
	if (flags->type)
		return (1);
//	if (flags->fieldlen || flags->padd_fill || flags->precision || flags->base)
//		return (0);
//	if (!ft_isspace(fmt[1]))
//		return (0);
	flags->padd_fill = '%';
	flags->type = PFT_CHAR;
	flags->fieldlen = 1;
	return (1);
}

int		fset_precision(t_pf_flag *flags, const char *fmt)
{
	if (flags->precision)
		return (0);
	if (!ft_isdigit(fmt[1]) || fmt[1] == '0')
		return (0);
	flags->precision = ft_atoi(&fmt[1]);
	return (ft_intlen(flags->precision, BASE_DEC));
}

int		fset_len(t_pf_flag *flags, const char *fmt)
{
	int		retrn;

	(void)fmt;
	if (flags->fieldlen)
		return (0);
	if (!flags->padd_fill)
		flags->padd_fill = ' ';
	flags->fieldlen = ft_atoi(fmt);
	retrn = 0;
	while (ft_isdigit(fmt[retrn]))
		retrn += 1;
	return (retrn);
}

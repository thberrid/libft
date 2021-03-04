/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_setflag_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 00:04:56 by thberrid          #+#    #+#             */
/*   Updated: 2021/03/04 00:04:57 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		fset_float(t_pf_flag *flags, const char *fmt)
{
	(void)fmt;
	if (flags->type)
		return (0);
	if (flags->base)
		return (0);
	flags->base = BASE_DEC;
	flags->type = PFT_FLOAT;
	return (1);
}

int		fset_char(t_pf_flag *flags, const char *fmt)
{
	(void)fmt;
	if (flags->type)
		return (0);
	flags->type = PFT_CHAR;
	return (1);
}

int		fset_str(t_pf_flag *flags, const char *fmt)
{
	(void)fmt;
	if (flags->type)
		return (0);
	flags->type = PFT_STR;
	return (1);
}

int		fset_ptr(t_pf_flag *flags, const char *fmt)
{
	(void)fmt;
	if (flags->type)
		return (0);
	flags->type = PFT_PTR;
	return (1);
}

int		fset_long(t_pf_flag *flags, const char *fmt)
{
	(void)fmt;
	flags->type = PFT_LONG;
	return (1);
}

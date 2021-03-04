/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_vaarg_numeric.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 00:09:21 by thberrid          #+#    #+#             */
/*   Updated: 2021/03/04 00:09:23 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		vaarg_getptr(t_pf_flag *flags, char **s, va_list ap)
{
	void	*arg;
	size_t	s_len;

	arg = va_arg(ap, void *);
	if (!flags->base)
		flags->base = BASE_OCTUP;
	*s = ft_ultoabase((unsigned long)arg, flags->base);
	if (!s)
		return (0);
	s_len = ft_strlen(*s);
	if (!flags->fieldlen)
		flags->fieldlen = s_len;
	return (1);
}

int		vaarg_getint(t_pf_flag *flags, char **s, va_list ap)
{
	int		arg;
	size_t	s_len;

	arg = va_arg(ap, int);
	if (!flags->base)
		flags->base = BASE_DEC;
	*s = ft_itoabase(arg, flags->base);
	if (!s)
		return (0);
	s_len = ft_strlen(*s);
	if (!flags->fieldlen)
		flags->fieldlen = s_len;
	return (1);
}

int		vaarg_getfloat(t_pf_flag *flags, char **s, va_list ap)
{
	float	arg;
	size_t	s_len;

	arg = (float)va_arg(ap, double);
	if (!flags->precision)
		flags->precision = PF_DEFAULT_PRECISION;
	if (!(*s = ft_ftoa(arg, flags->precision)))
		return (0);
	s_len = ft_strlen(*s);
	if (!flags->fieldlen)
		flags->fieldlen = s_len;
	return (1);
}

int		vaarg_getlong(t_pf_flag *flags, char **s, va_list ap)
{
	long	arg;
	size_t	s_len;

	arg = va_arg(ap, long);
	if (!flags->base)
		flags->base = BASE_DEC;
	*s = ft_ltoabase(arg, flags->base);
	if (!s)
		return (0);
	s_len = ft_strlen(*s);
	if (!flags->fieldlen)
		flags->fieldlen = s_len;
	return (1);
}

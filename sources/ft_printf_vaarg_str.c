/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_vaarg_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 00:12:35 by thberrid          #+#    #+#             */
/*   Updated: 2021/03/04 00:12:36 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		vaarg_getpercent(t_pf_flag *flags, char **s, va_list ap)
{
	(void)ap;
	*s = ft_strdup("%");
	if (!*s)
		return (0);
	flags->fieldlen = 1;
	return (1);
}

int		vaarg_getchar(t_pf_flag *flags, char **s, va_list ap)
{
	char	arg;

	if (flags->padd_fill == '%')
		arg = '%';
	else
		arg = (char)va_arg(ap, int);
	*s = ft_strdup(&arg);
	if (!s)
		return (0);
	if (!flags->fieldlen)
		flags->fieldlen = 1;
	return (1);
}

int		vaarg_getstr(t_pf_flag *flags, char **s, va_list ap)
{
	char	*arg;
	size_t	s_len;

	arg = va_arg(ap, char *);
	if (!s)
		return (0);
	if (!(*s = ft_strdup(arg)))
		return (0);
	s_len = ft_strlen(*s);
	if (!flags->fieldlen)
		flags->fieldlen = s_len;
	return (1);
}

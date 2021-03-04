/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:08:33 by thberrid          #+#    #+#             */
/*   Updated: 2021/02/24 15:08:34 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	flags_getlen(const char *str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (ft_isspace(str[index]))
			break ;
		index += 1;
	}
	return (index);
}

static int	arg_print(int fd, const char *fmt, va_list ap)
{
	t_pf_flag	flags;
	int			retrn;
	char		*str;

	str = NULL;
	ft_bzero(&flags, sizeof(t_pf_flag));
	retrn = flags_parse(&flags, fmt);
	if (retrn)
		retrn = vaarg_get(&flags, &str, ap);
	else
		write(2, "ft_printf: parse error\n", 23);
	if (retrn)
		retrn = pf_alignemnt(&flags, &str);
	if (retrn)
		retrn = write(fd, str, flags.fieldlen);
	if (str)
		ft_strdel(&str);
	return (retrn);
}

int			uprintf(int fd, const char *restrict format, va_list ap)
{
	int		current;
	int		printed;
	int		flushed;
	int		from;

	flushed = 0;
	printed = 0;
	from = 0;
	current = 0;
	while (format[current])
	{
		if (format[current] == '%')
		{
			flushed = write(fd, &format[from], current - from);
			printed += flushed;
			if (!(flushed = arg_print(fd, &format[current], ap)))
				return (-1);
			printed += flushed;
			current += flags_getlen(&format[current]);
			from = current;
		}
		current += 1;
	}
	flushed = write(fd, &format[from], current - from);
	return (printed + flushed);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		retrn;

	va_start(ap, format);
	retrn = uprintf(1, format, ap);
	va_end(ap);
	return (retrn);
}

int			ft_dprintf(int fd, const char *restrict format, ...)
{
	va_list	ap;
	int		retrn;

	va_start(ap, format);
	retrn = uprintf(fd, format, ap);
	va_end(ap);
	return (retrn);
}

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

int		flags_getlen(const char *str)
{
	int		index;

	index = 0;
	while (str[index + 1])
	{
		if (str[index + 1] == ' ')
			break ;
		index += 1;
	}
	return (index);
}

int		flags_print(int fd, const char *fmt, va_list ap)
{
	int		flags;
	int		retrn;

	flags = flags_set(fmt);
	retrn = printf_dispatcher(fd, flags, ap);
	return (retrn);
}

int		uprintf(int fd, const char *restrict format, va_list ap)
{
	int		current;
	int		printed;
	int		flushed;
	int		from;

	flushed = 0;
	printed = 0;
	from = 0;
	while (format[current])
	{
		if (format[current] == '%')
		{
			flushed = write(fd, &format[from], current - from);
			current + flags_getlen(&format[current]);
			from = current;
			printed += flushed;
			if (!(flushed = flags_print(fd, &format[current], ap)))
				return (-1);
			printed += flushed;
		}
		current += 1;
	}
	return (printed);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		retrn;

	va_start(ap, format);
	retrn = uprintf(1, format, ap);
	va_end(ap);
	return (retrn);
}

int		ft_dprintf(int fd, const char *restrict format, ...)
{
	va_list	ap;
	int		retrn;

	va_start(ap, format);
	retrn = uprintf(fd, format, ap);
	va_end(ap);
	return (retrn);
}
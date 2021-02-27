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

int		fset_precision(t_pa *flags, const char *fmt)
{
	if (flags->precision)
		return (0);
	if (!ft_isdigit(fmt[1]) || fmt[1] == '0')
		return (0);
	flags->precision = ft_atoi(&fmt[1]);
	return (ft_intlen(flags->precision));
}

int		fset_zero(t_pa *flags, const char *fmt)
{
	if (flags->padd_fill)
		return (0);
	flags->padd_fill = '0';
	return (1);
}

int		fset_space(t_pa *flags, const char *fmt)
{
	if (flags->padd_fill)
		return (0);
	flags->padd_fill = ' ';
	return (1);
}

int		fset_dec(t_pa *flags, const char *fmt)
{
	if (flags->type)
		return (0);
	flags->type = PFT_INT;
	return (1);
}

int		fset_float(t_pa *flags, const char *fmt)
{
	if (flags->type)
		return (0);
	flags->type = PFT_FLOAT;
	return (1);
}

int		fset_char(t_pa *flags, const char *fmt)
{
	if (flags->type)
		return (0);
	flags->type = PFT_CHAR;
	return (1);
}

int		fset_str(t_pa *flags, const char *fmt)
{
	if (flags->type)
		return (0);
	flags->type = PFT_STR;
	return (1);
}

int		fset_ptr(t_pa *flags, const char *fmt)
{
	if (flags->type)
		return (0);
	flags->type = PFT_PTR;
	return (1);
}

int		fset_long(t_pa *flags, const char *fmt)
{
	if (flags->type)
		return (0);
	flags->type = PFT_LONG;
	return (1);
}

int		fset_oct(t_pa *flags, const char *fmt)
{
	if (flags->base)
		return (0);
	flags->base = PFB_OCT;
	return (1);
}

int		fset_bin(t_pa *flags, const char *fmt)
{
	if (flags->base)
		return (0);
	flags->base = PFB_BIN;
	return (1);
}

int		fset_percent(t_pa *flags, const char *fmt)
{
	if (flags->len || flags->padd_fill || flags->precision ||
		flags->type || flags->base)
		return (0);
	if (!ft_isspace(fmt[1]))
		return (0);
	flags->padd_fill = '%';
	flags->type = PFT_CHAR;
	flags->len = 1;
	return (1);
}

int		fset_len(t_pa *flags, const char *fmt)
{
	if (flags->len)
		return (0);
	flags->len = ft_atoi(fmt);
	return (ft_intlen(flags->len));
}

t_flags_settings	*get_f_settings(void)
{
	static t_flags_settings fl_sets[14] = {
		{ ".", fset_precision },
		{ "0", fset_zero },
		{ " ", fset_space },
		{ "d", fset_dec },
		{ "f", fset_float },
		{ "c", fset_char },
		{ "s", fset_str },
		{ "l", fset_long },
		{ "p", fset_ptr },
		{ "o", fset_oct },
		{ "b", fset_bin },
		{ "%", fset_percent },
		{ "123456789", fset_len },
		{ NULL, NULL },
	};
	return (fl_sets);
}

int		flags_parse(t_pa *flags, const char *fmt)
{
	int					index;
	int					jndex;
	int					retrn;
	t_flags_settings	*f_settings;

	index = 1;
	f_settings = get_f_settings();
	while (fmt[index] && !ft_isspace(fmt[index]))
	{
		while (f_settings[jndex].id)
		{
			if (ft_ischarset(fmt[index], f_settings[jndex].id))
			{
				if (!(retrn = f_settings[jndex].f(flags, fmt[index])))
					return (0);
				jndex += retrn;
			}
			jndex += 1;
		}		
		index += 1;
	}
	return (1);
}

t_flags_types	*vaarg_gettype(void)
{
	static t_flags_types ftype[7] = {
		{ PFT_INT, vaarg_getint },
		{ PFT_PERCENT, vaarg_getpercent },
		{ PFT_FLOAT, vaarg_getfloat },
		{ PFT_CHAR, vaarg_getchar },
		{ PFT_STR, vaarg_getstr },
		{ PFT_PTR, vaarg_getptr },
		{ PFT_LONG, vaarg_getlong },
		{ NULL, NULL }
	};
	return (ftype);
}

int		vaarg_getint(t_pa *flags, char **s, va_list ap)
{
	int 	arg;
	int		s_len;

	arg = va_arg(ap, int);
	*s = ft_itoa(arg);
	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (!flags->len)
		flags->len = s_len;
	return (1);
}

int		vaarg_getstr(t_pa *flags, char **s, va_list ap)
{
	int 	arg;
	int		s_len;

	arg = va_arg(ap, int);
	*s = ft_itoa(arg);
	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (!flags->len)
		flags->len = s_len;
	return (1);
}

int		vaarg_getfloat(t_pa *flags, char **s, va_list ap)
{
	float 	arg;
	int		s_len;

	arg = va_arg(ap, float);
	*s = ft_ftoa(arg);
	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (!flags->len)
		flags->len = s_len;
	return (1);
}

int		vaarg_getchar(t_pa *flags, char **s, va_list ap)
{
	char 	arg;
	int		s_len;

	arg = (char)va_arg(ap, int);
	*s = ft_strdup(&arg);
	if (!s)
		return (0);
	flags->len = 1;
	return (1);
}

int		vaarg_getpercent(t_pa *flags, char **s, va_list ap)
{
	int 	arg;
	int		s_len;

	*s = ft_strdup("%");
	if (!*s)
		return (0);
	flags->len = 1;
	return (1);
}

int		vaarg_getnext(t_pa *flags, void *str, va_list ap)
{
	t_flags_types	*ftype;
	int				index;

	index = 0;
	ftype = ftypes_get();
	while (ftype[index].id)
	{
		if (ftype[index].id == flags->type)
		{
			if (ftype[index].f(flags, str, ap))
				return (0);
			return (1);
		}
		index += 1;
	}
	return (0);
}

int		arg_print(int fd, const char *fmt, va_list ap)
{
	t_pa	flags;
	int		retrn;
	char	*str;

	str = NULL;
	ft_bzero(&flags, sizeof(t_pa));
	retrn = flags_parse(&flags, fmt);
	if (retrn)
		retrn = vaarg_getnext(&flags, &str, ap);
	if (retrn)
		retrn = pf_alignemnt(&flags, &str);
	if (retrn)
		retrn = write(fd, str, flags.len);
	if (str)
		ft_strdel(&str);
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
			printed += flushed;
			if (!(flushed = arg_print(fd, &format[current], ap)))
				return (-1);
			printed += flushed;
			current + flags_getlen(&format[current]);
			from = current;
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
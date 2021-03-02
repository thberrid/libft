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

int		fset_precision(t_pf_flag *flags, const char *fmt)
{
	if (flags->precision)
		return (0);
	if (!ft_isdigit(fmt[1]) || fmt[1] == '0')
		return (0);
	flags->precision = ft_atoi(&fmt[1]);
	return (ft_intlen(flags->precision, BASE_DEC));
}

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
	if (flags->type)
		return (0);
	flags->type = PFT_LONG;
	return (1);
}

int		fset_percent(t_pf_flag *flags, const char *fmt)
{
	if (flags->fieldlen || flags->padd_fill || flags->precision ||
		flags->type || flags->base)
		return (0);
	if (!ft_isspace(fmt[1]))
		return (0);
	flags->padd_fill = '%';
	flags->type = PFT_CHAR;
	flags->fieldlen = 1;
	return (1);
}

int		fset_len(t_pf_flag *flags, const char *fmt)
{
	(void)fmt;
	if (flags->fieldlen)
		return (0);
	flags->fieldlen = ft_atoi(fmt);
	return (1);
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

int		flags_parse(t_pf_flag *flags, const char *fmt)
{
	int					index;
	int					jndex;
	int					retrn;
	t_flags_settings	*f_settings;

	index = 1;
	f_settings = get_f_settings();
	jndex = 0;
	while (fmt[index] && !ft_isspace(fmt[index]))
	{
		while (f_settings[jndex].id)
		{
			if (ft_ischarset(fmt[index], f_settings[jndex].id))
			{
				if (!(retrn = f_settings[jndex].f(flags, &fmt[index])))
					return (0);
				jndex += retrn;
			}
			jndex += 1;
		}		
		index += 1;
	}
	return (1);
}

t_pfstr_align	*pf_getaligmnt()
{
	static t_pfstr_align ftype[1] = {
		{ 0, NULL }
	};
	return (ftype);
}


int		pf_alignemnt(t_pf_flag *flags, char **str)
{
	t_pfstr_align	*falign;
	int				index;

	index = 0;
	falign = pf_getaligmnt();
	while (falign[index].id)
	{
		if (falign[index].id == flags->padd_fill)
		{
			if (falign[index].f(flags, str))
				return (0);
			return (1);
		}
		index += 1;
	}
	return (1);
}

int		vaarg_getint(t_pf_flag *flags, char **s, va_list ap)
{
	int 	arg;
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

int		vaarg_getlong(t_pf_flag *flags, char **s, va_list ap)
{
	long 	arg;
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

int		vaarg_getptr(t_pf_flag *flags, char **s, va_list ap)
{
	void 	*arg;
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

int		vaarg_getstr(t_pf_flag *flags, char **s, va_list ap)
{
	char 	*arg;
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

int		vaarg_getfloat(t_pf_flag *flags, char **s, va_list ap)
{
	float 	arg;
	size_t	s_len;

	arg = (float)va_arg(ap, double);
	if (!flags->precision)
		flags->precision = PF_DEFAULT_PRECISION;
	*s = ft_ftoa(arg, flags->precision);
	if (!s)
		return (0);
	s_len = ft_strlen(*s);
	if (!flags->fieldlen)
		flags->fieldlen = s_len;
	return (1);
}

int		vaarg_getchar(t_pf_flag *flags, char **s, va_list ap)
{
	char 	arg;

	arg = (char)va_arg(ap, int);
	*s = ft_strdup(&arg);
	if (!s)
		return (0);
	if (!flags->fieldlen)
		flags->fieldlen = 1;
	return (1);
}

int		vaarg_getpercent(t_pf_flag *flags, char **s, va_list ap)
{
	(void)ap;
	*s = ft_strdup("%");
	if (!*s)
		return (0);
	flags->fieldlen = 1;
	return (1);
}

t_flags_types	*vaarg_gettype(void)
{
	static t_flags_types ftype[8] = {
		{ PFT_INT, vaarg_getint },
		{ PFT_PERCENT, vaarg_getpercent },
		{ PFT_FLOAT, vaarg_getfloat },
		{ PFT_CHAR, vaarg_getchar },
		{ PFT_STR, vaarg_getstr },
		{ PFT_PTR, vaarg_getptr },
		{ PFT_LONG, vaarg_getlong },
		{ 0, NULL }
	};
	return (ftype);
}

int		vaarg_get(t_pf_flag *flags, char **str, va_list ap)
{
	t_flags_types	*ftype;
	int				index;

	index = 0;
	ftype = vaarg_gettype();
	while (ftype[index].id)
	{
		if (ftype[index].id == flags->type)
		{
			if (!ftype[index].f(flags, str, ap))
				return (0);
			return (1);
		}
		index += 1;
	}
	return (0);
}

int		arg_print(int fd, const char *fmt, va_list ap)
{
	t_pf_flag	flags;
	int		retrn;
	char	*str;

	str = NULL;
	ft_bzero(&flags, sizeof(t_pf_flag));
	retrn = flags_parse(&flags, fmt);
	if (retrn)
		retrn = vaarg_get(&flags, &str, ap);
	if (retrn)
		retrn = pf_alignemnt(&flags, &str);
	if (retrn)
		retrn = write(fd, str, flags.fieldlen);
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
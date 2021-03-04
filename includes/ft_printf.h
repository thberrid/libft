/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 00:32:44 by thberrid          #+#    #+#             */
/*   Updated: 2021/03/04 00:32:50 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <libft.h>

# define PFT_INT	 	1
# define PFT_FLOAT		2
# define PFT_CHAR		3
# define PFT_STR		4
# define PFT_PTR		5
# define PFT_LONG		6
# define PFT_PERCENT	7

# define PF_DEFAULT_PRECISION 6

typedef struct		s_pf_flag
{
	size_t	fieldlen;
	char	padd_fill;
	int		precision;
	int		type;
	char	*base;
	int		type_size;
}					t_pf_flag;

typedef struct		s_flags_settings
{
	char	*id;
	int		(*f)(t_pf_flag *, const char *);
}					t_flags_settings;

typedef struct		s_flags_types
{
	int		id;
	int		(*f)(t_pf_flag *, char **, va_list);
}					t_flags_types;

typedef struct		s_pfstr_align
{
	int		id;
	int		(*f)(t_pf_flag *, char **);
}					t_pfstr_align;

int					ft_printf(const char *restrict format, ...);
int					ft_dprintf(int fd, const char *restrict format, ...);
int					uprintf(int fd, const char *restrict format, va_list ap);

int					vaarg_getpercent(t_pf_flag *flags, char **s, va_list ap);
int					vaarg_getchar(t_pf_flag *flags, char **s, va_list ap);
int					vaarg_getstr(t_pf_flag *flags, char **s, va_list ap);
int					vaarg_getptr(t_pf_flag *flags, char **s, va_list ap);
int					vaarg_getint(t_pf_flag *flags, char **s, va_list ap);
int					vaarg_getfloat(t_pf_flag *flags, char **s, va_list ap);
int					vaarg_getlong(t_pf_flag *flags, char **s, va_list ap);
int					vaarg_get(t_pf_flag *flags, char **str, va_list ap);
t_flags_types		*vaarg_gettype(void);

int					fset_float(t_pf_flag *flags, const char *fmt);
int					fset_char(t_pf_flag *flags, const char *fmt);
int					fset_str(t_pf_flag *flags, const char *fmt);
int					fset_ptr(t_pf_flag *flags, const char *fmt);
int					fset_long(t_pf_flag *flags, const char *fmt);
int					fset_percent(t_pf_flag *flags, const char *fmt);
int					fset_precision(t_pf_flag *flags, const char *fmt);
int					fset_len(t_pf_flag *flags, const char *fmt);
int					fset_oct(t_pf_flag *flags, const char *fmt);
int					fset_dec(t_pf_flag *flags, const char *fmt);
int					fset_bin(t_pf_flag *flags, const char *fmt);
int					fset_zero(t_pf_flag *flags, const char *fmt);
int					fset_space(t_pf_flag *flags, const char *fmt);
t_flags_settings	*get_f_settings(void);
int					flags_parse(t_pf_flag *flags, const char *fmt);

t_pfstr_align		*pf_getaligmnt(void);
int					pf_alignemnt(t_pf_flag *flags, char **str);

#endif

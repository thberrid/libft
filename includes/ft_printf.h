/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:26:10 by thberrid          #+#    #+#             */
/*   Updated: 2021/02/24 19:26:12 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <libft.h>

# define    PFT_INT     1
# define    PFT_FLOAT   2
# define    PFT_CHAR    3
# define    PFT_STR     4
# define    PFT_PTR     5
# define    PFT_LONG    6
# define    PFT_PERCENT 7

# define    PFB_BIN     2
# define    PFB_DEC     10
# define    PFB_OCT     16

typedef struct  s_pa
{
    size_t  len;
    char    padd_fill;
    int     precision;
    int     type;
    int     base;
    int     type_size;   
}               t_pa;

typedef struct  s_flags_settings
{
    char    *id;
    int    (*f)(t_pa *, const char *);
}               t_flags_settings;

typedef struct  t_flags_types
{
    int     id;
    int    (*f)(t_pa *, char **, va_list);
}               t_flags_types;

int			    ft_printf(const char *restrict format, ...);
int		        ft_dprintf(int fd, const char *restrict format, ...);
int		        uprintf(int fd, const char *restrict format, va_list ap);

#endif
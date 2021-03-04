/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_vaarg_disp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 00:15:19 by thberrid          #+#    #+#             */
/*   Updated: 2021/03/04 00:15:21 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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

int				vaarg_get(t_pf_flag *flags, char **str, va_list ap)
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

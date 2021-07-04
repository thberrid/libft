/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_setflag_disp.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 00:13:54 by thberrid          #+#    #+#             */
/*   Updated: 2021/03/04 00:14:01 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_flags_settings	*get_f_settings(void)
{
	static t_flags_settings fl_sets[14] = {
		{ ".", fset_precision },
		{ "0", fset_zero },
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

int					flags_parse(t_pf_flag *flags, const char *fmt)
{
	int					index;
	int					jndex;
	int					retrn;
	t_flags_settings	*f_settings;

	index = 1;
	f_settings = get_f_settings();
	while (fmt[index] && !ft_isspace(fmt[index]))
	{
		jndex = 0;
		retrn = 0;
		while (f_settings[jndex].id)
		{
			if (ft_ischarset(fmt[index], f_settings[jndex].id))
			{
				if (!(retrn = f_settings[jndex].f(flags, &fmt[index])))
					return (0);
				index += retrn;
				break ;
			}
			jndex += 1;
		}
		if (retrn == 0)
			break ;
	}
	if (!flags->type)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_align.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 00:10:40 by thberrid          #+#    #+#             */
/*   Updated: 2021/03/04 00:10:42 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_pfstr_align	*pf_getaligmnt(void)
{
	static t_pfstr_align	ftype[1] = {
		{ 0, NULL }
	};

	return (ftype);
}

int				pf_alignemnt(t_pf_flag *flags, char **str)
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

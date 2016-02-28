/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 01:00:17 by bndao             #+#    #+#             */
/*   Updated: 2016/02/28 01:48:14 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					null_case_s(t_data *t)
{
	int			i;

	i = 0;
	if (t->o_zero && t->width)
	{
		i = t->width;
		while (i--)
			ft_putchar('0');
		return (t->width);
	}
	ft_putstr("(null)");
	return (6);
}

int					prec_str(t_data *t, char *str, t_conv *c)
{
	int			i;
	int			l;

	i = 0;
	l = 0;
	if (t->prec || return_char(c->b_t_conv, '.'))
	{
		i = t->prec;
		if (i >= (int)ft_strlen(str))
		{
			ft_putstr(str);
			return ((int)ft_strlen(str));
		}
		while (i--)
			ft_putchar(str[l++]);
		return (t->prec);
	}
	ft_putstr(str);
	return(ft_strlen(str));
}

int					len_str(t_data *t, char *str)
{
	if (!t->prec || (int)ft_strlen(str) < t->prec)
		return ((int)ft_strlen(str));
	return (t->prec);
}

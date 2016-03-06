/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 16:06:33 by bndao             #+#    #+#             */
/*   Updated: 2016/03/06 17:31:19 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					handle_s_maj(va_list conv, t_data *t, t_conv *c)
{
	wchar_t		*str;
	int			len;
	int			ret;

	ret = 0;
	if (!(str = va_arg(conv, wchar_t *)))
		return (null_case_s(t));
	len = len_str(t, ft_widestr_2_reg(str), c);
	if (!t->o_minus && t->width)
		ret += handle_width(len, t, c);
	ret += prec_str(t, ft_widestr_2_reg(str), c);
	if (t->o_minus && t->width)
		ret += handle_width(len, t, c);
	return (ret);
}

int					handle_c_maj(va_list conv, t_data *t, t_conv *c)
{
	wchar_t		ch;
	int			ret;

	ret = 0;
	if (!(ch = va_arg(conv, wchar_t)) && ch != 0)
		return (null_case());
	if (!t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_widechar_2_reg(ch)), t, c);
	ft_putstr(ft_widechar_2_reg(ch));
	ret += ch == 0 ? 1 : ft_strlen(ft_widechar_2_reg(ch));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_widechar_2_reg(ch)), t, c);
	return (ret);
}

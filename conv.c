/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:54:49 by bndao             #+#    #+#             */
/*   Updated: 2016/02/25 08:39:22 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					handle_s(va_list conv, t_data *t)
{
	char		*str;
	int			ret;

	ret = 0;
	if (!(str = va_arg(conv, char *)))
		return (null_case());
	ret = ft_strlen(str);
	if (!t->o_minus && t->width)
		ret += handle_width(ft_strlen(str), t);
	ft_putstr(str);
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(str), t);
	return (ret);
}

int					handle_d(va_list conv, t_data *t)
{
	int			d;
	int			ret;

	ret = 0;
	if (!(d = va_arg(conv, int)) && d != 0)
		return (null_case());
	if (d >= 0 && t->o_plus)
	{
		ft_putchar('+');
		ret = 1;
	}
	ret += handle_o_space(d, t);
	if (!t->o_minus && t->width)
		ret += handle_width_d(ft_strlen(ft_itoa(d)), t, d);
	if (!t->o_minus && t->prec && d > 0)
		ret += handle_o_point(ft_strlen(ft_itoa(d)), t, d);
	ret += handle_o_zero_d(d, t);
	if (t->o_minus && t->width)
		ret += handle_width_d(ft_strlen(ft_itoa(d)), t, d);
	return (ret);
}

int					handle_c(va_list conv, t_data *t)
{
	char		c;
	int			ret;

	ret = 0;
	if (!(c = (char)va_arg(conv, int)) && c != 0)
		return (null_case());
	if (!t->o_minus && t->width)
		ret += handle_width(1, t);
	ft_putchar(c);
	ret += 1;
	if (t->o_minus && t->width)
		ret += handle_width(1, t);
	return (ret);
}

int					handle_x(va_list conv, t_data *t)
{
	long int	d;
	int			ret;

	ret = 0;
	if (!(d = va_arg(conv, long int)) && d != 0)
		return (null_case());
	if (!t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 16, 'a')), t);
	if (t->o_diez && d != 0)
	{
		ret += 2;
		ft_putstr("0x");
	}
	ft_putstr(ft_itoa_base(d, 16, 'a'));
	ret += ft_strlen(ft_itoa_base(d, 16, 'a'));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 16, 'a')), t);
	return (ret);
}

int					handle_p(va_list conv, t_data *t)
{
	long int	d;
	int			ret;

	ret = 0;
	if (!(d = va_arg(conv, long int)) && d != 0)
		return (null_case());
	if (!t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 16, 'a')) + 2, t);
	ft_putstr("0x");
	ft_putstr(ft_itoa_base(d, 16, 'a'));
	ret += 2 + ft_strlen(ft_itoa_base(d, 16, 'a'));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 16, 'a')) + 2, t);
	return (ret);
}

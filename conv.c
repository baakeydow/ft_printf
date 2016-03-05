/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:54:49 by bndao             #+#    #+#             */
/*   Updated: 2016/03/05 11:45:48 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					handle_s(va_list conv, t_data *t, t_conv *c)
{
	char		*str;
	int			len;
	int			ret;

	ret = 0;
	if (!(str = va_arg(conv, char *)))
		return (null_case_s(t));
	len = len_str(t, str);
	if (len < t->prec && !t->width)
		len = t->prec;
	if (!t->o_minus && t->width)
		ret += handle_width(len, t, c);
	ret += prec_str(t, str, c);
	if (t->o_minus && t->width)
		ret += handle_width(len, t, c);
	return (ret);
}

int					handle_d(va_list conv, t_data *t, t_conv *c)
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
	ret += handle_o_space(d, t, c);
	if (!t->o_minus && t->width)
		ret += handle_width_d(ft_strlen(ft_itoa(d)), t, d);
	if (!t->o_minus && t->prec && d >= 0)
		ret += handle_o_point(ft_strlen(ft_itoa(d)), t, d);
	ret += handle_o_zero_d(d, t);
	if (t->o_minus && t->width)
		ret += handle_width_d(ft_strlen(ft_itoa(d)), t, d);
	return (ret);
}

int					handle_x(va_list conv, t_data *t, t_conv *c)
{
	long int	d;
	int			sharp;
	int			ret;

	ret = 0;
	sharp = 0;
	if (t->o_diez)
		sharp = 2;
	if (!(d = va_arg(conv, long int)) && d != 0)
		return (null_case());
	if (d == 0 && !t->prec && !t->width && return_char(c->b_t_conv, '.'))
		return (0);
	if (!t->o_minus && t->width && !t->o_zero)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 16, 'a')) + sharp, t, c);
	if (t->o_diez && d != 0)
	{
		ret += 2;
		ft_putstr("0x");
	}
	if (!t->o_minus && t->width && t->o_zero)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 16, 'a')) + sharp, t, c);
	if (t->prec)
		ret += handle_o_point(ft_strlen(ft_itoa_base(d, 16, 'a')), t, d);
	/*if (!(d == 0 && !t->prec && return_char(c->b_t_conv, '.')))*/
		ft_putstr(ft_itoa_base(d, 16, 'a'));
	ret += ft_strlen(ft_itoa_base(d, 16, 'a'));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 16, 'a')) + sharp, t, c);
	return (ret);
}

int					handle_p(va_list conv, t_data *t, t_conv *c)
{
	long int	d;
	int			ret;

	ret = 0;
	if (!(d = va_arg(conv, long int)) && d != 0)
		return (null_case());
	if (!t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 16, 'a')) + 2, t, c);
	ft_putstr("0x");
	if (d == 0 && !t->prec && return_char(c->b_t_conv, '.'))
		return (2);
	if (t->prec)
		ret += handle_o_point(ft_strlen(ft_itoa_base(d, 16, 'a')), t, d);
	ft_putstr(ft_itoa_base(d, 16, 'a'));
	ret += 2 + ft_strlen(ft_itoa_base(d, 16, 'a'));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 16, 'a')) + 2, t, c);
	return (ret);
}

int					handle_c(va_list conv, t_data *t, t_conv *c)
{
	char		ch;
	int			ret;

	ret = 0;
	if (!(ch = (char)va_arg(conv, int)) && ch != 0)
		return (null_case());
	if (!t->o_minus && t->width)
		ret += handle_width(1, t, c);
	ft_putchar(ch);
	ret += 1;
	if (t->o_minus && t->width)
		ret += handle_width(1, t, c);
	return (ret);
}

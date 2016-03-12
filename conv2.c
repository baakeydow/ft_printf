/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 03:46:46 by bndao             #+#    #+#             */
/*   Updated: 2016/03/12 18:33:40 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					handle_u(va_list conv, t_data *t, t_conv *c)
{
	uintmax_t	d;
	int			ret;

	ret = 0;
	d = size_uox(conv, t, c);
	if (!t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_ull(d)), t, c);
	if (!t->o_minus && t->prec)
		ret += handle_o_point_u(ft_strlen(ft_itoa_ull(d)), t);
	if (d == 0 && !t->prec && return_char(c->b_t_conv, '.'))
		return (0);
	ft_putnbr_u(d);
	ret += ft_strlen(ft_itoa_ull(d));
	if (t->o_minus && t->width)
		ret += handle_width_u(ft_strlen(ft_itoa_ull(d)), t, d, c);
	return (ret);
}

int					handle_o(va_list conv, t_data *t, t_conv *c)
{
	uintmax_t	d;
	int			sharp;
	int			ret;

	ret = 0;
	sharp = 0;
	if (t->o_diez)
		sharp = 1;
	d = size_uox(conv, t, c);
	if (!t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_uitoa_base(d, 8, 'a')) + sharp, t, c);
	if (t->o_diez && d != 0)
	{
		ret += 1;
		ft_putchar('0');
	}
	if (t->prec)
		ret += handle_o_point_u(ft_strlen(ft_uitoa_base(d, 8, 'a')) + sharp, t);
	if (!(d == 0 && !t->prec && return_char(c->b_t_conv, '.') && !t->o_diez && !t->width))
	{
		if (d == 0 && !t->o_diez && t->width)
			ft_putchar(' ');
		else
			ft_putstr(ft_uitoa_base(d, 8, 'a'));
	}
	else
		ret -= 1;
	ret += ft_strlen(ft_uitoa_base(d, 8, 'a'));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_uitoa_base(d, 8, 'a')) + sharp, t, c);
	return (ret);
}

int					handle_o_maj(va_list conv, t_data *t, t_conv *c)
{
	uintmax_t	d;
	int			sharp;
	int			ret;

	ret = 0;
	sharp = 0;
	if (t->o_diez)
		sharp = 1;
	d = size_uox(conv, t, c);
	if (!t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_uitoa_base(d, 8, 'A')) + sharp, t, c);
	if (t->o_diez && d != 0)
	{
		ret += 1;
		ft_putchar('0');
	}
	if (!t->o_minus && t->prec)
		ret += handle_o_point_u(ft_strlen(ft_uitoa_base(d, 8, 'A')) + sharp, t);
	if (!(d == 0 && !t->prec && return_char(c->b_t_conv, '.') && !t->o_diez))
		ft_putstr(ft_uitoa_base(d, 8, 'A'));
	else
		ret -= 1;
	ret += ft_strlen(ft_uitoa_base(d, 8, 'A'));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_uitoa_base(d, 8, 'A')) + sharp, t, c);
	return (ret);
}

int					handle_x_maj(va_list conv, t_data *t, t_conv *c)
{
	uintmax_t	d;
	int			sharp;
	int			ret;

	ret = 0;
	sharp = 0;
	if (t->o_diez)
		sharp = 2;
	d = size_uox(conv, t, c);
	if (d == 0 && !t->prec && !t->width && return_char(c->b_t_conv, '.'))
		return (0);
	if (!t->o_minus && t->width && !t->o_zero)
		ret += handle_width(ft_strlen(ft_uitoa_base(d, 16, 'A')) + sharp, t, c);
	if (t->o_diez && d != 0)
	{
		ret += 2;
		ft_putstr("0X");
	}
	if (!t->o_minus && t->width && t->o_zero)
		ret += handle_width(ft_strlen(ft_uitoa_base(d, 16, 'A')) + sharp, t, c);
	if (t->prec)
		ret += handle_o_point_u(ft_strlen(ft_uitoa_base(d, 16, 'A')), t);
	if (!(d == 0 && !t->prec && return_char(c->b_t_conv, '.')))
		ft_putstr(ft_uitoa_base(d, 16, 'A'));
	else
		ft_putchar(' ');
	ret += ft_strlen(ft_uitoa_base(d, 16, 'A'));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_uitoa_base(d, 16, 'A')) + sharp, t, c);
	return (ret);
}

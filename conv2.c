/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 03:46:46 by bndao             #+#    #+#             */
/*   Updated: 2016/03/05 17:09:43 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					handle_u(va_list conv, t_data *t, t_conv *c)
{
	size_t		d;
	int			ret;

	ret = 0;
	if (!(d = va_arg(conv, size_t)) && d != 0)
		return (null_case());
	if (!t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 10, 'a')), t, c);
	if (!t->o_minus && t->prec)
		ret += handle_o_point(ft_strlen(ft_itoa_base(d, 10, 'a')), t, d);
	if (d == 0 && !t->prec && return_char(c->b_t_conv, '.'))
		return (0);
	ft_putnbr_u(d);
	ret += ft_strlen(ft_itoa_base(d, 10, 'a'));
	if (t->o_minus && t->width)
	   ret += handle_width_d(ft_strlen(ft_itoa(d)), t, d, c);
	return (ret);
}

int					handle_o(va_list conv, t_data *t, t_conv *c)
{
	long int	d;
	int			sharp;
	int			ret;

	ret = 0;
	sharp = 0;
	if (t->o_diez)
		sharp = 1;
	if (!(d = va_arg(conv, long int)) && d != 0)
		return (null_case());
	if (!t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 8, 'a')) + sharp, t, c);
	if (t->o_diez && d != 0)
	{
		ret += 1;
		ft_putchar('0');
	}
	if (!t->o_minus && t->prec && d >= 0)
		ret += handle_o_point(ft_strlen(ft_itoa_base(d, 8, 'a')) + sharp, t, d);
	if (!(d == 0 && !t->prec && return_char(c->b_t_conv, '.')))
		ft_putstr(ft_itoa_base(d, 8, 'a'));
	else
		ft_putchar(' ');
	ret += ft_strlen(ft_itoa_base(d, 8, 'a'));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 8, 'a')) + sharp, t, c);
	return (ret);
}

int					handle_o_maj(va_list conv, t_data *t, t_conv *c)
{
	long int	d;
	int			ret;

	ret = 0;
	if (!(d = va_arg(conv, long int)) && d != 0)
		return (null_case());
	if (!t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 8, 'A')), t, c);
	if (t->o_diez && d != 0)
	{
		ret += 1;
		ft_putchar('0');
	}
	ft_putstr(ft_itoa_base(d, 8, 'A'));
	ret += ft_strlen(ft_itoa_base(d, 8, 'A'));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 8, 'A')), t, c);
	return (ret);
}

int					handle_x_maj(va_list conv, t_data *t, t_conv *c)
{
	long int	d;
	int			ret;

	ret = 0;
	if (!(d = va_arg(conv, long int)) && d != 0)
		return (null_case());
	if (!t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 16, 'A')), t, c);
	if (t->o_diez && d != 0)
	{
		ret += 2;
		ft_putstr("0X");
	}
	ft_putstr(ft_itoa_base(d, 16, 'A'));
	ret += ft_strlen(ft_itoa_base(d, 16, 'A'));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 16, 'A')), t, c);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 03:46:46 by bndao             #+#    #+#             */
/*   Updated: 2016/02/28 02:04:29 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					handle_o(va_list conv, t_data *t, t_conv *c)
{
	long int	d;
	int			ret;

	ret = 0;
	if (!(d = va_arg(conv, long int)) && d != 0)
		return (null_case());
	if (!t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 8, 'a')), t, c);
	if (t->o_diez && d != 0)
	{
		ret += 1;
		ft_putchar('0');
	}
	if (!t->o_minus && t->prec && d >= 0 && t->o_diez)
		ret += handle_o_point(ft_strlen(ft_itoa_base(d, 8, 'a')) + 1, t, d);
	ft_putstr(ft_itoa_base(d, 8, 'a'));
	ret += ft_strlen(ft_itoa_base(d, 8, 'a'));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 8, 'a')), t, c);
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

int					handle_c_maj(va_list conv, t_data *t, t_conv *c)
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

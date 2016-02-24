/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:54:49 by bndao             #+#    #+#             */
/*   Updated: 2016/02/24 04:10:47 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					handle_s(va_list conv)
{
	char		*str;

	if (!(str = va_arg(conv, char *)))
		return (null_case());
	ft_putstr(str);
	return (ft_strlen(str));
}

int					handle_d(va_list conv, t_data *t)
{
	int			d;
	int			ret;

	ret = 0;
	if (!(d = va_arg(conv, int)))
		return (null_case());
	if (d >= 0 && t->o_plus)
	{
		ft_putchar('+');
		ret = 1;
	}
	if (!t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa(d)), t);
	ft_putnbr(d);
	ret += ft_strlen(ft_itoa(d));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa(d)), t);
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

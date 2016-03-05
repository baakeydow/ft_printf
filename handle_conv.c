/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:54:26 by bndao             #+#    #+#             */
/*   Updated: 2016/03/05 14:58:20 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					handle_width(int len, t_data *t, t_conv *c)
{
	int			i;
	char		ch;

	ch = ' ';
	if (t->o_zero)
		ch = '0';
	i = t->width - len;
	if (t->prec > len && len != 0)
		i = t->width - t->prec;
	if (c->s && t->width > len && !t->prec && return_char(c->b_t_conv, '.'))
		i = t->prec;
	if (i < 0)
		return (0);
	if (i == 0)
	{
		len = 0;
		i = t->width;
	}
	while (i)
	{
		ft_putchar(ch);
		i--;
	}
	return (t->prec > len ? t->width - t->prec : t->width - len);
}

int					handle_width_d(int len_conv, t_data *t, int d, t_conv *c)
{
	int			i;
	char		ch;
	int			ok;
	int			ret;

	ch = ' ';
	if (t->o_zero && !t->o_minus)
		ch = '0';
	ok = 0;
	ret = 0;
	if (d < 0 && t->o_zero && !t->o_minus)
	{
		ok = 1;
		ft_putchar('-');
	}
	if (d < 0 && t->prec && t->prec > len_conv)
		ok = 1;
	ret += t->width - len_conv;
	if (t->prec > len_conv)
		ret = t->width - (len_conv - (len_conv - t->prec)) - ok;
	i = ret;
	if (i < 0 || (t->width > t->prec && return_char(c->b_t_conv, '.') && d == 0))
		return (0);
	while (i--)
		ft_putchar(ch);
	if (d < 0 && t->o_zero && !t->o_minus)
	{
		d = -d;
		ft_putnbr(d);
	}
	return (ret);
}

int					handle_o_point(int len_conv, t_data *t, int d)
{
	int			i;
	int			ok;

	ok = 0;
	if (d < 0)
		ok = 1;
	i = t->prec - len_conv - ok;
	if (i <= 0)
		return (0);
	while (i)
	{
		ft_putchar('0');
		i--;
	}
	return (t->prec - len_conv - ok);
}

int					handle_o_zero_d(int d, t_data *t, t_conv *c)
{
	int			ret;

	ret = 0;
	if (t->o_zero && d < 0 && !t->prec && !t->width &&
			return_char(c->b_t_conv, '.'))
		return (ft_strlen(ft_itoa(d)));
	else if (d < 0 && t->prec)
	{
		ft_putchar('-');
		ret = handle_o_point(ft_strlen(ft_itoa(d)) - 2, t, d);
		ret += ft_strlen(ft_itoa(d));
		ft_putnbr(-d);
		return (ret);
	}
	else if (d == 0 && !t->prec && return_char(c->b_t_conv, '.'))
		return (0);
	else if (t->o_zero && t->width && d < 0)
		return (t->width - (int)ft_strlen(ft_itoa(d)) + 1);
	else
		ft_putnbr(d);
	return (ft_strlen(ft_itoa(d)));
}

int					handle_o_space(int d, t_data *t, t_conv *c)
{
	int			ret;

	ret = 0;
	if ((d >= 0 && !t->o_plus && t->o_space && !c->u) ||
			(d == 0 && t->o_zero && t->width && t->prec))
	{
		ft_putchar(' ');
		ret = 1;
	}
	return (ret);
}

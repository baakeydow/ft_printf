/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:54:26 by bndao             #+#    #+#             */
/*   Updated: 2016/03/03 10:41:49 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int						handle_width(int len, t_data *t, t_conv *c)
{
	int			i;
	char		ch;

	ch = ' ';
	if (t->o_zero)
		ch = '0';
	i = t->width - len;
	if (t->prec > len)
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

int						handle_width_d(int len_conv, t_data *t, int d)
{
	int			i;
	char		c;
	int			ok;
	int			ret;

	c = ' ';
	if (t->o_zero)
		c = '0';
	ok = 0;
	ret = 0;
	if (d < 0 && t->o_zero)
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
	if (i <= 0)
		return (0);
	while (i--)
		ft_putchar(c);
	if (t->o_zero && d < 0)
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

int					handle_o_zero_d(int d, t_data *t)
{
	int			ret;

	ret = 0;
	if (t->o_zero && d < 0 && !t->prec)
		return (ft_strlen(ft_itoa(d)));
	else if (d < 0 && t->prec)
	{
		ft_putchar('-');
		ret = handle_o_point(ft_strlen(ft_itoa(d)) - 2, t, d);
		ret += ft_strlen(ft_itoa(d));
		ft_putnbr(-d);
		return (ret);
	}
	else if (d == 0 && !t->prec)
		return (0);
	else
		ft_putnbr(d);
	return (ft_strlen(ft_itoa(d)));
}

int					handle_o_space(int d, t_data *t, t_conv *c)
{
	int			ret;

	ret = 0;
	if (d >= 0 && !t->o_plus && t->o_space && !c->u)
	{
		ft_putchar(' ');
		ret = 1;
	}
	return (ret);
}

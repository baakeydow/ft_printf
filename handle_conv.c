/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:54:26 by bndao             #+#    #+#             */
/*   Updated: 2016/03/12 18:47:35 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					handle_width(int len, t_data *t, t_conv *c)
{
	int			i;
	char		ch;

	ch = ' ';
	if (t->o_zero && !t->o_minus &&
			(c->o || c->x || c->c || false_type(c) ||
			c->sm || c->xm || c->s || c->p || c->u))
		ch = '0';
	i = t->width - len;
	if (t->prec > len && len != 0 && !c->s)
		i = t->width - t->prec;
	if (i < 0)
		return (0);
	if (i == 0 && t->width > len)
	{
		len = 0;
		i = t->width;
	}
	while (i)
	{
		ft_putchar(ch);
		i--;
	}
	return (t->prec > len && !c->s ? t->width - t->prec : t->width - len);
}

static int			put_minus(intmax_t d, t_data *t)
{
	if (d < 0 && t->o_zero && !t->o_minus && !t->prec)
	{
		ft_putchar('-');
		return (1);
	}
	return (0);
}

static int			no_width(int i, intmax_t d, t_data *t, t_conv *c)
{
	if (i < 0 || (t->width > t->prec && return_char(c->b_t_conv, '.') &&
				d <= 0 && t->o_zero))
		return (1);
	return (0);
}

static void			neg_num(intmax_t d, t_data *t)
{
	if (d < 0 && t->o_zero && !t->o_minus && !t->prec)
	{
		d = -d;
		ft_putnbr(d);
	}
}

int					handle_width_d(int len, t_data *t, intmax_t d, t_conv *c)
{
	int			f[3];
	char		ch;

	ch = ' ';
	if (t->o_zero && !t->o_minus && !t->prec)
		ch = '0';
	f[1] = 0;
	f[2] = 0;
	if (put_minus(d, t))
		f[1] = 1;
	if (d < 0 && t->prec && t->prec > len)
		f[1] = 1;
	f[2] += t->width - len;
	if (t->prec > len)
		f[2] = t->width - (len - (len - t->prec)) - f[1];
	f[0] = f[2];
	if (no_width(f[0], d, t, c))
		return (0);
	if (t->o_plus && !t->o_zero && f[0] != 0)
		f[0] = f[0] - 1;
	while ((f[0])--)
		ft_putchar(ch);
	neg_num(d, t);
	return (f[2]);
}

int					handle_width_u(int len, t_data *t, uintmax_t d, t_conv *c)
{
	int			i;
	char		ch;
	int			ret;

	ch = ' ';
	if (t->o_zero && !t->o_minus)
		ch = '0';
	ret = 0;
	ret += t->width - len;
	if (t->prec > len)
		ret = t->width - (len - (len - t->prec));
	i = ret;
	if (i < 0 || (t->width > t->prec && return_char(c->b_t_conv, '.') &&
				d == 0))
		return (0);
	while (i--)
		ft_putchar(ch);
	return (ret);
}

int					handle_o_point(int len_conv, t_data *t, intmax_t d)
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

int					handle_o_point_u(int len_conv, t_data *t)
{
	int			i;

	i = t->prec - len_conv;
	if (i <= 0)
		return (0);
	while (i)
	{
		ft_putchar('0');
		i--;
	}
	return (t->prec - len_conv);
}

static int			neg_and_prec(intmax_t d, t_data *t)
{
	int			ret;

	ret = 0;
	ft_putchar('-');
	ret = handle_o_point(ft_strlen(ft_itoa_ll(d)) - 2, t, d);
	ret += ft_strlen(ft_itoa_ll(d));
	ft_putnbr_ll(-d);
	return (ret);
}

int					handle_o_zero_d(intmax_t d, t_data *t, t_conv *c)
{
	int			ret;

	ret = 0;
	if (t->o_zero && d < 0 && !t->prec && !t->width &&
			return_char(c->b_t_conv, '.'))
		return (ft_strlen(ft_itoa_ll(d)));
	else if (d < 0 && t->prec)
		return (neg_and_prec(d, t));
	else if (d == 0 && !t->prec && return_char(c->b_t_conv, '.'))
	{
		if (t->width)
			ft_putchar(' ');
		return (t->width ? 1 : 0);
	}
	else if (t->o_zero && t->width && d < 0 && !t->o_minus)
		return (c->d ? ft_strlen((ft_itoa_ll(d))) :
				t->width - ft_strlen(ft_itoa_ll(d)) + 1);
	else
		ft_putnbr_ll(d);
	return (ft_strlen(ft_itoa_ll(d)));
}

int					handle_o_space(intmax_t d, t_data *t, t_conv *c)
{
	int			ret;

	ret = 0;
	if ((d >= 0 && !t->o_plus && t->o_space && !c->u && !t->prec) ||
			(d == 0 && t->o_zero && t->width && t->prec))
	{
		ft_putchar(' ');
		ret = 1;
	}
	return (ret);
}

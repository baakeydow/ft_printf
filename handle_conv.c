/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:54:26 by bndao             #+#    #+#             */
/*   Updated: 2016/02/26 07:30:46 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int						handle_width(int len_conv, t_data *t)
{
	int			i;
	char		c;

	c = ' ';
	if (t->o_zero)
		c = '0';
	i = t->width - len_conv;
	if (i < 0)
		return (0);
	if (i == 0)
	{
		len_conv = 0;
		i = t->width;
	}
	while (i)
	{
		ft_putchar(c);
		i--;
	}
	return (t->width - len_conv);
}

int						handle_width_d(int len_conv, t_data *t, int d)
{
	int			i;
	char		c;
	char		ok;
	int			ret;

	c = ' ';
	ok = 0;
	ret = t->width - len_conv + ok;
	if (t->prec > len_conv)
		ret = t->width - (len_conv - (len_conv - t->prec));
	if (t->o_zero)
		c = '0';
	if (d < 0 && t->o_zero)
	{
		ok = 1;
		ft_putchar('-');
	}
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
	{
		d = -d;
		return (ft_strlen(ft_itoa(d)) + 1);
	}
	else if (d < 0 && t->prec)
	{
		ft_putchar('-');
		ret = handle_o_point(ft_strlen(ft_itoa(d)) - 2, t, d);
		ret += ft_strlen(ft_itoa(d));
		ft_putnbr(-d);
		return (ret);
	}
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

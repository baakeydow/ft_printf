/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 01:00:17 by bndao             #+#    #+#             */
/*   Updated: 2016/03/14 20:05:32 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					prec_str(t_data *t, char *str, t_conv *c)
{
	int			i;
	int			l;

	i = 0;
	l = 0;
	if (!ft_strlen(str) && t->width)
		return (0);
	if (t->prec || return_char(c->b_t_conv, '.'))
	{
		i = t->prec;
		if (i > (int)ft_strlen(str))
		{
			ft_putstr(str);
			return ((int)ft_strlen(str));
		}
		while (i--)
			ft_putchar(str[l++]);
		return (t->prec);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}

int					len_str(t_data *t, char *str, t_conv *c)
{
	if ((!t->prec && return_char(c->b_t_conv, '.')) ||
			((int)ft_strlen(str) > t->prec && return_char(c->b_t_conv, '.')))
		return (t->prec);
	return ((int)ft_strlen(str));
}

void				ft_putnbr_u(uintmax_t n)
{
	if (n > ULONG_MAX)
		ft_putstr("18446744073709551615");
	if (n > 9)
	{
		ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
	}
	else
		ft_putchar(48 + n);
}

void				ft_putnbr_ll(intmax_t n)
{
	if (n > LLONG_MAX)
		ft_putstr("-1");
	if (n <= LLONG_MIN)
	{
		ft_putstr("-9");
		n = 223372036854775808;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_ll(n / 10);
		ft_putnbr_ll(n % 10);
	}
	else
		ft_putchar(48 + n);
}

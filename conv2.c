/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 03:46:46 by bndao             #+#    #+#             */
/*   Updated: 2016/02/24 09:00:58 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					handle_o(va_list conv, t_data *t)
{
	long int	d;
	int			ret;

	ret = 0;
	if (!(d = va_arg(conv, long int)) && d != 0)
		return (null_case());
	if (!t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 8, 'a')), t);
	ft_putstr(ft_itoa_base(d, 8, 'a'));
	ret += ft_strlen(ft_itoa_base(d, 8, 'a'));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 8, 'a')), t);
	return (ret);
}

int					handle_c_maj(va_list conv, t_data *t)
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

int					handle_x_maj(va_list conv, t_data *t)
{
	long int	d;
	int			ret;

	ret = 0;
	if (!(d = va_arg(conv, long int)) && d != 0)
		return (null_case());
	if (!t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 16, 'A')), t);
	ft_putstr(ft_itoa_base(d, 16, 'A'));
	ret += ft_strlen(ft_itoa_base(d, 16, 'A'));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 16, 'A')), t);
	return (ret);
}

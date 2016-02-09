/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 00:59:47 by bndao             #+#    #+#             */
/*   Updated: 2016/02/09 06:50:10 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					handle_d(va_list conv, t_data *t, char *cpy)
{
	int		len_ante;
	int		len_after;
	int		d;

	len_ante = 0;
	len_after = 0;
	if (!(d = va_arg(conv, int)))
		return (null_case(cpy, t));
	len_ante = handle_ante(cpy, t);
	ft_putnbr(d);
	len_ante = handle_after(cpy, t);
	return (ft_strlen(ft_itoa(d)) + len_ante + len_after);
}

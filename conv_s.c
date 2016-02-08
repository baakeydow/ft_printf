/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 00:55:11 by bndao             #+#    #+#             */
/*   Updated: 2016/02/08 23:40:18 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					handle_s(va_list conv, t_data *t, char *cpy)
{
	int			len_ante;
	int			len_after;
	char		*str;

	len_ante = 0;
	len_after = 0;
	if (!(str = va_arg(conv, char *)))
		return (null_case(t));
	if (t->ante)
		len_ante = handle_t_ante(t);
	ft_putstr(str);
	if (t->after)
		len_after = handle_t_after(t);
	return (ft_strlen(str) + len_ante + len_after);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 21:45:13 by bndao             #+#    #+#             */
/*   Updated: 2016/03/09 02:08:13 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned long long int				size_d(va_list conv, t_data *t)
{
	unsigned long long int		nbr;

	nbr = 0;
	if (!t->h && !t->hh && !t->l && !t->ll && !t->j && !t->z)
		if (!(nbr = va_arg(conv, int)) && nbr != 0)
			return (null_case());
	if (t->h)
		if (!(nbr = (short)va_arg(conv, int)) && nbr != 0)
			return (null_case());
	if (t->hh)
		if (!(nbr = (char)va_arg(conv, int)) && nbr != 0)
			return (null_case());
	if (t->l)
		if (!(nbr = va_arg(conv, long int)) && nbr != 0)
			return (null_case());
	if (t->ll)
		if (!(nbr = va_arg(conv, long long int)) && nbr != 0)
			return (null_case());
	if (t->j)
		if (!(nbr = va_arg(conv, intmax_t)) && nbr != 0)
			return (null_case());
	if (t->z)
		if (!(nbr = va_arg(conv, size_t)) && nbr != 0)
			return (null_case());
	return (nbr);
}

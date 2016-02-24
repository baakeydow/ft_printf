/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:55:55 by bndao             #+#    #+#             */
/*   Updated: 2016/02/24 04:10:47 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int						printchar(const char **cpy)
{
	if (**cpy == '%')
		return (0);
	ft_putchar(*cpy[0]);
	return (1);
}

int						handle_no_p_cent(const char *cpy)
{
	if (!cpy)
		return (-1);
	ft_putstr(cpy);
	return (ft_strlen(cpy));
}

int						is_b_t_conv(const char *fmt, int *i)
{
	if (fmt[*i] == 's' || fmt[*i] == 'S' || fmt[*i] == 'p' ||
			fmt[*i] == 'd' || fmt[*i] == 'D' || fmt[*i] == 'i' ||
			fmt[*i] == 'o' || fmt[*i] == 'O' || fmt[*i] == 'u' ||
			fmt[*i] == 'U' || fmt[*i] == 'x' || fmt[*i] == 'X' ||
			fmt[*i] == 'c' || fmt[*i] == 'C')
		return (0);
	return (1);
}

int						is_not_data(const char *fmt, int *i)
{
	if (fmt[*i] == '-' || fmt[*i] == '+' || fmt[*i] == '#' ||
			fmt[*i] == ' ' || ft_isdigit(fmt[*i]) || fmt[*i] == 'l' ||
			fmt[*i] == 'h' || fmt[*i] == 'j' || fmt[*i] == 'z')
		return (0);
	return (1);
}

int						false_type(t_conv *c)
{
	if (!c->s && !c->S && !c->p && !c->d && !c->D && !c->i && !c->o &&
			!c->O && !c->u && !c->U && !c->x && !c->X && !c->c && !c->C)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:54:41 by bndao             #+#    #+#             */
/*   Updated: 2016/02/28 23:34:57 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int						handle_false_type(t_conv *c, t_data *t, char *cpy)
{
	int			ret;

	ret = 0;
	if (percent_nbr(before_t_conv(cpy)))
		return (handle_glued(t));
   if (!t->o_minus && t->width)
	{
		ret += handle_width(1, t, c) + 1;
		ft_putchar(before_t_conv(cpy)[ft_strlen(before_t_conv(cpy)) - 1]);
	}
	if (t->o_minus && t->width)
	{
		ft_putchar(before_t_conv(cpy)[ft_strlen(before_t_conv(cpy)) - 1]);
		ret += handle_width(1, t, c) + 1;
	}
	return (ret);
}

char					*after_t_conv(const char *fmt, t_conv *c, t_data *t)
{
	int			i;

	i = 0;
	if (false_type(c) && !percent_nbr(fmt) && !t->o_minus &&
			!t->o_space && !t->width)
		return ((char *)fmt);
	if (false_type(c) && !percent_nbr(fmt) && (!t->o_minus || t->o_space)
			&& !t->o_zero)
		return (ft_strsub(fmt, i + 1, ft_strlen(fmt) - i));
	while (fmt[i])
	{
		if (is_not_data(fmt, &i))
			break ;
		if (!is_b_t_conv(fmt, &i))
			break ;
		if (fmt[i] == '%')
			break ;
		++i;
	}
	return (ft_strsub(fmt, i + 1, ft_strlen(fmt) - i));
}

char					*before_t_conv(const char *fmt)
{
	int			i;

	i = 0;
	if (!is_b_t_conv(fmt, &i))
		return (get(fmt));
	while (fmt[i])
	{
		if (!is_b_t_conv(fmt, &i))
			break ;
		if (is_not_data(fmt, &i))
			break ;
		i++;
	}
	return (ft_strsub(fmt, 0, i + 1));
}

t_data					*init(const char *cpy)
{
	t_data		*ptr;

	if (!(ptr = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	ptr->o_minus = return_char(before_t_conv(cpy), '-');
	ptr->o_plus = return_char(before_t_conv(cpy), '+');
	ptr->o_diez = return_char(before_t_conv(cpy), '#');
	ptr->o_zero = find_o_zero(before_t_conv(cpy));
	ptr->o_space = return_char(before_t_conv(cpy), ' ');
	ptr->width = find_width(before_t_conv(cpy));
	ptr->prec = find_prec(before_t_conv(cpy));
	ptr->length = "0";
	return (ptr);
}

t_conv					*init_conv(const char *cpy)
{
	t_conv		*ptr;

	if (!(ptr = (t_conv *)malloc(sizeof(t_conv))))
		return (NULL);
	ptr->b_t_conv = before_t_conv(cpy);
	ptr->s = return_char(before_t_conv(cpy), 's');
	ptr->S = return_char(before_t_conv(cpy), 'S');
	ptr->p = return_char(before_t_conv(cpy), 'p');
	ptr->d = return_char(before_t_conv(cpy), 'd');
	ptr->D = return_char(before_t_conv(cpy), 'D');
	ptr->i = return_char(before_t_conv(cpy), 'i');
	ptr->o = return_char(before_t_conv(cpy), 'o');
	ptr->O = return_char(before_t_conv(cpy), 'O');
	ptr->u = return_char(before_t_conv(cpy), 'u');
	ptr->U = return_char(before_t_conv(cpy), 'U');
	ptr->x = return_char(before_t_conv(cpy), 'x');
	ptr->X = return_char(before_t_conv(cpy), 'X');
	ptr->c = return_char(before_t_conv(cpy), 'c');
	ptr->C = return_char(before_t_conv(cpy), 'C');
	return (ptr);
}

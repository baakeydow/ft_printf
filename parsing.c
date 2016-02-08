/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 04:10:15 by bndao             #+#    #+#             */
/*   Updated: 2016/02/06 19:12:05 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int						is_b_t_conv(char *fmt, int *i)
{
	if (fmt[*i] == 's' || fmt[*i] == 'S' || fmt[*i] == 'p' ||
			fmt[*i] == 'd' || fmt[*i] == 'D' || fmt[*i] == 'i' ||
			fmt[*i] == 'o' || fmt[*i] == 'O' || fmt[*i] == 'u' ||
			fmt[*i] == 'U' || fmt[*i] == 'x' || fmt[*i] == 'X' ||
			fmt[*i] == 'c' || fmt[*i] == 'C')
		return (0);
	return (1);
}

char					*before_t_conv(char *fmt)
{
	int			i;
	int			d;
	char		*t;

	i = 0;
	d = 0;
	if (!(t = post_percent(fmt)))
		return (NULL);
	if (!is_b_t_conv(t, &i))
		return (NULL);
	while (t[i])
	{
		if (is_b_t_conv(fmt, &i))
			d++;
		i++;
	}
	return (ft_strsub(t, 0, d));
}

char					*after_t_conv(char *fmt)
{
	int			i;

	i = 0;
	while (fmt[i])
	{
		if (!is_b_t_conv(fmt, &i))
			break ;
		i++;
	}
	return (ft_strsub(fmt, i + 1, ft_strlen(fmt) - i));
}

t_data					*init(char *cpy)
{
	t_data		*ptr;

	if (!(ptr = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	ptr->p_cent = percent_nbr(cpy);
	ptr->before = before_t_conv(post_percent(cpy));
	ptr->ante = ante_percent(cpy);
	ptr->after = after_t_conv(post_percent(cpy));
	ptr->o_minus = return_char(before_t_conv(cpy), '-');
	ptr->o_plus = return_char(before_t_conv(cpy), '+');
	ptr->o_diez = return_char(before_t_conv(cpy), '#');
	ptr->o_zero = return_char(before_t_conv(cpy), '0');
	ptr->o_space = return_char(before_t_conv(cpy), ' ');
	ptr->width = 0;
	ptr->precision = 0;
	ptr->length = "0";
	return (ptr);
}

t_conv					*init_conv(char *cpy)
{
	t_conv		*ptr;

	if (!(ptr = (t_conv *)malloc(sizeof(t_conv))))
		return (NULL);
	ptr->s = return_char(post_percent(cpy), 's');
	ptr->S = return_char(post_percent(cpy), 'S');
	ptr->p = return_char(post_percent(cpy), 'p');
	ptr->d = return_char(post_percent(cpy), 'd');
	ptr->D = return_char(post_percent(cpy), 'D');
	ptr->i = return_char(post_percent(cpy), 's');
	ptr->o = return_char(post_percent(cpy), 's');
	ptr->O = return_char(post_percent(cpy), 's');
	ptr->u = return_char(post_percent(cpy), 's');
	ptr->U = return_char(post_percent(cpy), 's');
	ptr->x = return_char(post_percent(cpy), 's');
	ptr->X = return_char(post_percent(cpy), 's');
	ptr->c = return_char(post_percent(cpy), 's');
	ptr->C = return_char(post_percent(cpy), 's');
	return (ptr);
}

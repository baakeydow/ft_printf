/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:54:33 by bndao             #+#    #+#             */
/*   Updated: 2016/02/21 20:56:39 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char					return_char(const char *fmt, char c)
{
	int				i;

	i = 0;
	if (!fmt)
		return (0);
	while (fmt[i])
	{
		if (fmt[i] == c)
			return (c);
		i++;
	}
	return (0);
}

int						percent_nbr(const char *fmt)
{
	size_t			i;
	int				p;

	i = 0;
	p = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
			p++;
		i++;
	}
	return (p);
}

int						find_width(char *str)
{
	int				i;
	int				start;

	i = 0;
	start = 0;
	if (!str)
		return (0);
	while (!(ft_isdigit(str[i])))
		i++;
	start = i;
	while (ft_isdigit(str[i]))
		i++;
	return (ft_atoi(ft_strsub(str, start, i)));
}

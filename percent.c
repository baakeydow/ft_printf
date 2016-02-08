/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 23:59:43 by bndao             #+#    #+#             */
/*   Updated: 2016/02/08 08:41:15 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char					*ante_percent(char *fmt)
{
	int				i;

	i = 0;
	while (fmt[i] && fmt[i] != '%')
		i++;
	if (i == 0)
		return (NULL);
	return (ft_strsub(fmt, 0, i));
}

char					*post_percent(char *fmt)
{
	int				i;
	char			*str;
	char			*dup;

	i = 0;
	dup = ft_strdup(fmt);
	if (!(str = ft_strchr(dup, '%')))
		return(dup);
	return (str + 1);
}

int						double_percent(char *fmt)
{
	int				i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1] == '%')
			return (1);
		i++;
	}
	return (0);
}

char					return_char(char *fmt, char c)
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

int						percent_nbr(char *fmt)
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

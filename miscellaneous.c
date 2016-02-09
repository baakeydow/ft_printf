/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 03:46:15 by bndao             #+#    #+#             */
/*   Updated: 2016/02/09 07:02:38 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				handle_no_p_cent(char *cpy)
{
	ft_putstr(cpy);
	return (ft_strlen(cpy));
}

int				handle_glued(void)
{
	ft_putchar('%');
	return (1);
}

int			handle_ante(char *cpy, t_data *t)
{
	int			len_ante;

	len_ante = ft_strlen(t->i_fmt) - ft_strlen(cpy - 1);
	if (len_ante > 0)
	{
		t->i_fmt = ft_strsub(t->i_fmt, 0, len_ante);
		ft_putstr(t->i_fmt);
	}
	else
	{
		t->i_fmt = ft_strdup(post_percent(cpy + 1));
		len_ante = ft_strlen(post_percent(cpy + 1));
		ft_putstr(t->i_fmt);
	}
	return (len_ante);
}

int			handle_after(char *cpy, t_data *t)
{
	int			len_after;

	len_after = 0;
	if (!(percent_nbr(cpy + 1)))
	{
		t->i_fmt = ft_strdup(cpy + 1);
		ft_putstr(cpy + 1);
		len_after = ft_strlen(post_percent(cpy + 1));
	}
	else
	{
		len_after = ft_strlen(cpy + 1) - ft_strlen(mv_next_percent(cpy + 1));
		t->i_fmt = ft_strsub(cpy + 1, 0, len_after - 1);
		ft_putstr(t->i_fmt);
	}
	return (len_after);
}

int			null_case(char *cpy, t_data *t)
{
	int			len_ante;
	int			len_after;

	len_ante = 0;
	len_after = 0;
	if (t->ante)
		len_ante = handle_ante(cpy, t);
	ft_putstr("(null)");
	if (t->after)
		len_after = handle_after(cpy, t);
	return (6 + len_ante + len_after);
}

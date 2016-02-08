/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 03:46:15 by bndao             #+#    #+#             */
/*   Updated: 2016/02/08 23:31:28 by bndao            ###   ########.fr       */
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

int			handle_t_ante(t_data *t)
{
	int			len_ante;

	len_ante = ft_strlen(t->ante);
	ft_putstr(t->ante);
	return (len_ante);
}

int			handle_t_after(t_data *t)
{
	int			len_after;

	len_after = 0;
	if (!percent_nbr(t->after))
	{
		ft_putstr((t->after));
		len_after = ft_strlen(t->after);
	}
	else
	{
		ft_putstr(after_t_conv(post_percent(t->after)));
		len_after = ft_strlen(after_t_conv(post_percent(t->after)));
	}
	return (len_after);
}

int			null_case(t_data *t)
{
	int			len_ante;
	int			len_after;

	len_ante = 0;
	len_after = 0;
	if (t->ante)
		len_ante = handle_t_ante(t);
	ft_putstr("(null)");
	if (t->after)
		len_after = handle_t_after(t);
	return (6 + len_ante + len_after);
}

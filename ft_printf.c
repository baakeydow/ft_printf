/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 07:00:46 by bndao             #+#    #+#             */
/*   Updated: 2016/02/09 06:58:43 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int				handle(va_list conv, char *cpy, t_data *t, t_conv *c)
{
	if (*cpy == c->s)
		return (handle_s(conv, t, cpy));
	if (*cpy == c->d)
		return (handle_d(conv, t, cpy));
	return (0);
}

int						ft_printf(const char *restrict format, ...)
{
	va_list		conv;
	char		*cpy;
	t_data		*t;
	t_conv		*c;
	int			ret;

	ret = 0;
	cpy = ft_strdup(format);
	t = init(cpy);
	c = init_conv(cpy);
	if (!(t->p_cent))
		return (handle_no_p_cent(cpy));
	if (t->p_cent == 2 && double_percent(cpy))
		return (handle_glued());
	va_start(conv, format);
	while (*cpy)
	{
		while (*cpy++ == '%')
			ret += handle(conv, cpy, t, c);
	}
	va_end(conv);
	return (ret);
}

int					main(void)
{
	char		*str;
	char		*what;
	int			d;

	str = "42";
	what = "what";
	d = 24;
	ft_putstr("Wazzup 42 cool ? what ? 24 ?\n");
	ft_printf("Wazzup %s cool ? %s ? %d ?\n", str, what, d);
	/*ft_printf("salut ? %s ? %s", str, what);*/
	/*ft_printf("salut ? %s ? easy ?", str);*/
	/*ft_printf("Salut -|%s|- ? -|%s|- ?\n", str, what);*/
	/*ft_printf("%s", str);*/
	/*ft_printf("%d", d);*/
	return (0);
}

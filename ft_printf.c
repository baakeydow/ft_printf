/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:54:17 by bndao             #+#    #+#             */
/*   Updated: 2016/02/22 14:53:32 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int				handle(va_list conv, char *cpy, t_data *t, t_conv *c)
{
	if (*cpy == '%')
		return (handle_glued());
	if (c->s)
		return (handle_s(conv));
	if (c->d)
		return (handle_d(conv, t));
	if (c->c)
		return (handle_c(conv, t));
	return (0);
}

int						ft_printf(const char *restrict format, ...)
{
	va_list		conv;
	t_data		*t;
	t_conv		*c;
	int			ret;

	ret = 0;
	if (!(percent_nbr(format)))
		return (handle_no_p_cent(format));
	va_start(conv, format);
	while (*format)
	{
		ret += printchar((const char **)&format);
		if (*format++ == '%')
		{
			t = init(format);
			c = init_conv(format);
			ret += handle(conv, (char *)format, t, c);
			format = after_t_conv(format);
			c = wipe_conv();
			t = wipe_data();
		}
	}
	va_end(conv);
	return (ret);
}

/*int					main(void)*/
/*{*/
	/*char		*str;*/
	/*int			d;*/
	/*int			c;*/

	/*str = "24";*/
	/*d = 24;*/
	/*c = 'c';*/
	/*[>ft_printf("Wazzup ? cool %s easy %+-4d? %c\n", str, d, c);<]*/
	/*[>ft_printf("%s", str);<]*/
	/*[>ft_printf("%d", d);<]*/
	/*ft_printf("{%3c}", 0);*/
	/*return (0);*/
/*}*/

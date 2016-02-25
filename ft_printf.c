/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:54:17 by bndao             #+#    #+#             */
/*   Updated: 2016/02/25 03:23:15 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int				handle(va_list conv, char *cpy, t_data *t, t_conv *c)
{
	if (*cpy == '%')
		return (handle_glued());
	if (false_type(c))
		return (handle_false_type(t, cpy));
	if (c->s)
		return (handle_s(conv, t));
	if (c->d || c->i)
		return (handle_d(conv, t));
	if (c->c)
		return (handle_c(conv, t));
	if (c->C)
		return (handle_c_maj(conv, t));
	if (c->x)
		return (handle_x(conv, t));
	if (c->X)
		return (handle_x_maj(conv, t));
	if (c->p)
		return (handle_p(conv, t));
	if (c->o)
		return (handle_o(conv, t));
	return (0);
}

int						ft_printf(const char *restrict format, ...)
{
	va_list		conv;
	t_data		*t;
	t_conv		*c;
	int			ret;

	ret = 0;
	if (percent_nbr(format) == 0 || percent_nbr(format) == -1)
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

/*int						main(void)*/
/*{*/
	/*char		*str;*/
	/*int			d;*/
	/*int			c;*/

	/*str = "24";*/
	/*d = 42;*/
	/*c = 'c';*/
   /*[> ft_printf("Wazzup ? cool %s easy %+-4d? %c\n", str, d, c);<]*/
	/*[>ft_printf("la string (%s) est a l'adresse 0x%x\n", str, &str);<]*/
	/*[>ft_printf("%d\n", d);<]*/
	/*[>ft_printf("%x\n", d);<]*/
	/*[>ft_printf("{%-10%}\n");<]*/
	/*[>ft_printf("{%10%}\n");<]*/
	/*ft_printf("%15.4d", d);*/
	/*return (0);*/
/*}*/

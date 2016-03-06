/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:54:17 by bndao             #+#    #+#             */
/*   Updated: 2016/03/06 14:05:22 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int				handle(va_list conv, char *cpy, t_data *t, t_conv *c)
{
	if (*cpy == '%')
		return (handle_glued(t));
	if (false_type(c))
		return (handle_false_type(c, t, cpy));
	if (c->s)
		return (handle_s(conv, t, c));
	if (c->S)
		return (handle_s_maj(conv, t, c));
	if (c->d || c->i)
		return (handle_d(conv, t, c));
	if (c->u)
		return (handle_u(conv, t, c));
	if (c->c)
		return (handle_c(conv, t, c));
	if (c->C)
		return (handle_c_maj(conv, t, c));
	if (c->x)
		return (handle_x(conv, t, c));
	if (c->X)
		return (handle_x_maj(conv, t, c));
	if (c->p)
		return (handle_p(conv, t, c));
	if (c->o)
		return (handle_o(conv, t, c));
	if (c->O)
		return (handle_o_maj(conv, t, c));
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
			format = after_t_conv(format, c, t);
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
	/*d = -42;*/
	/*c = 'c';*/
   /*[> ft_printf("Wazzup ? cool %s easy %+-4d? %c\n", str, d, c);<]*/
	/*[>ft_printf("la string (%s) est a l'adresse 0x%x\n", str, &str);<]*/
	/*[>ft_printf("%d\n", d);<]*/
	/*[>ft_printf("%x\n", d);<]*/
	/*[>ft_printf("{%-10%}\n");<]*/
	/*[>ft_printf("%.3d", 0);<]*/
	/*[>ft_printf("%u", 4294967295);<]*/
	/*[>ft_printf("%05d", -42);<]*/
	/*[>ft_printf("%-05o", 2500);<]*/
	/*[>ft_printf("%-10.5o", 2500);<]*/
	/*[>ft_printf("%S", L"米");<]*/
	/*[>ft_printf("%C", L'猫');<]*/
	/*ft_printf("{%05.c}", 0);*/
	/*[>ft_printf("%d\n", ft_printf("{%010d}", -42));<]*/
	/*[>ft_printf("%#-08x", 42);<]*/
	/*[>ft_printf("%5.2s is a string", "");<]*/
	/*return (0);*/
/*}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:54:17 by bndao             #+#    #+#             */
/*   Updated: 2016/03/09 15:07:35 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_va_arg				tab[TAB_SIZE] = {{&handle_s, 's'},
	{&handle_s_maj, 'S'}, {&handle_p, 'p'}, {&handle_d, 'd'},
	{&handle_d_maj, 'D'}, {&handle_i, 'i'}, {&handle_o, 'o'},
	{&handle_o_maj, 'O'}, {&handle_u, 'u'}, {&handle_u_maj, 'U'},
	{&handle_x, 'x'}, {&handle_x_maj, 'X'}, {&handle_c, 'c'},
	{&handle_c_maj, 'C'}};

static int				handle(va_list conv, t_va_arg tab[TAB_SIZE], t_data *t, t_conv *c)
{
	int			i;

	i = 0;
	if (*(t->cpy) == '%')
		return (handle_glued(t));
	if (false_type(c))
		return (handle_false_type(c, t));
	while (i < TAB_SIZE)
	{
		if (tab[i].c == return_char(c->b_t_conv, tab[i].c))
			return (tab[i].f(conv, t, c));
		i++;
	}
	return (0);
}

int						handle_d_maj(va_list conv, t_data *t, t_conv *c)
{
	return (handle_d(conv, t, c));
}

int						handle_i(va_list conv, t_data *t, t_conv *c)
{
	return (handle_d(conv, t, c));
}

int						handle_u_maj(va_list conv, t_data *t, t_conv *c)
{
	return (handle_u(conv, t, c));
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
			ret += handle(conv, tab, t, c);
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
	/*ft_printf("%.4u", 424242);*/
	/*[>ft_printf("%u", 4294967295);<]*/
	/*[>ft_printf("%05d", -42);<]*/
	/*[>ft_printf("%-05o", 2500);<]*/
	/*[>ft_printf("%-10.5o", 2500);<]*/
	/*[>ft_printf("%S", L"米");<]*/
	/*[>ft_printf("%C", L'猫');<]*/
	/*[>ft_printf("{%05.c}", 0);<]*/
	/*[>ft_printf("%15.4s", "42");<]*/
	/*[>ft_printf("{% C}", 0);<]*/
	/*[>ft_printf("%d\n", ft_printf("{%010d}", -42));<]*/
	/*[>ft_printf("{%30S}", L"我是一只猫。");<]*/
	/*[>ft_printf("%#-08x", 42);<]*/
	/*[>ft_printf("{%+03d}", 0);<]*/
	/*[>ft_printf("%U", ULONG_MAX / 2);<]*/
	/*[>ft_printf("%ld", (long)INT_MAX + 1);<]*/
	/*[>ft_printf("%5.2s is a string", "");<]*/
	/*return (0);*/
/*}*/

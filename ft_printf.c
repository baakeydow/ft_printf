/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 07:00:46 by bndao             #+#    #+#             */
/*   Updated: 2016/02/08 21:09:29 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int						handle(va_list conv, char *cpy, t_data *t, t_conv *c)
{
	if (*cpy == c->s)
		return (handle_s(conv, t, cpy));
	if (*cpy == c->d)
		return (handle_d(conv, t, cpy));
	return (0);
}

static char				**add_char(char **sp)
{
	int		i;
	int		d;
	char	**mod;

	d = 0;
	while (sp[d])
		d++;
	if (!(mod = (char **)malloc(sizeof(char *) * (d + 1))))
		return (NULL);
	mod[d] = NULL;
	i = 0;
	while (sp[i] && i + 1 < d)
	{
		mod[i] = ft_strjoin(sp[i], " ");
		i++;
	}
	mod[i] = ft_strdup(sp[i]);
	return (mod);
}

int						ft_printf(const char *restrict format, ...)
{
	va_list		conv;
	t_data		*t;
	t_conv		*c;
	int			ret;
	int			i;
	char		**sp;

	ret = 0;
	i = 0;
	sp = ft_strsplit(format, ' ');
	if (sp[1])
		sp = add_char(sp);
	while (sp && sp[i])
	{
		t = init(sp[i]);
		c = init_conv(sp[i]);
		if (!(t->p_cent))
			ret += handle_no_p_cent(sp[i]);
		if (t->p_cent == 2 && double_percent(sp[i]))
			ret += (handle_glued(t));
		va_start(conv, format);
		while (*sp[i])
		{
			while (*sp[i]++ == '%')
				ret += handle(conv, sp[i], t, c);
		}
		va_end(conv);
		i++;
	}
	return (ret);
}

int					main(void)
{
	char		*str;
	char		*hein;
	int			d;

	str = "42";
	hein = "hein";
	d = 24;
   /* ft_putstr("Salut 42 cool ? hein ? 24 ?\n");*/
	/*ft_printf("Salut %s cool ? %s ? %d ?\n", str, hein, d);*/
	/*ft_printf("Hein ? %d ?\n", d);*/
	ft_printf("Salut %d ? %s ?\n", d, str);
	/*ft_printf("salut %s sfrg dh", str);*/
	/*ft_printf("%d", d);*/
	return (0);
}

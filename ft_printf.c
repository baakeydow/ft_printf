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
	if (!(t->p_cent))
		return (handle_no_p_cent(cpy));
	va_start(conv, format);
	while (*cpy)
	{
		ret += printchar(&cpy);
		if (t->p_cent == 2 && double_percent(cpy))
			ret += (handle_glued());
		if (*cpy++ == '%')
		{
			c = init_conv(cpy);
			ret += handle(conv, cpy, t, c);
			cpy = after_t_conv(cpy);
		}
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
	/*ft_putstr("Wazzup 42 cool ? what ? 24 ?\n");*/
	ft_printf("Wazzup %s cool ? %s ? %d ?\n", str, what, d);
	/*ft_printf("salut ? %s ? easy ?", str);*/
	/*ft_printf("Salut -|%s|- ? -|%s|- ?\n", str, what);*/
	/*ft_printf("%s", str);*/
	/*ft_printf("%d", d);*/
	return (0);
}

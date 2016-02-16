#include "printf.h"

static int				handle(va_list conv, char *cpy, t_data *t, t_conv *c)
{
	if (*cpy == '%')
		return (handle_glued());
	if (*cpy == c->s)
		return (handle_s(conv));
	if (*cpy == c->d)
		return (handle_d(conv));
	if (c->b_t_conv)
		return (handle_fmt(conv, cpy, t, c));
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
	if (!(percent_nbr(cpy)))
		return (handle_no_p_cent(cpy));
	va_start(conv, format);
	while (*cpy)
	{
		ret += printchar(&cpy);
		if (*cpy++ == '%')
		{
			t = init(cpy);
			c = init_conv(cpy);
			ret += handle(conv, cpy, t, c);
			cpy = after_t_conv(cpy);
			c = wipe_conv();
			t = wipe_data();
		}
	}
	va_end(conv);
	return (ret);
}

int					main(void)
{
	char		*str;
	int			d;

	str = "42";
	d = 24;
	ft_printf("Wazzup ? cool %s easy %-4d?", str, d);
	/*ft_printf("%s", str);*/
	/*ft_printf("%d", d);*/
	return (0);
}

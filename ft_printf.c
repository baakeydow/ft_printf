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

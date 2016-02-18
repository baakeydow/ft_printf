#include "printf.h"

int					handle_s(va_list conv)
{
	char		*str;

	if (!(str = va_arg(conv, char *)))
		return (null_case());
	ft_putstr(str);
	return (ft_strlen(str));
}

int					handle_d(va_list conv, t_data *t)
{
	int			d;
	int			ret;

	ret = 0;
	if (!(d = va_arg(conv, int)))
		return (null_case());
	if (d >= 0 && t->o_plus)
	{
		ft_putchar('+');
		ret = 1;
	}
	ft_putnbr(d);
	ret += ft_strlen(ft_itoa(d));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa(d)), t);
	return (ret);
}

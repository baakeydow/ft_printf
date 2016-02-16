#include "printf.h"

int					handle_s(va_list conv)
{
	char		*str;

	if (!(str = va_arg(conv, char *)))
		return (null_case());
	ft_putstr(str);
	return (ft_strlen(str));
}

int					handle_d(va_list conv)
{
	int			d;

	if (!(d = va_arg(conv, int)))
		return (null_case());
	ft_putnbr(d);
	return (ft_strlen(ft_itoa(d)));
}

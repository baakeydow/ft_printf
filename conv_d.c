#include "printf.h"

int					handle_d(va_list conv, t_data *t, char *cpy)
{
	int			d;

	if (!(d = va_arg(conv, int)))
		return (null_case());
	ft_putnbr(d);
	return (ft_strlen(ft_itoa(d)));
}

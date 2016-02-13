#include "printf.h"

int					handle_s(va_list conv, t_data *t, char *cpy)
{
	char		*str;

	if (!(str = va_arg(conv, char *)))
		return (null_case());
	ft_putstr(str);
	return (ft_strlen(str));
}

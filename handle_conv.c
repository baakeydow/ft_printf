#include "printf.h"

int		handle_fmt(va_list conv, char *cpy, t_data *t, t_conv *c)
{
	return (t->width + handle_d(conv) + ft_strlen(c->b_t_conv) + ft_strlen(cpy));
}

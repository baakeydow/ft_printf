#include "printf.h"

int				printchar(char **cpy)
{
	if (**cpy == '%')
		return (0);
	ft_putchar(*cpy[0]);
	return (1);
}

int				handle_no_p_cent(char *cpy)
{
	ft_putstr(cpy);
	return (ft_strlen(cpy));
}

int				handle_glued(void)
{
	ft_putchar('%');
	return (1);
}

int				null_case(void)
{
	ft_putstr("(null)");
	return (6);
}

char			*get(char *fmt)
{
	char *dup;

	dup = ft_strdup(fmt);
	dup[1] = '\0';
	return (dup);
}

int				towork(va_list conv, t_data *t, char *cpy, t_conv *c)
{
	ft_putchar(t->o_minus);
	ft_putnbr(t->width);
	ft_putchar(c->d);
	return (ft_strlen(c->b_t_conv));
}

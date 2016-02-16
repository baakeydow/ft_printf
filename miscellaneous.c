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

#include "printf.h"

int						handle_width(int len_conv, t_data *t)
{
	int			i;

	i = t->width - len_conv;
	if (i <= 0)
		return (0);
	while (i)
	{
		ft_putchar(' ');
		i--;
	}
	return (t->width - len_conv);
}

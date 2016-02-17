#include "printf.h"

char					return_char(const char *fmt, char c)
{
	int				i;

	i = 0;
	if (!fmt)
		return (0);
	while (fmt[i])
	{
		if (fmt[i] == c)
			return (c);
		i++;
	}
	return (0);
}

int						percent_nbr(const char *fmt)
{
	size_t			i;
	int				p;

	i = 0;
	p = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
			p++;
		i++;
	}
	return (p);
}

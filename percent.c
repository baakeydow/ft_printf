#include "printf.h"

char					*post_percent(char *fmt)
{
	char		*str;
	char		*dup;

	dup = ft_strdup(fmt);
	if (!(str = ft_strchr(dup, '%')))
		return(dup);
	return (str + 1);
}

int						double_percent(char *fmt)
{
	if (fmt[0] == '%' && fmt[1] == '%')
		return (1);
	return (0);
}

char					return_char(char *fmt, char c)
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

int						percent_nbr(char *fmt)
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

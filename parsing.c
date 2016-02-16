#include "printf.h"

int						is_b_t_conv(char *fmt, int *i)
{
	if (fmt[*i] == 's' || fmt[*i] == 'S' || fmt[*i] == 'p' ||
			fmt[*i] == 'd' || fmt[*i] == 'D' || fmt[*i] == 'i' ||
			fmt[*i] == 'o' || fmt[*i] == 'O' || fmt[*i] == 'u' ||
			fmt[*i] == 'U' || fmt[*i] == 'x' || fmt[*i] == 'X' ||
			fmt[*i] == 'c' || fmt[*i] == 'C')
		return (0);
	return (1);
}

char					*after_t_conv(char *fmt)
{
	int			i;

	i = 0;
	while (fmt[i])
	{
		if (!is_b_t_conv(fmt, &i))
			break ;
		if (fmt[i] == '%')
			break ;
		++i;
	}
	return (ft_strsub(fmt, i + 1, ft_strlen(fmt) - i));
}

char					*before_t_conv(char *fmt)
{
	int			i;

	i = 0;
	if (!is_b_t_conv(fmt, &i))
		return (get(fmt));
	while (fmt[i])
	{
		if (!is_b_t_conv(fmt, &i))
			break ;
		i++;
	}
	return (ft_strsub(fmt, 0, i + 1));
}

t_data					*init(char *cpy)
{
	t_data		*ptr;

	if (!(ptr = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	ptr->i_fmt = ft_strdup(cpy);
	ptr->o_minus = return_char(before_t_conv(cpy), '-');
	ptr->o_plus = return_char(before_t_conv(cpy), '+');
	ptr->o_diez = return_char(before_t_conv(cpy), '#');
	ptr->o_zero = return_char(before_t_conv(cpy), '0');
	ptr->o_space = return_char(before_t_conv(cpy), ' ');
	ptr->width = 4;
	ptr->precision = 0;
	ptr->length = "0";
	return (ptr);
}

t_conv					*init_conv(char *cpy)
{
	t_conv		*ptr;

	if (!(ptr = (t_conv *)malloc(sizeof(t_conv))))
		return (NULL);
	ptr->b_t_conv = before_t_conv(cpy);
	ptr->s = return_char(before_t_conv(cpy), 's');
	ptr->S = return_char(before_t_conv(cpy), 'S');
	ptr->p = return_char(before_t_conv(cpy), 'p');
	ptr->d = return_char(before_t_conv(cpy), 'd');
	ptr->D = return_char(before_t_conv(cpy), 'D');
	ptr->i = return_char(before_t_conv(cpy), 'i');
	ptr->o = return_char(before_t_conv(cpy), 'o');
	ptr->O = return_char(before_t_conv(cpy), 'O');
	ptr->u = return_char(before_t_conv(cpy), 'u');
	ptr->U = return_char(before_t_conv(cpy), 'U');
	ptr->x = return_char(before_t_conv(cpy), 'x');
	ptr->X = return_char(before_t_conv(cpy), 'X');
	ptr->c = return_char(before_t_conv(cpy), 'c');
	ptr->C = return_char(before_t_conv(cpy), 'C');
	return (ptr);
}

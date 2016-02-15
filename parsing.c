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
		return (NULL);
	while (fmt[i])
	{
		if (!is_b_t_conv(fmt, &i))
			break ;
		i++;
	}
	return (ft_strsub(fmt, 0, i));
}

t_data					*init(char *cpy)
{
	t_data		*ptr;

	if (!(ptr = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	ptr->i_fmt = ft_strdup(cpy);
	ptr->p_cent = percent_nbr(cpy);
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
	ptr->s = return_char(cpy, 's');
	ptr->S = return_char(cpy, 'S');
	ptr->p = return_char(cpy, 'p');
	ptr->d = return_char(cpy, 'd');
	ptr->D = return_char(cpy, 'D');
	ptr->i = return_char(cpy, 's');
	ptr->o = return_char(cpy, 's');
	ptr->O = return_char(cpy, 's');
	ptr->u = return_char(cpy, 's');
	ptr->U = return_char(cpy, 's');
	ptr->x = return_char(cpy, 's');
	ptr->X = return_char(cpy, 's');
	ptr->c = return_char(cpy, 's');
	ptr->C = return_char(cpy, 's');
	return (ptr);
}

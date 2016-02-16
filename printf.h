#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_data
{
	char		o_minus;
	char		o_plus;
	char		o_diez;
	char		o_zero;
	char		o_space;
	int			width;
	int			precision;
	char		*length;
}				t_data;

typedef struct	s_conv
{
	char		*b_t_conv;
	char		s;
	char		S;
	char		p;
	char		d;
	char		D;
	char		i;
	char		o;
	char		O;
	char		u;
	char		U;
	char		x;
	char		X;
	char		c;
	char		C;
}				t_conv;

int				handle_no_p_cent(char *cpy);
int				handle_glued(void);
int				percent_nbr(char *fmt);
t_data			*init(char *cpy);
t_data			*wipe_data(void);
t_conv			*init_conv(char *cpy);
t_conv			*wipe_conv(void);
char			*before_t_conv(char *fmt);
char			*after_t_conv(char *fmt);
int				is_b_t_conv(char *fmt, int *i);
char			return_char(char *fmt, char c);
int				null_case(void);
int				printchar(char **cpy);
char			*get(char *fmt);
int				handle_fmt(va_list conv, char *cpy, t_data *t, t_conv *c);
int				handle_s(va_list conv);
int				handle_d(va_list conv);

#endif

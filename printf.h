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
char			*post_percent(char *fmt);
int				percent_nbr(char *fmt);
int				double_percent(char *fmt);
char			*before_t_conv(char *fmt);
char			*after_t_conv(char *fmt);
int				is_b_t_conv(char *fmt, int *i);
char			return_char(char *fmt, char c);
t_data			*init(char *cpy);
t_data			*wipe_data(void);
t_conv			*init_conv(char *cpy);
t_conv			*wipe_conv(void);
int				handle_s(va_list conv, t_data *t, char *cpy);
int				handle_d(va_list conv, t_data *t, char *cpy);
int				null_case(void);
int				printchar(char **cpy);
char			*get(char *fmt);
int				towork(va_list conv, t_data *t, char *cpy, t_conv *c);

#endif

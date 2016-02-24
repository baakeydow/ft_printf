/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:55:16 by bndao             #+#    #+#             */
/*   Updated: 2016/02/24 11:38:11 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char			*ft_itoa_base(long int nbr, int base, char c);
int				false_type(t_conv *c);
int				printchar(const char **cpy);
int				handle_no_p_cent(const char *cpy);
int				is_not_data(const char *fmt, int *i);
int				handle_glued(void);
int				percent_nbr(const char *fmt);
t_data			*init(const char *cpy);
t_data			*wipe_data(void);
t_conv			*init_conv(const char *cpy);
t_conv			*wipe_conv(void);
char			*before_t_conv(const char *fmt);
char			*after_t_conv(const char *fmt);
int				is_b_t_conv(const char *fmt, int *i);
char			return_char(char *fmt, char c);
char			find_o_zero(char *fmt);
int				null_case(void);
char			*get(const char *fmt);
int				find_width(char *str);
int				handle_width(int len_conv, t_data *t);
int				handle_width_d(int len_conv, t_data *t, int d);
int				handle_o_zero(int d, t_data *t);
int				handle_false_type(t_data *t, char *cpy);
int				handle_s(va_list conv);
int				handle_d(va_list conv, t_data *t);
int				handle_c(va_list conv, t_data *t);
int				handle_c_maj(va_list conv, t_data *t);
int				handle_x(va_list conv, t_data *t);
int				handle_x_maj(va_list conv, t_data *t);
int				handle_o(va_list conv, t_data *t);
int				handle_p(va_list conv, t_data *t);

#endif

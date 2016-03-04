/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:55:16 by bndao             #+#    #+#             */
/*   Updated: 2016/03/04 17:50:04 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <wchar.h>

typedef struct	s_data
{
	char		o_minus;
	char		o_plus;
	char		o_diez;
	char		o_zero;
	char		o_space;
	int			width;
	int			prec;
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

int				ft_printf(const char *format, ...);
char			*ft_widechar_2_reg(wchar_t wide);
char			*ft_widestr_2_reg(wchar_t *src);
char			*ft_itoa_base(long int nbr, int base, char c);
char			*ft_nbr_to_char(int nbr, int base, char c);
int				false_type(t_conv *c);
int				printchar(const char **cpy);
int				handle_no_p_cent(const char *cpy);
int				is_not_data(const char *fmt, int *i);
int				handle_glued(t_data *t);
int				percent_nbr(const char *fmt);
t_data			*init(const char *cpy);
t_data			*wipe_data(void);
t_conv			*init_conv(const char *cpy);
t_conv			*wipe_conv(void);
char			*before_t_conv(const char *fmt);
char			*after_t_conv(const char *fmt, t_conv *c, t_data *t);
int				is_b_t_conv(const char *fmt, int *i);
char			*get(const char *fmt);
char			return_char(char *fmt, char c);
int				null_case(void);
int				null_case_s(t_data *t);
char			find_o_zero(char *fmt);
int				find_width(char *str);
int				find_prec(char *str);
int				prec_str(t_data *t, char *str, t_conv *c);
int				len_str(t_data *t, char *str);
int				handle_width_d(int len_conv, t_data *t, int d);
int				handle_width(int len_conv, t_data *t, t_conv *c);
int				handle_o_point(int len_conv, t_data *t, int d);
int				handle_o_zero_d(int d, t_data *t);
int				handle_o_space(int d, t_data *t, t_conv *c);
int				handle_false_type(t_conv *c, t_data *t, char *cpy);
int				handle_s(va_list conv, t_data *t, t_conv *c);
int				handle_d(va_list conv, t_data *t, t_conv *c);
int				handle_u(va_list conv, t_data *t, t_conv *c);
void			ft_putnbr_u(unsigned int n);
int				handle_c(va_list conv, t_data *t, t_conv *c);
int				handle_c_maj(va_list conv, t_data *t, t_conv *c);
int				handle_x(va_list conv, t_data *t, t_conv *c);
int				handle_x_maj(va_list conv, t_data *t, t_conv *c);
int				handle_o(va_list conv, t_data *t, t_conv *c);
int				handle_o_maj(va_list conv, t_data *t, t_conv *c);
int				handle_p(va_list conv, t_data *t, t_conv *c);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 23:35:59 by bndao             #+#    #+#             */
/*   Updated: 2016/03/12 18:33:40 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*ft_zero_or_min(int number)
{
	char	*str;

	if (number == 0)
		str = ft_strdup("0");
	else
		str = ft_strdup("-2147483648");
	return (str);
}

static char		*str_size(char **str, int *not_neg, size_t *i, int *rem)
{
	*i = 0;
	*not_neg = 1;
	*rem = 0;
	if (!((*str) = (char *)malloc(sizeof(char) * 12)))
		return (NULL);
	return (*str);
}

char			*ft_itoa_base(long long int nbr, int base, char c)
{
	int		d[2];
	size_t	i;
	char	*str_number;

	if (!(str_size(&str_number, &d[1], &i, &d[0])))
		return (NULL);
	if (nbr == 0 || nbr == LLONG_MIN)
		return (ft_zero_or_min(nbr));
	if (nbr < 0)
	{
		nbr = -nbr;
		d[1] = 0;
	}
	while (nbr)
	{
		d[0] = nbr % base;
		str_number[i++] = (d[0] > 9) ? (d[0] - 10) + c : d[0] + '0';
		nbr = nbr / base;
	}
	if (!d[1])
		str_number[i++] = '-';
	str_number[i] = '\0';
	return (ft_strrev(str_number));
}

static char		*str_length(char **str, size_t *i, int *rem)
{
	*i = 0;
	*rem = 0;
	if (!((*str) = (char *)malloc(sizeof(char) * 20)))
		return (NULL);
	return (*str);
}

char			*ft_uitoa_base(uintmax_t nbr, int base, char c)
{
	int		d;
	size_t	i;
	char	*str_number;

	if (!(str_length(&str_number, &i, &d)))
		return (NULL);
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr)
	{
		d = nbr % base;
		str_number[i++] = (d > 9) ? (d - 10) + c : d + '0';
		nbr = nbr / base;
	}
	str_number[i] = '\0';
	return (ft_strrev(str_number));
}

char				*ft_widechar_2_reg(wchar_t wide)
{
	char	str[5];

	ft_bzero(str, 5);
	if (wide < 128)
		str[0] = (char)wide;
	else if (wide < 2048)
	{
		str[0] = (wide >> 6) + 192;
		str[1] = (wide & 63) + 128;
	}
	else if (wide < 65536)
	{
		str[0] = (wide >> 12) + 224;
		str[1] = ((wide >> 6) & 63) + 128;
		str[2] = (wide & 63) + 128;
	}
	else if (wide < 1114112)
	{
		str[0] = (wide >> 18) + 240;
		str[1] = ((wide >> 12) & 63) + 128;
		str[2] = ((wide >> 6) & 63) + 128;
		str[3] = (wide & 63) + 128;
	}
	return (ft_strdup(str));
}

char				*ft_widestr_2_reg(wchar_t *src)
{
	char	*str;
	char 	*ante;
	char	*post;

	if (!(str = ft_strnew(0)))
		return (NULL);
	while (*src)
	{
		ante = str;
		if (!(post = ft_widechar_2_reg(*src)))
			return (NULL);
		if (!(str = ft_strjoin(ante, post)))
			return (NULL);
		src++;
		ft_strdel(&ante);
		ft_strdel(&post);
	}
	return (str);
}

static char		*ft_z_or_m(intmax_t number)
{
	char	*str;

	if (number == 0)
		str = ft_strdup("0");
	else
		str = ft_strdup("-9223372036854775808");
	return (str);
}

static char		*s_size(char **str, int *not_neg, size_t *i)
{
	*i = 0;
	*not_neg = 1;
	if (!((*str) = (char *)malloc(sizeof(char) * 19)))
		return (NULL);
	return (*str);
}

char			*ft_itoa_ll(intmax_t nbr)
{
	int		pos;
	size_t	i;
	char	*str_number;

	if (!(s_size(&str_number, &pos, &i)))
		return (NULL);
	if (nbr == 0 || nbr <= LLONG_MIN)
		return (ft_z_or_m(nbr));
	if (nbr < 0)
	{
		nbr = -nbr;
		pos = 0;
	}
	while (nbr)
	{
		str_number[i] = (nbr) % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	if (!pos)
		str_number[i++] = '-';
	str_number[i] = '\0';
	return (ft_strrev(str_number));
}

static char		*s_s(char **str, size_t *i)
{
	*i = 0;
	if (!((*str) = (char *)malloc(sizeof(char) * 19)))
		return (NULL);
	return (*str);
}

char			*ft_itoa_ull(uintmax_t nbr)
{
	size_t	i;
	char	*str_number;

	if (!(s_s(&str_number, &i)))
		return (NULL);
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr)
	{
		str_number[i] = (nbr) % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	str_number[i] = '\0';
	return (ft_strrev(str_number));
}

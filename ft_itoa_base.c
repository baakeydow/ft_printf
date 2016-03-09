/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 23:35:59 by bndao             #+#    #+#             */
/*   Updated: 2016/03/09 03:48:06 by bndao            ###   ########.fr       */
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

char			*ft_itoa_base(long int nbr, int base, char c)
{
	int		d[2];
	size_t	i;
	char	*str_number;

	if (!(str_size(&str_number, &d[1], &i, &d[0])))
		return (NULL);
	if (nbr == 0 || nbr == -2147483648)
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

static int				binary_to_dec(char *str)
{
	int		n;

	n = 0;
	str = ft_strrev(str);
	if (str[0] == '1')
		n = 1;
	if (str[1] == '1')
		n += 2;
	if (str[2] == '1')
		n += 4;
	if (str[3] == '1')
		n += 8;
	if (str[4] == '1')
		n += 16;
	if (str[5] == '1')
		n += 32;
	if (str[6] == '1')
		n += 64;
	if (str[7] == '1')
		n += 128;
	return (ft_atoi(ft_itoa_base(n, 10, 'a')));
}

char				*ft_nbr_to_char(int nbr, int base, char c)
{
	char	*str;
	int		i;
	int		fix;

	fix = 0;
	str = ft_strnew(100);
	i = 0;
	if (nbr >= 0)
		return (ft_itoa_base(nbr, base, c));
	nbr = -nbr;
	str = ft_itoa_base(nbr, 2, c);
	if (ft_strlen(str) < 8)
	{
		fix = 8 - ft_strlen(str);
		while (fix)
		{
			str = ft_strjoin("0", str);
			fix--;
		}
	}
	while (str[i])
	{
		if (str[i] == '1')
			str[i] = '0';
		else if (str[i] == '0')
			str[i] = '1';
		i++;
	}
	i = binary_to_dec(str);
	i = i + 1;
	return (ft_itoa_base(i, base, c));
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

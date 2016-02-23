/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 23:35:59 by bndao             #+#    #+#             */
/*   Updated: 2016/02/23 05:54:13 by bndao            ###   ########.fr       */
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

char			*ft_itoa_base(long int nbr, int base)
{
	int		rem;
	int		pos;
	size_t	i;
	char	*str_number;

	if (!(str_size(&str_number, &pos, &i, &rem)))
		return (NULL);
	if (nbr == 0 || nbr == -2147483648)
		return (ft_zero_or_min(nbr));
	if (nbr < 0)
	{
		nbr = -nbr;
		pos = 0;
	}
	while (nbr)
	{
		rem = nbr % base;
		str_number[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		nbr = nbr / base;
	}
	if (!pos)
		str_number[i++] = '-';
	str_number[i] = '\0';
	return (ft_strrev(str_number));
}

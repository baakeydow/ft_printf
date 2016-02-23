/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:54:26 by bndao             #+#    #+#             */
/*   Updated: 2016/02/23 06:16:18 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int						handle_width(int len_conv, t_data *t)
{
	int			i;

	i = t->width - len_conv;
	if (i <= 0)
		return (0);
	while (i)
	{
		ft_putchar(' ');
		i--;
	}
	return (t->width - len_conv);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:55:55 by bndao             #+#    #+#             */
/*   Updated: 2016/02/22 16:00:01 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				printchar(const char **cpy)
{
	if (**cpy == '%')
		return (0);
	ft_putchar(*cpy[0]);
	return (1);
}

int				handle_no_p_cent(const char *cpy)
{
	if (!cpy)
		return (-1);
	ft_putstr(cpy);
	return (ft_strlen(cpy));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:21:05 by bndao             #+#    #+#             */
/*   Updated: 2016/01/04 17:19:12 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_show_tab(t_stock_par *par)
{
	int				nb;
	int				i;

	nb = 0;
	while (par && par->str)
	{
		i = 0;
		ft_putstr("Argument: ");
		ft_putstr(par->str);
		ft_putstr("\n");
		ft_putstr("Taille: ");
		ft_putnbr(par->size_param);
		ft_putstr("\n");
		while (par->tab && par->tab[i])
		{
			ft_putstr("sous-chaine: ");
			ft_putstr(par->tab[i]);
			ft_putstr("\n");
			i++;
		}
		ft_putstr("\n\n");
		par++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:21:05 by bndao             #+#    #+#             */
/*   Updated: 2016/01/04 17:18:48 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stock_par			*ft_param_to_tab(int ac, char **av)
{
	int				nb;
	int				cpt;
	t_stock_par		*tab;

	nb = 0;
	cpt = 0;
	if (!av)
		return (NULL);
	if (!(tab = (t_stock_par *)malloc(sizeof(t_stock_par) * ac + 1)))
		return (NULL);
	nb = 0;
	while (nb < ac)
	{
		ft_memset(&tab[nb], 0, sizeof(struct s_stock_par));
		tab[nb].size_param = ft_strlen(av[nb]);
		tab[nb].str = av[nb];
		tab[nb].copy = ft_strdup(av[nb]);
		tab[nb].tab = ft_split_whitespaces(av[nb]);
		nb++;
	}
	tab[nb].str = NULL;
	return (tab);
}

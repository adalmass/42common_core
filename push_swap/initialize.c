/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:42:22 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/23 11:12:51 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_tab_b(t_tabs *tab)
{
	tab->tab_b = ft_calloc(tab->len_tab_a + 1, sizeof(char *));
	if (!tab->tab_b)
		ft_error("tab_b : calloc failed\n");
}

void	initialize(t_tabs *tab, char **av)
{
	int		i;
	char	*temp;

	i = 1;
	tab->count = 0;
	tab->max = 0;
	tab->max_idx = 0;
	tab->len_tab_a = 0;
	temp = ft_strdup("");
	while (av[i])
	{
		temp = ft_strjoin_gnl(temp, av[i]);
		temp = ft_strjoin_gnl(temp, " ");
		i++;
	}
	tab->tab_a = ft_split(temp, ' ');
	tab->copy_a = ft_split(temp, ' ');
	if (temp)
		free(temp);
}

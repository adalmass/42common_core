/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_nb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:29:46 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/07 08:38:46 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_copy_a(t_tabs *tab)
{
	int	y;

	y = 0;
	tab->copy_a = ft_calloc(tab->len_tab_a + 1, sizeof(char *));
	if (!tab->tab_b)
		ft_error("tab_b : calloc failed\n");
	while (tab->tab_a[y])
	{
		tab->copy_a[y] = tab->tab_a[y];
		y++;
	}
	tab->copy_a[y] = NULL;
}

void	sort_copy_a(t_tabs *tab)
{
	int		y;
	int		modified;
	char	*temp;

	modified = 1;
	temp = NULL;
	while (modified)
	{
		modified = 0;
		y = 0;
		while (tab->copy_a[y + 1])
		{
			if (ft_atoi(tab->copy_a[y]) > ft_atoi(tab->copy_a[y + 1]))
			{
				temp = tab->copy_a[y];
				tab->copy_a[y] = tab->copy_a[y + 1];
				tab->copy_a[y + 1] = temp;
				modified = 1;
			}
			y++;
		}
	}
}

void	simplify_tab_a(t_tabs *tab)
{
	int	y;
	int	z;

	y = 0;
	while (tab->tab_a[y])
	{
		z = 0;
		while (tab->copy_a[z])
		{
			if (ft_atoi(tab->tab_a[y]) == ft_atoi(tab->copy_a[z]))
			{
				tab->tab_a[y] = ft_itoa(z + 1);
				break ;
			}
			z++;
		}
		y++;
	}
}

void	handle_tab_a(t_tabs *tab)
{
	init_copy_a(tab);
	sort_copy_a(tab);
	simplify_tab_a(tab);
}

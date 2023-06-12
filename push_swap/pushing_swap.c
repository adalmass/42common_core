/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:49:58 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/12 19:36:14 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_tabs *tab)
{
	int	y;

	y = 0;
	while (tab->tab_b[y] && y < 1)
		y++;
	if (y > 0)
		tab->tab_a[0] = tab->tab_b[0];
	y = 0;
	while (tab->tab_b[y])
	{
		tab->tab_b[y] = tab->tab_b[y + 1];
		y++;
	}
	ft_putstr("pa\n");
}

// void	pb(t_tabs *tab)
// {
// 	int		i = 0;
// 	int		j = 0;
// 	char	*temp;
// 	char	**new_b;

// 	temp = ft_strdup(tab->tab_a[0]);
// 	free(tab->tab_a[0]);
// 	tab->tab_a[0] = ft_strdup("#");
// 	while (tab->tab_b[i] != NULL)
// 		i++;
// 	new_b = malloc(sizeof(char *) * i + 2);
// 	new_b[0] = temp;
// 	i = 1;
// 	while (tab->tab_b[i] != NULL)
// 		new_b[i++] = ft_strdup(tab->tab_b[j++]);
// 	tab->tab_b = new_b;
// }

void	pb(t_tabs *tab)
{
	int	y;
	int	len;
	
	y = 0;
	len = 0;
	while (tab->tab_a[len])
		len++;
	y = len;
	if (y >= 0)
	{
		while (y >= 0)
		{
			tab->tab_b[y] = tab->tab_b[y - 1];
			y--;
		}
		tab->tab_b[0] = tab->tab_a[0];
		y = 0;
		while (y < len - 1)
		{
			tab->tab_a[y] = tab->tab_a[y + 1];
			y++;
		}
		DEBUG_print_tab_a(tab);
		DEBUG_print_tab_b(tab);
		ft_putchar('\n');
	}
}

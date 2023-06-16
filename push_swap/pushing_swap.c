/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:49:58 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/16 19:19:57 by aldalmas         ###   ########.fr       */
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

// void	pb(t_tabs *tab)
// {
// 	int	y;
// 	int	len;

// 	y = 0;
// 	len = 0;
// 	while (tab->tab_a[y])
// 	{
// 		printf("%s     |     %s\n", tab->tab_a[y], tab->tab_b[y]);
// 		y++;
// 	}
// 	len = y;
// 	while (y > 0)
// 	{
// 		tab->tab_b[y] = tab->tab_b[y - 1];
// 		y--;
// 	}
// 	ft_printf("y %d\n", y);
// 	tab->tab_b[y] = tab->tab_a[y];
// 	while (y < len)
// 	{
// 		tab->tab_a[y] = tab->tab_a[y + 1];
// 		y++;
// 	}
// 	ft_putchar('\n');
// }


void	pb(t_tabs *tab)
{
	int i;
	i = 0;
	if (tab->tab_a[0] != NULL)
	{
		while(tab->tab_b[i])
		{
			i++;
		}
		while(i > 0)
		{
			tab->tab_b[i] = tab->tab_b[i - 1];
			i--;
		}
		tab->tab_b[0] = tab->tab_a[0];
		i = 0;
		while(tab->tab_a[i] != NULL)
		{
			tab->tab_a[i] = tab->tab_a[i + 1];
			i++;
		}
	}
	i = 0;
	while (tab->tab_b[i])
	{
		printf("%s       |      %s\n", tab->tab_a[i], tab->tab_b[i]);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:42:22 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/18 10:35:12 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_copy_stack(char **stack)
{
	int		i;
	char	**copy;

	i = 0;
	while (stack[i] != NULL)
		i++;
	copy = malloc(sizeof(char *) * i + 1);
	i = 0;
	while (stack[i] != NULL)
	{
		copy[i] = ft_strdup(stack[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	initialize(t_tabs *tab, char **av)
{
	int		i;
	char	*temp;

	i = 0;
	tab->count = 0;
	tab->max = 0;
	tab->max_idx = 0;
	tab->len_tab_a = 1;
	temp = ft_strdup("");
	while (av[tab->len_tab_a])
	{
		temp = ft_strjoin_gnl(temp, av[tab->len_tab_a]);
		temp = ft_strjoin_gnl(temp, " ");
		tab->len_tab_a++;
	}
	tab->tab_a = ft_split(temp, ' ');
	tab->tab_b = ft_calloc(tab->len_tab_a + 1, sizeof(char *));
	if (!tab->tab_b)
		ft_error("tab_b : calloc failed\n");
	free(temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:43:07 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/05 11:15:10 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_tabs *tab)
{
	if (ft_atoi(tab->tab_a[0]) > ft_atoi(tab->tab_a[1]))
		swap_a(tab);
}

void	sort_three(t_tabs *tab)
{
	int	str1;
	int	str2;
	int	str3;

	str1 = ft_atoi(tab->tab_a[0]);
	str2 = ft_atoi(tab->tab_a[1]);
	str3 = ft_atoi(tab->tab_a[2]);
	if (str1 > str2)
		swap_a(tab);
}

// void	sort_five(t_tabs *tab)
// {
	
// }
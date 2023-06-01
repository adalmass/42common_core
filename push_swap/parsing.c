/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:27:26 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/01 18:49:54 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_zeros(t_tabs *tab)
{
	int		y;
	int		temp;

	y = 0;
	while (tab->tab_a[y])
	{
		temp = ft_atoi(tab->tab_a[y]);
		tab->tab_a[y] = ft_itoa(temp);
		y++;
	}
}

void	check_operators(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '-')
		{
			if (!ft_isdigit(s[i + 1]))
				ft_error("No digit after '-' or '+'\n");
			if (i > 0 && s[i - 1] != ' ')
				ft_error("'+' or '-' after digit\n");
		}
		i++;
	}
}

void	handle_int_limit(t_tabs *tab)
{
	int	y;
	int	len_s;
	int	int_min;
	int	int_max;

	y = 0;
	len_s = 0;
	int_min = s_len("-2147483648");
	int_max = s_len("2147483647");
	while (tab->tab_a[y])
	{
		len_s = s_len(tab->tab_a[y]);
		ft_printf("len_s : %d\nlen_max :%d\nlen_min : %d\n", len_s, int_max, int_min);
		if ((tab->tab_a[y][0] == '-' && len_s > int_min)
			|| (tab->tab_a[y][0] != '-' && len_s > int_max))
			ft_error("Int limit reached\n");
		y++;
	}
}

void	rewrite_str(char *s)
{
	int	i;
	int	minus_found;

	i = 0;
	minus_found = 0;
	while (s[i])
	{
		if ((s[i] == '-' && s[i + 1] == '0') || s[i] == '+')
		{
			if ((s[i] == '-' && s[i + 1] == '0'))
				minus_found = 1;
			s[i] = ' ';
		}
		if (ft_isdigit(s[i - 1]) == 0 && s[i] == '0'
			&& ft_isdigit(s[i + 1]) == 1)
		{
			while (s[i] == '0' && s[i + 1] != ' ')
					s[i++] = ' ';
			if (minus_found)
				s[i - 1] = '-';
			minus_found = 0;
		}
		i++;
	}
}

void	parse_tab_a(t_tabs *tab)
{
	int		y;

	y = 1;
	while (tab->tab_a[y])
	{
		check_operators(tab->tab_a[y]);
		rewrite_str(tab->tab_a[y]);
		y++;
	}
	handle_zeros(tab);
	handle_int_limit(tab);
	handle_doubles(tab);
}

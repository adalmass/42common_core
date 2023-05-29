/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:27:26 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/29 16:29:04 by aldalmas         ###   ########.fr       */
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
		free(tab->tab_a[y]);
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

void	handle_int_limit(char *s)
{
	if ((s[0] == '-' && s_len(s) > s_len("-2147483648"))
		|| (s[0] != '-' && s_len(s) > s_len("2147483647")))
		ft_error("Int limit reached\n");
	// if (len_s == int_min || len_s == int_max)
	// {
	// 	if (ft_strncmp(s, int_max, s_len(s)) || ft_strncmp(s, int_min, s_len(s)))
	// }
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
		if (s[i] == '0' && s[i + 1] == '0')
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

void	create_tab_a(t_parse *parse, t_tabs *tab)
{
	int		y;
	char	*str;

	y = 1;
	str = ft_strdup("");
	while (parse->args[y])
	{
		str = ft_strjoin_gnl(str, parse->args[y]);
		str = ft_strjoin_gnl(str, " ");
		y++;
	}
	check_operators(str);
	rewrite_str(str);
	tab->tab_a = ft_split(str, ' ');
	y = 0;
	while (tab->tab_a[y])
	{
		handle_int_limit(tab->tab_a[y]);
		y++;
	}
	handle_zeros(tab);
	handle_doubles(tab);
	free(str);
}

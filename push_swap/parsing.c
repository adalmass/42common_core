/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:27:26 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/02 15:38:57 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*rewrite_str(char *s)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	temp = ft_strdup("");
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		temp[j] = s[i];
		j++;
		i++;
	}
	temp[j] = '\0';
	return (temp);
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
	int	len_s;

	len_s = s_len(s);
	if (len_s > 11)
		ft_error("INT LIMIT reached\n");
	if (s[0] != '-')
	{
		if (len_s == 10 && ft_strncmp(s, "2147483647", 10) > 0)
			ft_error("INT MAX reached\n");
	}
	else
	{
		if (len_s == 11 && ft_strncmp(s, "-2147483648", 11) > 0)
			ft_error("INT MIN reached\n");
	}
}

void	handle_zeros(char *s)
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
	int	y;

	y = 0;
	while (tab->tab_a[y])
	{
		check_operators(tab->tab_a[y]);
		handle_zeros(tab->tab_a[y]);
		tab->tab_a[y] = rewrite_str(tab->tab_a[y]);
		handle_int_limit(tab->tab_a[y]);
		y++;
	}
	handle_doubles(tab);
}

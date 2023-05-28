/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:44:13 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/28 15:29:35 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_tabs{
	char		**tab_a;
	char		**tab_b;
}				t_tabs;

typedef struct s_parse{
	int			found;
	int			len_to_find;
	int			y;
	int			x;
	int			minus_found;
	char		*no_z_str;
	char		**args;
	char		*chars_stocked;
	char		*char_to_find;
}				t_parse;

// --- initialize.c
void	initialize_struct(t_parse *parse);

// --- error_management.c
int		check_char_args(char *str);
void	is_valid_args(char **av);
void	ft_error(char *error_msg);

// --- parsing.c
void	handle_operators(char *s);
void	handle_zeros(t_tabs *tab);
void	create_tab_a(t_parse *parse, t_tabs *tabs);

// --- manage_double.c
int		if_double(char *s1, char *s2);
void	handle_doubles(t_tabs *tabs);
void	find_double(t_tabs *tabs, char *chars_stocked, int here);

// --- manage_zeros.c
int		find_len_nb(t_parse *parse);
void	manage_zeros(t_parse *parse);

// --- DEBUG_print_tab.c
void	DEBUG_print_tab_a(t_tabs *tabs);

#endif
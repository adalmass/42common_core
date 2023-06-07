/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:44:13 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/07 15:51:34 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_tabs{
	int			count;
	int			len_tab_a;
	int			max;
	int			max_idx;
	int			*tab_max_idx;
	int			*copy_a;
	char		**tab_a;
	char		**tab_b;
}				t_tabs;

typedef struct s_parse{
	char		*chars_stocked;
}				t_parse;

// --------------PARSING--------------
// --- DEBUG_print_tab.c
void	DEBUG_print_tab_a(t_tabs *tabs);
void	DEBUG_print_tab_b(t_tabs *tabs);
void	DEBUG_print_copy_a(t_tabs *tab);

// --- initialize.c
void	initialize(t_tabs *tab, int ac, char **av);
void	make_copy_a(t_tabs *tab);

// --- error_management.c
int		check_char_args(char *str);
void	is_valid_args(char **av);
void	ft_error(char *error_msg);

// --- manage_double.c
int		if_double(char *s1, char *s2);
void	handle_doubles(t_tabs *tabs);
void	find_double(t_tabs *tabs, char *chars_stocked, int here);

// --- parsing.c
char	*rewrite_str(char *s);
void	handle_int_limit(char *s);
void	handle_zeros(char *s);
void	check_operators(char *s);
void	parse_tab_a(t_tabs *tabs);

// --------------SWAP--------------
// --- sorting_swap.c
void	swap_a(t_tabs *tab);
void	swap_b(t_tabs *tab);
void	swap_ss(t_tabs *tab);

// --- pushing_swap.c
void	push_a(t_tabs *tab);
void	push_b(t_tabs *tab);

// --- rotating_swap.c
void	rotate_a(t_tabs *tab);
void	rotate_b(t_tabs *tab);
void	rotate_rr(t_tabs *tab);

// --- r_rotating_swap.c
void	r_rotate_a(t_tabs *tab);
void	r_rotate_b(t_tabs *tab);
void	r_rotate_rrr(t_tabs *tab);

// --- sort_small_stack.c

// --- simplify_nb.c
int		compare_str(t_tabs *tab, int idx);
void	swap_str(t_tabs *tab, int idx);
void	sort_two(t_tabs *tab);
//void	sort_three(t_tabs *tab);
//void	sort_five(t_tabs *tab);
void	simplify_nb(t_tabs *tab);
void	search_max(t_tabs *tab);

#endif
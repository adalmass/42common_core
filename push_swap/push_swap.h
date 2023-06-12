/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:44:13 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/12 15:11:41 by aldalmas         ###   ########.fr       */
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
	char		**tab_a;
	char		**tab_b;
	char		**copy_a;
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
void	initialize(t_tabs *tab, char **av);

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
void	sa(t_tabs *tab);
void	sb(t_tabs *tab);
void	ss(t_tabs *tab);

// --- pushing_swap.c
void	pa(t_tabs *tab);
void	pb(t_tabs *tab);

// --- rotating_swap.c
void	ra(t_tabs *tab);
void	rb(t_tabs *tab);
void	rr(t_tabs *tab);

// --- r_rotating_swap.c
void	rra(t_tabs *tab);
void	rrb(t_tabs *tab);
void	rrr(t_tabs *tab);

// --- sort_small_stack.c

// --- simplify_stack.c
void	sort_copy_a(t_tabs *tab);
void	simplify_tab_a(t_tabs *tab);
void	init_copy_a(t_tabs *tab);
void	handle_tab_a(t_tabs *tab);

// --- sort_big_stack.c
void	push_to_b(t_tabs *tab, int filter);


#endif
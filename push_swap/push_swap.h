/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:44:13 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/24 21:45:43 by aldalmas         ###   ########.fr       */
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
	char		*chars_stocked;
	char		*char_to_find;
}				t_parse;

// --- initialize.c
void	initialize_struct(t_parse *parse);

// --- error_management.c
void	is_valid_args(char **av);
void	ft_error(void);

// --- parsing.c
int		check_char_args(char c, char d);
int		search_double(char *s1, char *s2);
void	create_tab_a(char **av, t_parse *parse, t_tabs *tabs);
void	check_if_double(t_parse *parse, t_tabs *tabs);

// --- DEBUG_print_tab.c
void	DEBUG_print_tab_a(t_tabs *tabs);

#endif
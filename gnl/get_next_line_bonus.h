/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <aldalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:34:42 by aldalmas          #+#    #+#             */
/*   Updated: 2023/02/04 14:26:33 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdlib.h>
# include <unistd.h>

int		s_len(char *s);
int		search_backslash_n(char	*stock);
char	*get_next_line(int fd);
char	*if_find_newline(int fd, int ret, char **stock, char *temp);
char	*ft_strjoin(char *stock, char *temp);
char	*line_to_return(char *stock, int idx_backslash_n);
char	*cut_and_update_stock(char *stock, int idx_backslash_n);
void	stock_verification(char **stock);

#endif
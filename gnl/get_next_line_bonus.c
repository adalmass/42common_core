/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <aldalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:02:36 by aldalmas          #+#    #+#             */
/*   Updated: 2023/02/03 08:31:05 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*if_find_newline(int fd, int ret, char **stock, char *temp)
{
	int		idx_newline;
	char	*returned_line;

	while (ret > 0 || search_backslash_n(*stock) >= 0)
	{
		temp[ret] = '\0';
		*stock = ft_strjoin(*stock, temp);
		if (!(*stock))
			return (NULL);
		idx_newline = search_backslash_n(*stock);
		if (idx_newline >= 0)
		{
			returned_line = line_to_return(*stock, idx_newline);
			if (!(*returned_line))
				return (free(*stock), *stock = NULL);
			*stock = cut_and_update_stock(*stock, idx_newline);
			return (returned_line);
		}
		ret = read(fd, temp, BUFFER_SIZE);
	}
	return (NULL);
}

void	stock_verification(char **stock)
{
	if (*stock == NULL)
	{
		*stock = malloc(sizeof(char) * 1);
		if (!(*stock))
			return ;
		*stock[0] = '\0';
	}	
}

char	*get_next_line(int fd)
{
	int			ret;
	char		temp[BUFFER_SIZE + 1];
	static char	*stock[1024];
	char		*returned_line;

	ret = read(fd, temp, BUFFER_SIZE);
	if (ret == -1)
	{
		if (stock[fd])
			free(stock[fd]);
		return (stock[fd] = NULL);
	}
	stock_verification(&stock[fd]);
	returned_line = if_find_newline(fd, ret, &stock[fd], temp);
	if (returned_line)
		return (returned_line);
	if (stock[fd][0] == '\0')
		return (free(stock[fd]), stock[fd] = NULL);
	returned_line = line_to_return(stock[fd], s_len(stock[fd]));
	free(stock[fd]);
	stock[fd] = NULL;
	return (returned_line);
}

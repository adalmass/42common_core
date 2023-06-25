/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 08:38:07 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/25 11:32:17 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin_free(char *stock, char *temp)
{
	char	*memory;
	int		i;
	int		j;

	memory = malloc(sizeof(char) * (ft_strlen(stock) + ft_strlen(temp) + 1));
	if (!memory)
	{
		free(stock);
		return (NULL);
	}
	i = -1;
	while (stock[++i])
		memory[i] = stock[i];
	memory[i] = '\0';
	j = i;
	i = -1;
	while (temp[++i])
		memory[j + i] = temp[i];
	memory[j + i] = '\0';
	free(stock);
	return (memory);
}
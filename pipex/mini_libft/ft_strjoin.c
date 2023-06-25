/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:35:22 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/25 12:45:36 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*concat_and_copy(char *d, char *s, char *memory)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (d[i])
	{
		memory[i] = d[i];
		i++;
	}
	while (s[j])
	{
		memory[i + j] = s[j];
		j++;
	}
	memory[i + j] = '\0';
	return (memory);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*memory;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	memory = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!memory)
		return (NULL);
	return (concat_and_copy((char *)s1, (char *)s2, memory));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:54:24 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/13 14:56:11 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	memory = malloc((count * size) * sizeof(char));
	if (!memory)
		return (NULL);
	ft_bzero(memory, count * size);
	return (memory);
}

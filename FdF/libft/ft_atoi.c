/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <aldalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:55:23 by aldalmas          #+#    #+#             */
/*   Updated: 2023/02/10 15:55:35 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_result(const char *str, size_t i)
{
	size_t	result;

	result = 0;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	result;
	size_t	minus_count;

	i = 0;
	result = 0;
	minus_count = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\v') || (str[i] == '\f'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus_count++;
		i++;
	}
	if (ft_isdigit(str[i]) == 0)
		return (0);
	result = get_result(str, i);
	if (minus_count == 1)
		return (result * -1);
	return (result);
}

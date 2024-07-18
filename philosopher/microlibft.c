/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microlibft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:21:36 by aldalmas          #+#    #+#             */
/*   Updated: 2024/07/18 17:07:36 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:09:04 by aldalmas          #+#    #+#             */
/*   Updated: 2024/07/18 16:58:18 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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


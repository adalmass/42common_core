/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microlibft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:21:36 by aldalmas          #+#    #+#             */
/*   Updated: 2024/07/27 19:53:08 by aldalmas         ###   ########.fr       */
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

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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
	int	i;
	int	result;
	int	minus_count;

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

int	handle_int_limit(char *s)
{
	int	len_s;

	len_s = ft_strlen(s);
	if (len_s > 11)
	{
		error_found("INT LIMIT reached");
		return (0);
	}
	if (s[0] != '-')
	{
		if (len_s == 10 && ft_strncmp(s, "2147483647", 10) > 0)
		{
			error_found("INT MAX reached");
			return (0);
		}
	}
	else
	{
		if (len_s == 11 && ft_strncmp(s, "-2147483648", 11) > 0)
		{
			error_found("INT MIN reached\n");
			return (0);
		}
	}
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (!n)
		return (0);
	while ((i < (n - 1)) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

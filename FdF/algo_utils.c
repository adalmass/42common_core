/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <aldalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:32:54 by aldalmas          #+#    #+#             */
/*   Updated: 2023/02/09 09:05:49 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_point(int x, int x_end, int y, int y_end)
{
	float	check_x;
	float	check_y;
	float	result;

	check_x = abs(x_end - x);
	check_y = abs(y_end - y);
	result = abs(check_x / check_y);
}
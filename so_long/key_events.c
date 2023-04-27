/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:24:31 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/27 14:24:41 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	shutdown(void)
{
	ft_printf("[Sortie du programme]\n");
	//system("leaks so_long");
	exit(0);
	return (0);
}

int	check_event(int key)
{
	ft_printf("code de la touche : %d ->", key);
	if (key == 1)
		ft_printf("clic gauche\n");
	else if (key == 2)
		ft_printf("clic droit\n");
	else if (key == 3)
		ft_printf("clic molette\n");
	else if (key == 4)
		ft_printf("molette vers le bas\n");
	else if (key == 5)
		ft_printf("molette vers le haut\n");
	else if (key == 17 || key == 53)
		shutdown();
	else if (key == 124)
		ft_printf("fleche droite\n");
	else if (key == 123)
		ft_printf("fleche gauche\n");
	else if (key == 126)
		ft_printf("fleche haut\n");
	else if (key == 125)
		ft_printf("fleche bas\n");
	return (0);
}

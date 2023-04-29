
#include "so_long.h"

int	shutdown(void)
{
	ft_printf("[Sortie du programme]\n");
	//system("leaks so_long");
	exit(0);
	return (0);
}

int	key_press(int key, t_game *game)
{
	if (key == 53)
		shutdown();
	if (key == 13)
		move_up(game);
	else if (key == 1)
		move_down(game);
	else if (key == 2)
		move_right(game);
	else if (key == 0)
		move_left(game);
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == 13 || key == 1 || key == 2 || key == 3)
		ft_printf("relache\n");
	return (0);
}
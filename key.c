#include "cube.h"

int	key_press(int key, t_game *cube)
{
	if (key == 0 || key == 'a')
		cube->player->mov_dirx = -1;
	else if (key == 1 || key == 's')
		cube->player->mov_diry = -1;
	else if (key == 2 || key == 'd')
		cube->player->mov_dirx = 1;
	else if (key == 13 || key == 'w')
		cube->player->mov_diry = 1;
	else if (key == 65361)
		cube->player->cam_dir = -1;
	else if (key == 65363)
		cube->player->cam_dir = 1;
	else if (key == 65307)
		close_window(cube);
	return (0);
	// if (key == 0 || key == 'a')
	// 	cube->player->mov_dirX = -1;
	// else if (key == 1 || key == 's')
	// 	cube->player->mov_dirY = -1;
	// else if (key == 2 || key == 'd')
	// 	cube->player->mov_dirX = 1;
	// else if (key == 13 || key == 'w')
	// 	cube->player->mov_dirY = 1;
	// else if (key == 65361)
	// 	cube->player->cam_dir = -1;
	// else if (key == 65363)
	// 	cube->player->cam_dir = 1;
	// else if (key == 65307)
	// 	close_window(cube);
	// return (0);
}
int	key_release(int key, t_game* cube)
{
	if (key == 'w' || key == 's')
		cube->player->mov_diry = 0;
	else if (key == 'a' || key == 'd')
		cube->player->mov_dirx = 0;
	else if (key == 65363 || key == 65361)
		cube->player->cam_dir = 0;
	return (0);
	// if (key == 'w' || key == 's')
	// 	cube->player->mov_dirY = 0;
	// else if (key == 'a' || key == 'd')
	// 	cube->player->mov_dirX = 0;
	// else if (key == 65363 || key == 65361)
	// 	cube->player->cam_dir = 0;
	// return (0);
}

#include "cube.h"

int	key_press(int key, t_game *cube)
{
	if (key == 0 || key == 'a')
		cube->player->mov_dirX = -1;
	else if (key == 1 || key == 's')
		cube->player->mov_dirY = -1;
	else if (key == 2 || key == 'd')
		cube->player->mov_dirX = 1;
	else if (key == 13 || key == 'w')
		cube->player->mov_dirY = 1;
	else if (key == 65361)
		cube->player->cam_dir = -1;
	else if (key == 65363)
		cube->player->cam_dir = 1;
	else if (key == 65307)
		close_window(cube);
	return (0);
}
int	key_release(int key, t_game* cube)
{
	if (key == 'w' || key == 's')
		cube->player->mov_dirY = 0;
	else if (key == 'a' || key == 'd')
		cube->player->mov_dirX = 0;
	else if (key == 65363 || key == 65361)
		cube->player->cam_dir = 0;
	return (0);
}
int handle_mouse(int x, int y, void *cube)
{
	double normalized_x;
	double max_rotation_angle;
	double rotation_angle;
	double new_rotation_angle;

	(void)y;
	mlx_mouse_hide(((t_game *)cube)->mlx, ((t_game *)cube)->mlx_win);
	normalized_x = (2.0f * x) / SCREENWIDTH - 1.0f;
	max_rotation_angle = 180.0f;
	rotation_angle = max_rotation_angle * normalized_x;
	new_rotation_angle = rotation_angle;
	if (((t_game *)cube)->player->rot_angle != 360)
		new_rotation_angle = ((t_game *)cube)->player->rot_angle - rotation_angle;
	((t_game *)cube)->player->rot_angle = rotation_angle;
	rotate_cam(new_rotation_angle, (t_game *)cube);
	return (0);
}

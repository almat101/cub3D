#include "cube.h"

void rotate_to_left(t_game *cube, double rot_speed)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = cube->player->dirX;
	cube->player->dirX = cube->player->dirX * cos(-rot_speed) - cube->player->dirY * sin(-rot_speed);
	cube->player->dirY = old_dir_x * sin(-rot_speed) + cube->player->dirY * cos(-rot_speed);
	old_plane_x = cube->player->planeX;
	cube->player->planeX = cube->player->planeX * cos(-rot_speed) - cube->player->planeY * sin(-rot_speed);
	cube->player->planeY = old_plane_x * sin(-rot_speed) + cube->player->planeY * cos(-rot_speed);
}

void rotate_to_right(t_game *cube, double rot_speed)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = cube->player->dirX;
	cube->player->dirX = cube->player->dirX * cos(rot_speed) - cube->player->dirY * sin(rot_speed);
	cube->player->dirY = old_dir_x * sin(rot_speed) + cube->player->dirY * cos(rot_speed);
	old_plane_x = cube->player->planeX;
	cube->player->planeX = cube->player->planeX * cos(rot_speed) - cube->player->planeY * sin(rot_speed);
	cube->player->planeY = old_plane_x * sin(rot_speed) + cube->player->planeY * cos(rot_speed);
}

void update_rotation(t_game *cube)
{
	double rot_speed;

	rot_speed = cube->frameTime * 3.0;
	if (cube->player->cam_dir == -1)
		rotate_to_right(cube, rot_speed);
	if (cube->player->cam_dir == 1)
		rotate_to_left(cube, rot_speed);
}

void	rotate_cam(float angle, t_game *cube)
{
	double new_dir_x;
	double new_dir_y;
	double new_plane_x;
	double new_plane_y;

	angle = angle * M_PI / 180.0f;
	new_dir_x = cube->player->dirX * cos(angle) - cube->player->dirY * sin(angle);
	new_dir_y = cube->player->dirX * sin(angle) + cube->player->dirY * cos(angle);
	new_plane_x = cube->player->planeX * cos(angle) - cube->player->planeY * sin(angle);
	new_plane_y = cube->player->planeX * sin(angle) + cube->player->planeY * cos(angle);
	cube->player->dirX = new_dir_x;
	cube->player->dirY = new_dir_y;
	cube->player->planeX = new_plane_x;
	cube->player->planeY = new_plane_y;
}

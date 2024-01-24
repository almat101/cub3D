#include "cube.h"

void init_all(t_game *cube)
{
	cube->player = ft_calloc(1, sizeof(t_player));
	cube->colors = ft_calloc(1, sizeof(t_colors));
	cube->img = ft_calloc(1, sizeof(t_img));
	cube->card = ft_calloc(1, sizeof(t_cards));
	cube->map = NULL;
	cube->info = NULL;
	cube->player->posX = 0;
	cube->player->posY = 0;
	cube->player->dirX = 0;
	cube->player->dirY = 0;
	cube->player->planeX = 0;
	cube->player->planeY = 0;
	cube->player->mov_dirX = 0;
	cube->player->mov_dirY = 0;
	cube->player->cam_dir = 0;
	cube->time = 0;
	cube->oldTime = 0;
	cube->map_width = 0;
	cube->map_height = 0;
	init_all2(cube);
}

void	init_all2(t_game *cube)
{
	cube->card->no = NULL;
	cube->card->so = NULL;
	cube->card->ea = NULL;
	cube->card->we = NULL;
	cube->card->n = 0;
	cube->card->s = 0;
	cube->card->e = 0;
	cube->card->w = 0;
	cube->colors->f_floor = 0;
	cube->colors->c_ceil = 0;
	cube->player->rot_angle = 360;
	cube->colors->floor_color = NULL;
	cube->colors->ceil_color = NULL;
	cube->colors->f_hex_color = NULL;
	cube->colors->c_hex_color = NULL;
}



void init_data(t_data *data, t_game *cube, int x)
{
	data->camera_x = 2 * x / (double)SCREENWIDTH - 1;
	data->ray_dir_x = cube->player->dirX + cube->player->planeX * data->camera_x;
	data->ray_dir_y = cube->player->dirY + cube->player->planeY * data->camera_x;
	data->map_x = (int)cube->player->posX;
	data->map_y = (int)cube->player->posY;
	if (data->ray_dir_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1.0f / data->ray_dir_x);
	if (data->ray_dir_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1.0f / data->ray_dir_y);
	data->hit = 0;
	init_step(data, cube);
}

void init_step(t_data *data, t_game *cube)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (cube->player->posX - (int)data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = ((int)data->map_x + 1.0 - cube->player->posX) * data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (cube->player->posY - (int)data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = ((int)data->map_y + 1.0 - cube->player->posY) * data->delta_dist_y;
	}
}

void	init_direction(t_game *cube)
{
	if (cube->player->direction == 'W')
	{
		cube->player->dirX = 1;
		cube->player->planeY = 0.66;
	}
	if (cube->player->direction == 'E')
	{
		cube->player->dirX = -1;
		cube->player->planeY = -0.66;
	}
	if (cube->player->direction == 'N')
	{
		cube->player->dirY = 1;
		cube->player->planeX = -0.66;
	}
	if (cube->player->direction == 'S')
	{
		cube->player->dirY = -1;
		cube->player->planeX = 0.66;
	}
}

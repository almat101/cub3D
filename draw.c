#include "cube.h"

void	draw_textwall(t_data *data, t_game *cube, int x)
{
	int y;

	data->step = 1.0 * data->tex_height / data->line_height;
	data->tex_pos = (data->draw_start - SCREENHEIGHT / 2 + data->line_height / 2) * data->step;
	y = data->draw_start;
	while (y < data->draw_end)
	{
		data->tex_y = (int)data->tex_pos % data->tex_height;
		data->tex_pos += data->step;
		set_color(data, cube, 4 * (int)(data->tex_height * data->tex_y + data->tex_x));
		my_mlx_pixel_put(cube->img, x, y++, data->color);
	}
}
void	set_color(t_data *data, t_game *cube, int shift)
{

	if (data->side == 1)
	{
		if (data->ray_dir_y > 0)
			data->color = *(unsigned int *)(cube->card->north_wall.addr + shift);
		else
			data->color = *(unsigned int *)(cube->card->south_wall.addr + shift);
	}
	else
	{
		if (data->ray_dir_x > 0)
			data->color = *(unsigned int *)(cube->card->east_wall.addr + shift);
		else
			data->color = *(unsigned int *)(cube->card->west_wall.addr + shift);
	}
}

void	set_texwh(t_data *data, t_game *cube)
{
	if (data->side == 1)
	{
		if (data->ray_dir_y > 0)
		{
			data->tex_width = cube->card->north_wall.width;
			data->tex_height = cube->card->north_wall.height;
			return;
		}
		data->tex_width = cube->card->south_wall.width;
		data->tex_height = cube->card->south_wall.height;
	}
	else
	{
		if (data->ray_dir_x > 0)
		{
			data->tex_width = cube->card->east_wall.width;
			data->tex_height = cube->card->east_wall.height;
			return;
		}
		data->tex_width = cube->card->west_wall.width;
		data->tex_height = cube->card->west_wall.height;
	}
}

int	set_wall_x(t_data *data, t_game *cube)
{
	if (data->side == 0)
		data->wall_x = cube->player->posY + data->perp_wall_dist * data->ray_dir_y;
	else
		data->wall_x = cube->player->posX + data->perp_wall_dist * data->ray_dir_x;
	data->wall_x -= (int)(data->wall_x);
	return (0);
}

int	wall_pos(t_data *data, t_game *cube)
{
	if (data->side == 0)
		data->perp_wall_dist = (data->side_dist_x - data->delta_dist_x);
	else
		data->perp_wall_dist = (data->side_dist_y - data->delta_dist_y);
	data->line_height = (int)(SCREENHEIGHT / data->perp_wall_dist);
	data->draw_start = -data->line_height / 2 + SCREENHEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + SCREENHEIGHT / 2;
	if (data->draw_end >= SCREENHEIGHT)
		data->draw_end = SCREENHEIGHT - 1;
	if (set_wall_x(data, cube))
		return (1);
	set_texwh(data, cube);
	data->tex_x = (int)(data->wall_x * (double)data->tex_width);
	if (data->hit != 2 && data->side == 0 && data->ray_dir_x > 0)
		data->tex_x = data->tex_width - data->tex_x - 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		data->tex_x = data->tex_width - data->tex_x - 1;
	return (0);
}

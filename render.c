#include "cube.h"

void	render_map(t_game *cube)
{
	t_data data;
	int x;

	x = 0;
	while (x < SCREENWIDTH)
	{
		init_data(&data, cube, x);
		dda_algorithm(&data, cube);
		draw_vertical_line(&data, cube, x);
		x++;
	}
}

void	dda_algorithm(t_data *data, t_game *cube)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (cube->map[(int)data->map_y][(int)data->map_x] == '1')
			data->hit = 1;
	}
}

void	draw_vertical_line(t_data *data, t_game *cube, int x)
{
	int i;

	i = 0;
	if (wallPosRayPosOnWall(data, cube))
		return;
	while (i < data->draw_start)
		my_mlx_pixel_put(cube->img, x, i++, cube->colors->c_ceil);
	drawTextWall(data, cube, x);
	i = data->draw_end;
	while (i < SCREENHEIGHT)
		my_mlx_pixel_put(cube->img, x, i++, cube->colors->f_floor);
}

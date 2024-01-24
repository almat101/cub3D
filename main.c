#include "cube.h"

void dda_algorithm(t_data *data, t_game *cube)
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

void set_color(t_data *data, t_game *cube, int shift)
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

void setTexWH(t_data *data, t_game *cube)
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

int set_wall_x(t_data *data, t_game *cube)
{
	if (data->side == 0)
		data->wall_x = cube->player->posY + data->perp_wall_dist * data->ray_dir_y;
	else
		data->wall_x = cube->player->posX + data->perp_wall_dist * data->ray_dir_x;
	data->wall_x -= (int)(data->wall_x);
	return (0);
}

int wallPosRayPosOnWall(t_data *data, t_game *cube)
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
	setTexWH(data, cube);
	data->tex_x = (int)(data->wall_x * (double)data->tex_width);
	if (data->hit != 2 && data->side == 0 && data->ray_dir_x > 0)
		data->tex_x = data->tex_width - data->tex_x - 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		data->tex_x = data->tex_width - data->tex_x - 1;
	return (0);
}

void drawTextWall(t_data *data, t_game *cube, int x)
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

void draw_vertical_line(t_data *data, t_game *cube, int x)
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

void render_map(t_game *cube)
{
	t_data data;
	int x;

	x = 0;
	// load_all_texture(cube);
	while (x < SCREENWIDTH)
	{
		init_data(&data, cube, x);
		dda_algorithm(&data, cube);
		draw_vertical_line(&data, cube, x);
		x++;
	}
}

void mlx_hooks(t_game *cube)
{
	mlx_hook(cube->mlx_win, 17, 0, close_window, cube);
	mlx_hook(cube->mlx_win, 6, 1L << 6, handle_mouse, (void *)cube);
	mlx_hook(cube->mlx_win, 2, 1L << 0, key_press, (void *)cube);
	mlx_hook(cube->mlx_win, 3, 1L << 1, key_release, (void *)cube);
}

int game_loop(t_game *cube)
{
	render_map(cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img->img, 0, 0);
	count_fps(cube);
	update_movement(cube);
	update_rotation(cube);
	return (0);
}

void initialize_game(t_game *cube, char **argv)
{
	is_cube(argv[1]);
	init_all(cube);
	parse_info(argv, cube);
	extract_texture(cube);
	extract_colors(cube);
	check_rgb(cube);
	rgb_to_hex(cube);
	check_real_map(cube);
	extract_real_map(cube);
	replace_tabs_in_real_map(&cube->map, cube->map_height);
	check_player(cube);
	check_symbols(cube);
	check_flmap(cube);
	check_map(cube);
	save_player(cube);
	if (!player_exist(cube))
		free_err(cube, "Error\nPlayer doesn't exist\n");
}

void start_game(t_game *cube)
{
	cube->mlx = mlx_init();
	load_imgs(cube);
	load_all_texture(cube);
	mlx_hooks(cube);
	init_direction(cube);
	mlx_loop_hook(cube->mlx, game_loop, cube);
	mlx_loop(cube->mlx);
}

int main(int argc, char **argv)
{
	t_game *cube;

	(void)argv;
	if (argc == 2)
	{
		cube = ft_calloc(1, sizeof(t_game));
		initialize_game(cube, argv);
		start_game(cube);
	}
	else
		write(2, "Error\nInvalid number of arguments\n", 34);
	exit(0);
}

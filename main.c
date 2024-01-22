#include "cube.h"

void	init_data(t_data *data, t_game *cube, int x)
{
	data->camera_x = 2 * x / (double)SCREENWIDTH - 1;
	data->ray_dir_x = cube->player->dirx + cube->player->planex
		* data->camera_x;
	data->ray_dir_y = cube->player->diry + cube->player->planey
		* data->camera_x;
	data->map_x = (int)cube->player->posx;
	data->map_y = (int)cube->player->posy;
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

void 	init_step(t_data *data, t_game *cube)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (cube->player->posx - (int)data->map_x)
			* data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = ((int)data->map_x + 1.0 - cube->player->posx)
			* data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (cube->player->posy - (int)data->map_y)
			* data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = ((int)data->map_y + 1.0 - cube->player->posy)
			* data->delta_dist_y;
	}
}

void	dda_algorithm(t_data *data,t_game *cube)
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
		if (cube->real_map[(int)data->map_y][(int)data->map_x] == '1')
			data->hit = 1;
	}
}

void	set_color(t_data *data, t_game *cube, int shift)
{

	if (data->side == 1)
	{
		if (data->ray_dir_y > 0)
			data->color = *(unsigned int *)(cube->card->north_wall.addr
					+ shift);
		else
			data->color = *(unsigned int *)(cube->card->south_wall.addr
					+ shift);
	}
	else
	{
		if (data->ray_dir_x > 0)
			data->color = *(unsigned int *)(cube->card->east_wall.addr
					+ shift);
		else
			data->color = *(unsigned int *)(cube->card->west_wall.addr
					+ shift);
	}
}

void	setTexWH(t_data *data, t_game *cube)
{
	if (data->side == 1)
	{
		if (data->ray_dir_y > 0)
		{
			data->tex_width = cube->card->north_wall.width;
			data->tex_height = cube->card->north_wall.height;
			return ;
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
			return ;
		}
		data->tex_width = cube->card->west_wall.width;
		data->tex_height = cube->card->west_wall.height;
	}
}

int	set_wall_x(t_data *data, t_game *cube)
{
	if (data->side == 0)
		data->wall_x = cube->player->posy + data->perp_wall_dist
			* data->ray_dir_y;
	else
		data->wall_x = cube->player->posx + data->perp_wall_dist
			* data->ray_dir_x;
	data->wall_x -= (int)(data->wall_x);
	// if (data->hit == 2)
	// {
	// 	if (data->wall_x
	// 		> cube->map_door_timer[(int)data->map_y][(int)data->map_x])
	// 		return (1);
	// 	set_wall_x_door(data, cube);
	// 	if (data->wall_x < 0)
	// 		data->wall_x = 0;
	// }
	return (0);
}

int	wallPosRayPosOnWall(t_data *data, t_game *cube)
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


void	drawTextWall(t_data *data, t_game *cube, int x)
{
	int	y;

	data->step = 1.0 * data->tex_height / data->line_height;
	data->tex_pos = (data->draw_start - SCREENHEIGHT / 2
			+ data->line_height / 2) * data->step;
	y = data->draw_start;
	while (y < data->draw_end)
	{
		data->tex_y = (int)data->tex_pos % data->tex_height;
		data->tex_pos += data->step;
		set_color(data, cube, 4
			* (int)(data->tex_height * data->tex_y + data->tex_x));
		my_mlx_pixel_put(cube->img, x, y++, data->color);
	}
}

void	draw_vertical_line(t_data *data, t_game *cube, int x)
{
	int	i;

	i = 0;
	if (wallPosRayPosOnWall(data, cube))
		return ;
	while (i < data->draw_start)
		my_mlx_pixel_put(cube->img, x, i++, cube->colors->c_ceil);
	drawTextWall(data, cube, x);
	i = data->draw_end;
	while (i < SCREENHEIGHT)
		my_mlx_pixel_put(cube->img, x, i++, cube->colors->f_floor);
}

void	render_map(t_game *cube)
{
	t_data	data;
	int		x;

	x = 0;
	//load_all_texture(cube);
	while (x < SCREENWIDTH)
	{
		init_data(&data, cube, x);
		dda_algorithm(&data, cube);
		draw_vertical_line(&data, cube, x);
		x++;
	}
}


void	move_forward(t_game *cube, double moveSpeed)
{

	if (cube->real_map[(int)cube->player->posy]
		[(int)(cube->player->posx + cube->player->dirx * moveSpeed)] == '0')
		cube->player->posx += cube->player->dirx * moveSpeed;
	if (cube->real_map[(int)(cube->player->posy + cube->player->diry
			* moveSpeed)]
		[(int)(cube->player->posx)] == '0')
		cube->player->posy += cube->player->diry
			* moveSpeed;
	// // move forward if no wall in front of you
	// if (cube->real_map[(int)cube->player->posY]
	// 	[(int)(cube->player->posX + cube->player->dirX * moveSpeed)] == '0')
	// 	cube->player->posX += cube->player->dirX * moveSpeed;
	// if (cube->real_map[(int)(cube->player->posY + cube->player->dirY
	// 		* moveSpeed)]
	// 	[(int)(cube->player->posX)] == '0')
	// 	cube->player->posY += cube->player->dirY
	// 		* moveSpeed;
}

void	move_backward(t_game *cube, double moveSpeed)
{
	if (cube->real_map[(int)cube->player->posy]
		[(int)(cube->player->posx - cube->player->dirx * moveSpeed)] == '0')
		cube->player->posx -= cube->player->dirx * moveSpeed;
	if (cube->real_map[(int)(cube->player->posy - cube->player->diry
			* moveSpeed)]
		[(int)cube->player->posx] == '0')
		cube->player->posy -= cube->player->diry * moveSpeed;
	// move backwards if no wall behind you
	// if (cube->real_map[(int)cube->player->posY]
	// 	[(int)(cube->player->posX - cube->player->dirX * moveSpeed)] == '0')
	// 	cube->player->posX -= cube->player->dirX * moveSpeed;
	// if (cube->real_map[(int)(cube->player->posY - cube->player->dirY
	// 		* moveSpeed)]
	// 	[(int)cube->player->posX] == '0')
	// 	cube->player->posY -= cube->player->dirY * moveSpeed;
}

void	move_left(t_game *cube, double moveSpeed)
{
	if (cube->real_map[(int)cube->player->posy]
		[(int)(cube->player->posx - cube->player->diry * moveSpeed)] == '0')
		cube->player->posx -= cube->player->diry * moveSpeed;
	if (cube->real_map[(int)(cube->player->posy
			+ cube->player->dirx * moveSpeed)]
		[(int)(cube->player->posx)] == '0')
		cube->player->posy += (cube->player->dirx) * moveSpeed;
	// move to left
	// if (cube->real_map[(int)cube->player->posY]
	// 	[(int)(cube->player->posX - cube->player->dirY * moveSpeed)] == '0')
	// 	cube->player->posX -= cube->player->dirY * moveSpeed;
	// if (cube->real_map[(int)(cube->player->posY
	// 		+ cube->player->dirX * moveSpeed)]
	// 	[(int)(cube->player->posX)] == '0')
	// 	cube->player->posY += (cube->player->dirX) * moveSpeed;
}

void	move_right(t_game *cube, double moveSpeed)
{
	if (cube->real_map[(int)cube->player->posy]
		[(int)(cube->player->posx + cube->player->diry * moveSpeed)] == '0')
		cube->player->posx += cube->player->diry * moveSpeed;
	if (cube->real_map[(int)(cube->player->posy
			- cube->player->dirx * moveSpeed)][(int)cube->player->posx] == '0')
		cube->player->posy -= (cube->player->dirx) * moveSpeed;
	// move to right
	// if (cube->real_map[(int)cube->player->posY]
	// 	[(int)(cube->player->posX + cube->player->dirY * moveSpeed)] == '0')
	// 	cube->player->posX += cube->player->dirY * moveSpeed;
	// if (cube->real_map[(int)(cube->player->posY
	// 		- cube->player->dirX * moveSpeed)][(int)cube->player->posX] == '0')
	// 	cube->player->posY -= (cube->player->dirX) * moveSpeed;
}

void	update_movement(t_game *cube)
{
	double	move_speed;

	move_speed = cube->frameTime * 5.0;
	if (cube->player->mov_diry == 1)
		move_forward(cube, move_speed);
	if (cube->player->mov_diry == -1)
		move_backward(cube, move_speed);
	if (cube->player->mov_dirx == -1)
		move_left(cube, move_speed);
	if (cube->player->mov_dirx == 1)
		move_right(cube, move_speed);

	// speed modifiers
	// double	moveSpeed;

	// moveSpeed = cube->frameTime * 5.0;
	// if (cube->player->mov_dirY == 1)
	// 	move_forward(cube, moveSpeed);
	// if (cube->player->mov_dirY == -1)
	// 	move_backward(cube, moveSpeed);
	// if (cube->player->mov_dirX == -1)
	// 	move_left(cube, moveSpeed);
	// if (cube->player->mov_dirX == 1)
	// 	move_rigth(cube, moveSpeed);
}

void	rotate_to_left(t_game *cube, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->player->dirx;
	cube->player->dirx = cube->player->dirx * cos(-rot_speed)
		- cube->player->diry * sin(-rot_speed);
	cube->player->diry = old_dir_x * sin(-rot_speed)
		+ cube->player->diry * cos(-rot_speed);
	old_plane_x = cube->player->planex;
	cube->player->planex = cube->player->planex * cos(-rot_speed)
		- cube->player->planey * sin(-rot_speed);
	cube->player->planey = old_plane_x * sin(-rot_speed)
		+ cube->player->planey * cos(-rot_speed);
	// double	olddirX;
	// double	oldplaneX;
	// // rotate to the right
	// if (cube->player->cam_dir == 1)
	// {
	// 	// both camera direction and camera plane must be rotated
	// 	olddirX = cube->player->dirX;
	// 	cube->player->dirX = cube->player->dirX * cos(-rotSpeed) - cube->player->dirY * sin(-rotSpeed);
	// 	cube->player->dirY = olddirX * sin(-rotSpeed) + cube->player->dirY * cos(-rotSpeed);
	// 	oldplaneX = cube->player->planeX;
	// 	cube->player->planeX = cube->player->planeX * cos(-rotSpeed) - cube->player->planeY * sin(-rotSpeed);
	// 	cube->player->planeY = oldplaneX * sin(-rotSpeed) + cube->player->planeY * cos(-rotSpeed);
	// }
}

void	rotate_to_right(t_game *cube, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->player->dirx;
	cube->player->dirx = cube->player->dirx * cos(rot_speed)
		- cube->player->diry * sin(rot_speed);
	cube->player->diry = old_dir_x * sin(rot_speed)
		+ cube->player->diry * cos(rot_speed);
	old_plane_x = cube->player->planex;
	cube->player->planex = cube->player->planex * cos(rot_speed)
		- cube->player->planey * sin(rot_speed);
	cube->player->planey = old_plane_x * sin(rot_speed)
		+ cube->player->planey * cos(rot_speed);
	// double	olddirX;
	// double	oldplaneX;

	// // rotate to the left
	// if (cube->player->cam_dir == -1)
	// {
	// 	// both camera direction and camera plane must be rotated
	// 	olddirX = cube->player->dirX;
	// 	cube->player->dirX = cube->player->dirX * cos(rotSpeed) - cube->player->dirY * sin(rotSpeed);
	// 	cube->player->dirY = olddirX * sin(rotSpeed) + cube->player->dirY * cos(rotSpeed);
	// 	oldplaneX = cube->player->planeX;
	// 	cube->player->planeX = cube->player->planeX * cos(rotSpeed) - cube->player->planeY * sin(rotSpeed);
	// 	cube->player->planeY = oldplaneX * sin(rotSpeed) + cube->player->planeY * cos(rotSpeed);
	// }
}

void	update_rotation(t_game *cube)
{
	double	rot_speed;

	rot_speed = cube->frameTime * 3.0;
	if (cube->player->cam_dir == 1)
		rotate_to_right(cube, rot_speed);
	if (cube->player->cam_dir == -1)
		rotate_to_left(cube, rot_speed);
	// double	rotSpeed;

	// rotSpeed = cube->frameTime * 3.0;	// the constant value is in radians/second
	// rotate_to_right(cube, rotSpeed);
	// rotate_to_left(cube, rotSpeed);
}

void	mlx_hooks(t_game *cube)
{
	mlx_hook(cube->mlx_win, 17, 0, close_window, cube);
	mlx_hook(cube->mlx_win, 2, 1L << 0, key_press, (void *)cube);
	mlx_hook(cube->mlx_win, 3, 1L << 1, key_release, (void *)cube);
}

int	game_loop(t_game *cube)
{
	render_map(cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img->img, 0, 0);
	count_fps(cube);
	update_movement(cube);
	update_rotation(cube);
	return (0);
}


void	init_direction(t_game *cube)
{
	if (cube->player->direction == 'W')
	{
		cube->player->dirx = -1;
		cube->player->planey = 0.66;
	}
	if (cube->player->direction == 'E')
	{
		cube->player->dirx = 1;
		cube->player->planey = -0.66;
	}
	if (cube->player->direction == 'N')
	{
		cube->player->diry = 1;
		cube->player->planex = -0.66;
	}
	if (cube->player->direction == 'S')
	{
		cube->player->diry = -1;
		cube->player->planex = 0.66;
	}
	// if (cube->player->direction == 'W')
	// {
	// 	cube->player->dirX = -1;
	// 	cube->player->planeY = 0.66;
	// }
	// if (cube->player->direction == 'E')
	// {
	// 	cube->player->dirX = 1;
	// 	cube->player->planeY = -0.66;
	// }
	// if (cube->player->direction == 'N')
	// {
	// 	cube->player->dirY = -1;
	// 	cube->player->planeX = -0.66;
	// }
	// if (cube->player->direction == 'S')
	// {
	// 	cube->player->dirY = 1;
	// 	cube->player->planeX = 0.66;
	// }
}

void	save_player(t_game *cube)
{
	int	i;
	int	j;

	i = 0;
	while(cube->real_map[i] != NULL)
	{
		j = 0;
		while (cube->real_map[i][j] != '\0')
		{
			if (is_player(cube->real_map[i][j]))
			{
				cube->player->posx = i;
				cube->player->posy = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

 int	player_existence(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->real_map[++i])
	{
		j = -1;
		while (game->real_map[i][++j])
		{
			if (game->real_map[i][j] == 'N' || game->real_map[i][j] == 'S'
				|| game->real_map[i][j] == 'E'
				|| game->real_map[i][j] == 'W')
			{
				game->player->posy = i + 0.5;
				game->player->posx = j + 0.5;
				game->player->direction = game->real_map[i][j];
				game->real_map[i][j] = '0';
				return (1);
			}
		}
	}
	return (0);
}

void	load_imgs(t_game *cube)
{
	cube->mlx_win = mlx_new_window(cube->mlx, SCREENWIDTH,
			SCREENHEIGHT, "Cube3D");
	cube->img->img = mlx_new_image(cube->mlx, SCREENWIDTH, SCREENHEIGHT);
	cube->img->addr = mlx_get_data_addr(cube->img->img,
			&cube->img->bpp, &cube->img->line_length,
			&cube->img->endian);
}
int	main(int argc, char **argv)
{
	t_game		*cube;

	(void)argv;
	if (argc == 2)
	{
		cube = ft_calloc(1, sizeof(t_game));
		is_cube(argv[1]);
		init_all(cube);

		parse_map(argv, cube);
		extract_texture(cube);
		extract_colors(cube);
		check_rgb(cube);
		rgb_to_hex(cube);
		check_real_map(cube);
		extract_real_map(cube);
		check_player(cube);
		check_symbols(cube); // dopo realmap
		check_flmap(cube);
		check_map(cube);
		replace_tabs_in_real_map(&cube->real_map, cube->map_height);
		save_player(cube);
		// print_map(cube->real_map);
		if (!player_existence(cube))
			free_err(cube, "Error\nPlayer doesn't exist\n");
		//printf_player(cube);
		//print_colors_value(cube);
		//print_texture_value(cube);
		cube->mlx = mlx_init();
		load_imgs(cube);
		load_all_texture(cube);
		mlx_hooks(cube);
		init_direction(cube);
		mlx_loop_hook(cube->mlx, game_loop, cube);
		mlx_loop(cube->mlx);
	}
	else
		write(2, "Error\nInvalid number of arguments\n", 34);
	exit(0);
}

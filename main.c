#include "cube.h"

int worldMap[mapWidth][mapHeight] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

void	init_data(t_data *data, t_game *cube, int x)
{
	data->cameraX = 2 * x / (double)SCREENWIDTH - 1; // x-coordinate in camera space
	data->rayDirX = cube->player->dirX + cube->player->planeX * data->cameraX;
	data->rayDirY = cube->player->dirY + cube->player->planeY * data->cameraX;
	data->mapX = (int)cube->player->posX;
	data->mapY = (int)cube->player->posY;
	data->deltaDistX = (data->rayDirX == 0) ? 1e30 : fabs(1.0 / data->rayDirX);
	data->deltaDistY = (data->rayDirY == 0) ? 1e30 : fabs(1.0 / data->rayDirY);
	data->hit = 0; // was there a wall hit?
	data->side = 0;	 // was a NS or a EW wall hit?
	init_step(data, cube);
}

void 	init_step(t_data *data, t_game *cube)
{
	if (data->rayDirX < 0)
	{
		data->stepX = -1;
		data->sideDistX = (cube->player->posX - data->mapX) * data->deltaDistX;
	}
	else
	{
		data->stepX = 1;
		data->sideDistX = (data->mapX + 1.0 - cube->player->posX) * data->deltaDistX;
	}
	if (data->rayDirY < 0)
	{
		data->stepY = -1;
		data->sideDistY = (cube->player->posY - data->mapY) * data->deltaDistY;
	}
	else
	{
		data->stepY = 1;
		data->sideDistY = (data->mapY + 1.0 - cube->player->posY) * data->deltaDistY;
	}
}

void	dda_algorithm(t_data *data)
{
	// perform DDA
	while (data->hit == 0)
	{
		// jump to next map square, either in x-direction, or in y-direction
		if (data->sideDistX < data->sideDistY)
		{
			data->sideDistX += data->deltaDistX;
			data->mapX += data->stepX;
			data->side = 0;
		}
		else
		{
			data->sideDistY += data->deltaDistY;
			data->mapY += data->stepY;
			data->side = 1;
		}
		// Check if ray has hit a wall
		if (worldMap[data->mapX][data->mapY] > 0)
			data->hit = 1;
	}
}

void	set_color(t_data *data, t_game *cube, int shift)
{
	if (data->side == 1)
	{
		//nord
		if (data->rayDirY > 0)
			data->color = *(unsigned int *)(cube->card->north_wall.addr + shift);
		//sud
		else
			data->color = *(unsigned int *)(cube->card->south_wall.addr + shift);
	}
	else
	{
		//est
		if (data->rayDirX > 0)
			data->color = *(unsigned int *)(cube->card->east_wall.addr + shift);
		//ovest
		else
			data->color = *(unsigned int *)(cube->card->west_wall.addr + shift);
	}
}

void	setTexWH(t_data *data, t_game *cube)
{
	if (data->side == 1)
	{
		if (data->rayDirY > 0)
		{
			data->texWidth = cube->card->north_wall.width;
			data->texHeight = cube->card->north_wall.height;
			return ;
		}
		data->texWidth = cube->card->south_wall.width;
		data->texHeight = cube->card->south_wall.height;
	}
	else
	{
		if (data->rayDirX > 0)
		{
			data->texWidth = cube->card->east_wall.width;
			data->texHeight = cube->card->east_wall.height;
			return ;
		}
		data->texWidth = cube->card->west_wall.width;
		data->texHeight = cube->card->west_wall.height;
	}
}

void	wallPosRayPosOnWall(t_data *data, t_game *cube)
{
	if (data->side == 0)
		data->perpWallDist = (data->sideDistX - data->deltaDistX);
	else
		data->perpWallDist = (data->sideDistY - data->deltaDistY);
	data->lineHeight = (int)(SCREENHEIGHT / data->perpWallDist);
	data->drawStart = -data->lineHeight / 2 + SCREENHEIGHT / 2;
	if (data->drawStart < 0)
		data->drawStart = 0;
	data->drawEnd = data->lineHeight / 2 + SCREENHEIGHT / 2;
	if (data->drawEnd >= SCREENHEIGHT)
		data->drawEnd = SCREENHEIGHT - 1;
	if (data->side == 0)
		data->wallX = cube->player->posY + data->perpWallDist * data->rayDirY;
	else
		data->wallX = cube->player->posX + data->perpWallDist * data->rayDirX;
	data->wallX -= (int)(data->wallX);
	setTexWH(data, cube);
	data->texX = (int)(data->wallX * (double)data->texWidth);
	if(data->side == 0 && data->rayDirX > 0)
		data->texX = data->texWidth - data->texX - 1;
	if(data->side == 1 && data->rayDirY < 0)
		data->texX = data->texWidth - data->texX - 1;
}


void	drawTextWall(t_data *data, t_game *cube, int x)
{
	int	y;

	data->step = 1.0 * data->texHeight / data->lineHeight;
	data->texPos = (data->drawStart - SCREENHEIGHT / 2 + data->lineHeight / 2) * data->step;
	y = data->drawStart;
	while(y < data->drawEnd)
	{
		data->texY = (int)data->texPos % data->texHeight;
		data->texPos += data->step;
		set_color(data, cube, 4 * (int)(data->texHeight * data->texY + data->texX));
		my_mlx_pixel_put(cube->img, x, y++, data->color);
	}
}

void	draw_vertical_line(t_data *data, t_game *cube, int x)
{
	int	i;

	i = 0;
	wallPosRayPosOnWall(data, cube);
	while (i < data->drawStart)
		my_mlx_pixel_put(cube->img, x, i++, 0xFF00FFFF);
	drawTextWall(data, cube, x);
	i = data->drawEnd;
	while (i < SCREENHEIGHT)
		my_mlx_pixel_put(cube->img, x, i++, 0xFFFFFFFF);
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
		dda_algorithm(&data);
		draw_vertical_line(&data, cube, x);
		x++;
	}
}


void	move_forward(t_game *cube, double moveSpeed)
{
	// move forward if no wall in front of you
	if (cube->player->mov_dirY == 1)
	{
		if (worldMap[(int)(cube->player->posX + cube->player->dirX * moveSpeed)][(int)cube->player->posY] == false)
			cube->player->posX += cube->player->dirX * moveSpeed;
		if (worldMap[(int)(cube->player->posX)][(int)(cube->player->posY + cube->player->dirY * moveSpeed)] == false)
			cube->player->posY += cube->player->dirY * moveSpeed;
	}
}

void	move_backward(t_game *cube, double moveSpeed)
{
	// move backwards if no wall behind you
	if (cube->player->mov_dirY == -1)
	{
		if (worldMap[(int)(cube->player->posX - cube->player->dirX * moveSpeed)][(int)cube->player->posY] == false)
			cube->player->posX -= cube->player->dirX * moveSpeed;
		if (worldMap[(int)cube->player->posX][(int)(cube->player->posY - cube->player->dirY * moveSpeed)] == false)
			cube->player->posY -= cube->player->dirY * moveSpeed;
	}
}

void	move_left(t_game *cube, double moveSpeed)
{
	// move to left
	if (cube->player->mov_dirX == -1)
	{
		if (worldMap[(int)(cube->player->posX - cube->player->dirY * moveSpeed)][(int)cube->player->posY] == false)
			cube->player->posX -= cube->player->dirY * moveSpeed;
		if (worldMap[(int)(cube->player->posX)][(int)(cube->player->posY + cube->player->dirX * moveSpeed)] == false)
			cube->player->posY += (cube->player->dirX) * moveSpeed;
	}
}

void	move_rigth(t_game *cube, double moveSpeed)
{
	// move to right
	if (cube->player->mov_dirX == 1)
	{
		if (worldMap[(int)(cube->player->posX + cube->player->dirY * moveSpeed)][(int)cube->player->posY] == false)
			cube->player->posX += cube->player->dirY * moveSpeed;
		if (worldMap[(int)cube->player->posX][(int)(cube->player->posY - cube->player->dirX * moveSpeed)] == false)
			cube->player->posY -= (cube->player->dirX) * moveSpeed;
	}
}

void	update_movement(t_game *cube)
{
	// speed modifiers
	double	moveSpeed;

	moveSpeed = cube->frameTime * 5.0; // the constant value is in squares/second
	move_forward(cube, moveSpeed);
	move_backward(cube, moveSpeed);
	move_left(cube, moveSpeed);
	move_rigth(cube, moveSpeed);
}

void	rotate_to_right(t_game *cube, double rotSpeed)
{
	double	oldDirX;
	double	oldPlaneX;
	// rotate to the right
	if (cube->player->cam_dir == 1)
	{
		// both camera direction and camera plane must be rotated
		oldDirX = cube->player->dirX;
		cube->player->dirX = cube->player->dirX * cos(-rotSpeed) - cube->player->dirY * sin(-rotSpeed);
		cube->player->dirY = oldDirX * sin(-rotSpeed) + cube->player->dirY * cos(-rotSpeed);
		oldPlaneX = cube->player->planeX;
		cube->player->planeX = cube->player->planeX * cos(-rotSpeed) - cube->player->planeY * sin(-rotSpeed);
		cube->player->planeY = oldPlaneX * sin(-rotSpeed) + cube->player->planeY * cos(-rotSpeed);
	}
}

void	rotate_to_left(t_game *cube, double rotSpeed)
{
	double	oldDirX;
	double	oldPlaneX;

	// rotate to the left
	if (cube->player->cam_dir == -1)
	{
		// both camera direction and camera plane must be rotated
		oldDirX = cube->player->dirX;
		cube->player->dirX = cube->player->dirX * cos(rotSpeed) - cube->player->dirY * sin(rotSpeed);
		cube->player->dirY = oldDirX * sin(rotSpeed) + cube->player->dirY * cos(rotSpeed);
		oldPlaneX = cube->player->planeX;
		cube->player->planeX = cube->player->planeX * cos(rotSpeed) - cube->player->planeY * sin(rotSpeed);
		cube->player->planeY = oldPlaneX * sin(rotSpeed) + cube->player->planeY * cos(rotSpeed);
	}
}
void	update_rotation(t_game *cube)
{
	double	rotSpeed;

	rotSpeed = cube->frameTime * 3.0;	// the constant value is in radians/second
	rotate_to_right(cube, rotSpeed);
	rotate_to_left(cube, rotSpeed);
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
		extract_colors(cube);
		extract_texture(cube);
		check_real_map(cube);
		extract_real_map(cube);
		check_rgb(cube);
		rgb_to_hex(cube);
		replace_tabs_in_real_map(&cube->real_map, cube->map_height);
		check_symbols(cube);
		//save_player(cube);
		printf_player(cube);
		print_colors_value(cube);
		print_texture_value(cube);
		cube->mlx = mlx_init();
		cube->mlx_win = mlx_new_window(cube->mlx, SCREENWIDTH, SCREENHEIGHT, "Cub3D");
		cube->img->img = mlx_new_image(cube->mlx, SCREENWIDTH, SCREENHEIGHT);
		cube->img->addr = mlx_get_data_addr(cube->img->img, &cube->img->bpp, &cube->img->line_length, &cube->img->endian);
		mlx_hooks(cube);
		load_all_texture(cube);
		mlx_loop_hook(cube->mlx, game_loop, cube);
		mlx_loop(cube->mlx);
		free_all(cube);
	}
	else
		write(2, "Error\nInvalid number of arguments\n", 34);
	exit(0);
}

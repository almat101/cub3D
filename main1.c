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
	data->cameraX = 2 * x / (double)screenWidth - 1; // x-coordinate in camera space
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

void	draw_vertical_line(t_game *cube, t_data *data, int x)
{
	int	i;

	i = 0;
	data->perpWallDist = (data->side == 0) ? (data->sideDistX - data->deltaDistX) : (data->sideDistY - data->deltaDistY);
	data->lineHeight = (int)(screenHeight / data->perpWallDist);
	data->drawStart = -data->lineHeight / 2 + screenHeight / 2;
	if (data->drawStart < 0)
		data->drawStart = 0;
	data->drawEnd = data->lineHeight / 2 + screenHeight / 2;
	if (data->drawEnd >= screenHeight)
		data->drawEnd = screenHeight - 1;
	set_color(data);
	while (i < data->drawStart)
		my_mlx_pixel_put(cube->img, x, i++, 0xFF0000FF);
	while (i < data->drawEnd)
		my_mlx_pixel_put(cube->img, x, i++, data->color);
	while (i < screenHeight)
		my_mlx_pixel_put(cube->img, x, i++, 0xFF808090);
}


void	set_color(t_data *data)
{
	if (data->side == 1)
	{
		//nord texture
		if (data->rayDirY > 0)
			data->color = 0xFF00FF00;
		//sud texture
		else
			data->color = 0xFF800080;
	}
	else
	{
		//est texture
		if (data->rayDirX > 0)
			data->color = 0xFF00FF90;
		//ovest texture
		else
			data->color = 0xFFC040C0;
	}
}
void	render_map(t_game *cube)
{
	t_data	data;
	int		x;

	x = -1;
	while (++x < screenWidth)
	{
		init_data(&data, cube, x);
		dda_algorithm(&data);
		draw_vertical_line(cube, &data, x);
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
	// rotate to the right
	if (cube->player->cam_dir == 1)
	{
		// both camera direction and camera plane must be rotated
		double oldDirX = cube->player->dirX;
		cube->player->dirX = cube->player->dirX * cos(-rotSpeed) - cube->player->dirY * sin(-rotSpeed);
		cube->player->dirY = oldDirX * sin(-rotSpeed) + cube->player->dirY * cos(-rotSpeed);
		double oldPlaneX = cube->player->planeX;
		cube->player->planeX = cube->player->planeX * cos(-rotSpeed) - cube->player->planeY * sin(-rotSpeed);
		cube->player->planeY = oldPlaneX * sin(-rotSpeed) + cube->player->planeY * cos(-rotSpeed);
	}
}

void	rotate_to_left(t_game *cube, double rotSpeed)
{
	// rotate to the left
	if (cube->player->cam_dir == -1)
	{
		// both camera direction and camera plane must be rotated
		double oldDirX = cube->player->dirX;
		cube->player->dirX = cube->player->dirX * cos(rotSpeed) - cube->player->dirY * sin(rotSpeed);
		cube->player->dirY = oldDirX * sin(rotSpeed) + cube->player->dirY * cos(rotSpeed);
		double oldPlaneX = cube->player->planeX;
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
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img->img, 0, 0);
	render_map(cube);
	count_fps(cube);
	update_movement(cube);
	update_rotation(cube);
	return (0);
}
int main(int argc, char **argv)
{

	t_game		cube;
	t_player	player;
	t_img		img;
	(void)argc;
	(void)argv;

	player.posX = 18;
	player.posY = 11.5;
	player.dirX = -1;
	player.dirY = 0;
	player.planeX = 0;
	player.planeY = 0.66;
	cube.time = 0;
	cube.oldTime = 0;
	cube.mlx = mlx_init();
	cube.mlx_win = mlx_new_window(cube.mlx, screenWidth, screenHeight, "Cub3D");
	img.img = mlx_new_image(cube.mlx, screenWidth, screenHeight);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	cube.img = &img;
	cube.player = &player;
	mlx_hooks(&cube);
	mlx_loop_hook(cube.mlx, game_loop, &cube);
	mlx_loop(cube.mlx);
}

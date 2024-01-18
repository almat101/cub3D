#include "cube.h"

void	init_all(t_game *cube)
{
	cube->player = ft_calloc(1, sizeof(t_player));
	cube->colors = ft_calloc(1, sizeof(t_colors));
	cube->img = ft_calloc(1, sizeof(t_img));
	cube->card = ft_calloc(1, sizeof(t_cards));
	cube->real_map = NULL;
	cube->map = NULL;
	cube->player->posX = 18;
	cube->player->posY = 11;
	cube->player->dirX = -1;
	cube->player->dirY = 0;
	cube->player->planeX = 0;
	cube->player->planeY = 0.66;
	cube->player->mov_dirX = 0;
	cube->player->mov_dirY = 0;
	cube->player->cam_dir = 0;
	cube->time = 0;
	cube->oldTime = 0;
	cube->map_width = 0;
	cube->map_height = 0;
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
	// cube->colors->floor_color = NULL;
	// cube->colors->ceil_color = NULL;
	// cube->colors->f_hex_color = NULL;
	// cube->colors->c_hex_color = NULL;
}

int	close_window(t_game *cube)
{
	mlx_destroy_window(cube->mlx, cube->mlx_win);
	mlx_destroy_image(cube->mlx, cube->img->img);
	mlx_destroy_image(cube->mlx, cube->card->east_wall.img);
	mlx_destroy_image(cube->mlx, cube->card->west_wall.img);
	mlx_destroy_image(cube->mlx, cube->card->north_wall.img);
	mlx_destroy_image(cube->mlx, cube->card->south_wall.img);
	free(cube->card);
	free(cube->player);
	free(cube->img);
	free(cube->colors);
	free(cube->mlx);
	free(cube);
	exit (1);
}

void	destroy_all(t_game *cube)
{
	mlx_destroy_window(cube->mlx, cube->mlx_win);
	mlx_destroy_image(cube->mlx, cube->img->img);
}

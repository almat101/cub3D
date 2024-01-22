#include "cube.h"

void	init_all(t_game *cube)
{
	cube->player = ft_calloc(1, sizeof(t_player));
	cube->colors = ft_calloc(1, sizeof(t_colors));
	cube->img = ft_calloc(1, sizeof(t_img));
	cube->card = ft_calloc(1, sizeof(t_cards));
	// cube->real_map = NULL;
	// cube->map = NULL;
	cube->player->posx = 0;
	cube->player->posy = 0;
	cube->player->dirx = 0;
	cube->player->diry = 0;
	cube->player->planex = 0;
	cube->player->planey = 0;
	cube->player->mov_dirx = 0;
	cube->player->mov_diry = 0;
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

void	free_all(t_game *cube)
{
	if (cube->map)
		free_mat(cube->map);
	if (cube->real_map)
		free_mat(cube->real_map);
	free_texture(cube);
	free_colors(cube);
	free(cube->card);
	free(cube->player);
	free(cube->colors);
	free(cube->img);
	mlx_destroy_window(cube->mlx, cube->mlx_win);
	free(cube->mlx);
	free(cube);
}

void	free_all2(t_game *cube)
{
	if (cube->map)
		free_mat(cube->map);
	if (cube->real_map)
		free_mat(cube->real_map);
	free_texture(cube);
	free_colors(cube);
	free(cube->card);
	free(cube->player);
	free(cube->colors);
	free(cube->img);
	free(cube);
}
int	close_window(t_game *cube)
{
	mlx_destroy_image(cube->mlx, cube->card->east_wall.img);
	mlx_destroy_image(cube->mlx, cube->card->west_wall.img);
	mlx_destroy_image(cube->mlx, cube->card->north_wall.img);
	mlx_destroy_image(cube->mlx, cube->card->south_wall.img);
	mlx_destroy_image(cube->mlx, cube->img->img);
	free_all(cube);
	exit (0);
}

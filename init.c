#include "cube.h"

void	init_all(t_game *cube)
{
	cube->player = ft_calloc(1, sizeof(t_player));
	cube->colors = ft_calloc(1, sizeof(t_colors));
	cube->img = ft_calloc(1, sizeof(t_img));
	cube->cards = ft_calloc(1, sizeof(t_cards));
	cube->real_map = NULL;
	cube->map = NULL;
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
	cube->cards->no = NULL;
	cube->cards->so = NULL;
	cube->cards->ea = NULL;
	cube->cards->we = NULL;
	cube->cards->f_no = 0;
	cube->cards->f_so = 0;
	cube->cards->f_we = 0;
	cube->cards->f_ea = 0;
	cube->colors->f_floor = 0;
	cube->colors->c_ceil = 0;
	cube->colors->floor_color = NULL;
	cube->colors->ceil_color = NULL;
	cube->colors->f_hex_color = NULL;
	cube->colors->c_hex_color = NULL;

}

void	free_all(t_game *cube)
{
	if (cube->map)
		free_mat(cube->map);
	if (cube->real_map)
		free_mat(cube->real_map);
	free_texture(cube);
	free_colors(cube);
	free(cube->player);
	free(cube->colors);
	free(cube->img);
	free(cube->cards);
}

// void		*mlx;
// 	void		*mlx_win;
// 	t_colors	*colors;
// 	t_player	*player;
// 	double		time;
// 	double		oldTime;
// 	int			fps;
// 	double		frameTime;
// 	t_img 		*img;
// 	char 		**map;
// 	char		**real_map;
// 	int			map_width;
// 	int			map_height;
// 	char		*north_texture;
// 	char		*south_texture;
// 	char		*west_texture;
// 	char		*east_texture;
// 	char		*ceil_color_rgb;
// 	char		*floor_color_rgb;

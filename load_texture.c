#include "cube.h"

void	load_texture_NO_SO(t_game *cube)
{
	cube->card->north_wall.img = mlx_xpm_file_to_image(cube->mlx,
			cube->card->no,
			&cube->card->north_wall.width, &cube->card->north_wall.height);
	if(!cube->card->north_wall.img)
		free_err(cube, "Error\nNorth wall doesn't load\n");
	cube->card->north_wall.addr = mlx_get_data_addr(cube->card->north_wall.img,
			&cube->card->north_wall.bpp, &cube->card->north_wall.line_length,
			&cube->card->north_wall.endian);
	cube->card->south_wall.img = mlx_xpm_file_to_image(cube->mlx,
			cube->card->so,
			&cube->card->south_wall.width, &cube->card->south_wall.height);
	if(!cube->card->south_wall.img)
		free_err(cube, "Error\nsouth wall doesn't load\n");
	cube->card->south_wall.addr = mlx_get_data_addr(cube->card->south_wall.img,
			&cube->card->south_wall.bpp, &cube->card->south_wall.line_length,
			&cube->card->south_wall.endian);
}

void	load_texute_EA_WE(t_game *cube)
{
	cube->card->east_wall.img = mlx_xpm_file_to_image(cube->mlx,
			cube->card->ea,
			&cube->card->east_wall.width, &cube->card->east_wall.height);
	if(!cube->card->east_wall.img)
		free_err(cube, "Error\neast wall doesn't load\n");
	cube->card->east_wall.addr = mlx_get_data_addr(cube->card->east_wall.img,
			&cube->card->east_wall.bpp, &cube->card->east_wall.line_length,
			&cube->card->east_wall.endian);
	cube->card->west_wall.img = mlx_xpm_file_to_image(cube->mlx,
			cube->card->we,
			&cube->card->west_wall.width, &cube->card->west_wall.height);
	if(!cube->card->west_wall.img)
		free_err(cube, "Error\nwest wall doesn't load\n");
	cube->card->west_wall.addr = mlx_get_data_addr(cube->card->west_wall.img,
			&cube->card->west_wall.bpp, &cube->card->west_wall.line_length,
			&cube->card->west_wall.endian);
}

void	load_all_texture(t_game *cube)
{
	load_texture_NO_SO(cube);
	load_texute_EA_WE(cube);
}

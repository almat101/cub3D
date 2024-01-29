#include "cube.h"

int	game_loop(t_game *cube)
{
	render_map(cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img->img, 0, 0);
	count_fps(cube);
	update_movement(cube);
	update_rotation(cube);
	return (0);
}

void	initialize_game(t_game *cube, char **argv)
{
	is_cube(cube, argv[1]);
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

void	start_game(t_game *cube)
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
		printf("Error\nInvalid number of arguments\n");
	exit(0);
}

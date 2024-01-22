#include "cube.h"

int	main (int argc, char **argv)
{
	t_game	*cube;

	if (argc == 2)
	{
		cube = ft_calloc(1,sizeof(t_game));
		is_cube(argv[1]);
		init_all(cube);

		parse_map(argv, cube);
		extract_colors(cube);
		extract_texture(cube);
		check_real_map(cube);
		extract_real_map(cube);
		check_rgb(cube);
		rgb_to_hex(cube);
		replace_tabs_in_real_map(&cube->map, cube->map_height);
		check_symbols(cube);
		save_player(cube);

		//cube->mlx = mlx_init();

		print_map(cube->map);
		printf_player(cube);
		check_player(cube);
		check_flmap(cube);
		check_map(cube);
		//print_texture_value(cube);
		//print_colors_value(cube);
		//mlx_hook(cube->mlx_win, 17, 0, close_window, cube);
		//load_img(cube);
		//load_all_texture(cube);
		//mlx_loop_hook(cube->mlx, game_loop, cube);
		//mlx_loop(cube->mlx);
		free_all(cube);
	}
	else
		write(2,"Error\nInvalid number of arguments\n",34);
	return (0);
}

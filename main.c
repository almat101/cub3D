/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:02:32 by amatta            #+#    #+#             */
/*   Updated: 2024/01/30 13:02:33 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	check_nplayer(cube);
	check_symbols(cube);
	check_edges(cube);
	check_flmap(cube);
	check_inner_map(cube);
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

int	main(int argc, char **argv)
{
	t_game	*cube;

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

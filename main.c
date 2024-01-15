#include "cube.h"

/*
controllare i bordi se non sono presenti 0
controllare se non ci sono spazi dove sono presenti i 0, per esempio tra 10 e 01 e 00 uno spazio in mezzo
oppure sostituire i spazi con 0 e i tab con 4 zeri
se trovo newline in getnextline e dopo trovo la mappa e errore
*/

int	main (int argc, char **argv)
{
	t_game	cube;

	if (argc == 2)
	{
		is_cube(argv[1]);
		init_all(&cube);

		parse_map(argv, &cube);
		extract_texture(&cube);
		extract_real_map(&cube);
		extract_colors(&cube);
		// check for valid rgb values
		check_rgb(&cube);
		rgb_to_hex(&cube);

		//fill map with 0
		//fill_map_with_zero(&cube.real_map, cube.map_height);
		//check_card1(&cube);  // is redundant???????????
		//check_colors(&cube);
		replace_tabs_in_real_map(&cube.real_map, cube.map_height);
		check_player(&cube);
		check_flmap(&cube);
		check_map(&cube);
		print_map(cube.real_map);
		//print_texture_value(&cube);
		//print_colors_value(&cube);
		//print_hexa_color(&cube);
		free_all(&cube);
	}
	else
		printf("Error\nInvalid number of arguments\n");
	return (0);
}




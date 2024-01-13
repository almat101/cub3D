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
		parse_map(argv, &cube);
		check_card1(&cube);
		check_card2(&cube);

		printf("all map:\n");
		print_all_map(&cube);

		printf("now real map:\n");
		extract_map(argv, &cube);
		print_real_map(&cube);

		printf("now texture:\n");
		extract_texture_value(&cube);
		print_texture_value(&cube);
		free_all_map(&cube);
		free_real_map(&cube);
		free_texture(&cube);
	}
	else
		printf("Error\nInvalid number of arguments\n");
	return (0);
}

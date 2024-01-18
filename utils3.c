#include "cube.h"

void	print_colors_value(t_game *cube)
{
	printf("floor color int: %d\n", cube->colors->f_floor);
	printf("ceil color int: %d\n", cube->colors->c_ceil);
	printf("floor hexa color: %s\n", cube->colors->f_hex_color);
	printf("ceil hexa color: %s\n", cube->colors->c_hex_color);
}


void	print_texture_value(t_game *cube)
{
	printf("%s", cube->card->no);
	printf("%s", cube->card->so);
	printf("%s", cube->card->we);
	printf("%s", cube->card->ea);
}
void	free_err(t_game *cube, char *s)
{
	free_all(cube);
	while (*s)
		write(2, s++, 1);
	exit(1);
}

#include "cube.h"

void	print_colors_value(t_game *cube)
{
	printf("floor color int: %d", cube->colors->f_color_num);
	printf("ceil colorint: %d", cube->colors->f_floor);
}
void	print_hexa_color(t_game *cube)
{
	printf("floor hexa color: %s\n", cube->colors->f_hex_color);
	printf("ceil hexa color: %s\n", cube->colors->c_hex_color);
}
void	free_err(t_game *cube, char *s)
{
	free_all(cube);
	while (*s)
		write(2, s++, 1);
	exit(1);
}

#include "cube.h"

void	print_colors_value(t_game *cube)
{
	printf("floor color: %s", cube->colors->floor_color);
	printf("ceil color: %s", cube->colors->ceil_color);
}

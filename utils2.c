#include "cube.h"

void	print_map(char **map)
{
	int		i;

	i = 0;
	while (map[i] != NULL)
	{
		printf("%s", map[i]);
		i++;
	}
}
void	print_colors_value(t_game *cube)
{
	printf("floor color int: %d\n", cube->colors->f_floor);
	printf("ceil color int: %d\n", cube->colors->c_ceil);
	printf("floor hexa color: %s\n", cube->colors->f_hex_color);
	printf("ceil hexa color: %s\n", cube->colors->c_hex_color);
}


void	print_texture_value(t_game *cube)
{
	printf("%s\n", cube->card->no);
	printf("%s\n", cube->card->so);
	printf("%s\n", cube->card->we);
	printf("%s\n", cube->card->ea);
}

void	printf_player(t_game *cube)
{
	printf("Player position: %f %f\n", cube->player->posX, cube->player->posY);
//	printf("Player direction: %f %f\n", cube->player->dirX, cube->player->dirY);
//	printf("Player plane: %f %f\n", cube->player->planeX, cube->player->planeY);
}

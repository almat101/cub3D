#include "cube.h"

void	save_player(t_game *cube)
{
	int	i;
	int	j;

	i = 0;
	while(cube->real_map[i] != NULL)
	{
		j = 0;
		while (cube->real_map[i][j] != '\0')
		{
			if (is_player(cube->real_map[i][j]))
			{
				cube->player->posX = i;
				cube->player->posY = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	printf_player(t_game *cube)
{
	printf("Player position: %f %f\n", cube->player->posX, cube->player->posY);
//	printf("Player direction: %f %f\n", cube->player->dirX, cube->player->dirY);
//	printf("Player plane: %f %f\n", cube->player->planeX, cube->player->planeY);
}
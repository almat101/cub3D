#include "cube.h"

void	free_real_map(t_game *cube)
{
	int i;

	i = 0;
	if (cube->real_map == NULL)
		return ;
	while (cube->real_map[i] != NULL)
	{
		free(cube->real_map[i]);
		i++;
	}
	free(cube->real_map);
}

void	free_mat(char **mat)
{
	int i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

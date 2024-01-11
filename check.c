#include "cube.h"

void	check_cardinals(t_game *cube)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (cube->map[i] != NULL)
	{
		if (ft_strncmp(cube->map[i], "NO ", 3) == 0)
			count++;
		else if (ft_strncmp(cube->map[i], "SO ", 3) == 0)
			count++;
		else if (ft_strncmp(cube->map[i], "WE ", 3) == 0)
			count++;
		else if (ft_strncmp(cube->map[i], "EA ", 3) == 0)
			count++;
		else if (ft_strncmp(cube->map[i], "F ", 2) == 0)
			count++;
		else if (ft_strncmp(cube->map[i], "C ", 2) == 0)
			count++;
		i++;
	}
	if (count != 6)
	{
		printf("Error\nMissing cardinal or ceil or floor value\n");
		exit (1);
	}
}

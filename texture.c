#include "cube.h"


void	extract_texture_value(t_game *cube)
{
	int		i;

	i = 0;
	while (cube->map[i] != NULL)
	{
		if (ft_strncmp(cube->map[i], "NO ", 3) == 0)
			cube->north_texture = ft_strdup(cube->map[i] + 3);
		else if (ft_strncmp(cube->map[i], "SO ", 3) == 0)
			cube->south_texture = ft_strdup(cube->map[i] + 3);
		else if (ft_strncmp(cube->map[i], "WE ", 3) == 0)
			cube->west_texture = ft_strdup(cube->map[i] + 3);
		else if (ft_strncmp(cube->map[i], "EA ", 3) == 0)
			cube->east_texture = ft_strdup(cube->map[i] + 3);
		else if (ft_strncmp(cube->map[i], "F ", 2) == 0)
			cube->floor_color_rgb = ft_strdup(cube->map[i] + 2);
		else if (ft_strncmp(cube->map[i], "C ", 2) == 0)
			cube->ceil_color_rgb = ft_strdup(cube->map[i] + 2);
		i++;
	}
}

void	print_texture_value(t_game *cube)
{
	printf("%s", cube->north_texture);
	printf("%s", cube->south_texture);
	printf("%s", cube->west_texture);
	printf("%s", cube->east_texture);
	printf("%s", cube->floor_color_rgb);
	printf("%s", cube->ceil_color_rgb);
}

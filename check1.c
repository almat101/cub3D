#include "cube.h"

// extract color values from the map and put in a string with the assign
void extract_colors(t_game *cube)
{
	int i;

	i = 0;
	while (cube->map[i] != NULL)
	{
		if (ft_strncmp(cube->map[i], "F ", 2) == 0)
			assign_colors(cube, &cube->colors->floor_color, cube->map[i] + 2, &cube->colors->f_floor);
		else if (ft_strncmp(cube->map[i], "C ", 2) == 0)
			assign_colors(cube, &cube->colors->ceil_color, cube->map[i] + 2, &cube->colors->f_ceil);
		i++;
	}
	if (cube->colors->f_floor == 0 || cube->colors->f_ceil == 0)
	{
		printf("Error\nMissing colors\n");
		free_all(cube);
		exit (1);
	}
}

// check if the color values are valid and assign them with strdup
void	assign_colors(t_game *cube, char **dest, const char *src, int *flag)
{
	if (*flag == 1)
	{
		printf("Error\nDuplicate color\n");
		free_all(cube);
		exit(1);
	}
	else if (*flag == 0)
	{
		*dest = ft_strdup(src);
		*flag = 1;
	}
}

void	ft_rgb_err(t_game *cube, char *line, char **rgb_value)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
		{
			printf("Error\nInvalid RGB values\n");
			free_all(cube);
			free_mat(rgb_value);
			exit(1);
		}
		i++;
	}
}

// check if the color values are valid rgb > 0 and < 255
void check_valid_rgb(t_game *cube, char *line)
{
	char	**rgb_values;
	int		i;
	int 	value;

	value = 0;
	i = 0;
	rgb_values = ft_split(line + 2, ',');
	while (rgb_values[i] != NULL)
		i++;
	if (i != 3)
		ft_rgb_err(cube, line, rgb_values);
	while (i-- > 0)
	{
		value = ft_atoi_rgb(rgb_values[i]);
		if (value < 0 || value > 255)
			ft_rgb_err(cube, line, rgb_values);
	}
	free_mat(rgb_values);
}

// check if the color values are valid in form of rgb 3 values
void check_rgb(t_game *cube)
{
	int i;

	i = 0;
	while (cube->map[i] != NULL)
	{
		if (ft_strncmp(cube->map[i], "F ", 2) == 0)
			check_valid_rgb(cube, cube->map[i]);
		else if (ft_strncmp(cube->map[i], "C ", 2) == 0)
			check_valid_rgb(cube, cube->map[i]);
		i++;
	}
}

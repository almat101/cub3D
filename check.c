#include "cube.h"

void	check_card1(t_game *cube)
{
	int i;

	i = 0;
	while (cube->map[i] != NULL)
	{
		if (ft_strncmp(cube->map[i], "NO ", 3) == 0)
			cube->cards->f_no = 1;
		else if (ft_strncmp(cube->map[i], "SO ", 3) == 0)
			cube->cards->f_so = 1;
		else if (ft_strncmp(cube->map[i], "WE ", 3) == 0)
			cube->cards->f_we = 1;
		else if (ft_strncmp(cube->map[i], "EA ", 3) == 0)
			cube->cards->f_ea = 1;
		i++;
	}
	if (cube->cards->f_no == 0 || cube->cards->f_so == 0
		|| cube->cards->f_we == 0 || cube->cards->f_ea == 0)
	{
		printf("Error\nMissing or duplicate cardinal texture\n");
		free_all(cube);
		exit (1);
	}
}

void	check_colors(t_game *cube)
{
	int i;
	int count_f;
	int count_c;

	i = 0;
	count_f = 0;
	count_c = 0;
	while (cube->map[i] != NULL)
	{
		if (ft_strncmp(cube->map[i], "F ", 2) == 0)
			count_f++;
		else if (ft_strncmp(cube->map[i], "C ", 2) == 0)
			count_c++;
		i++;
	}
	if (count_f != 1 || count_c != 1)
	{
		printf("Error\nMissing or duplicate colors\n");
		free_all(cube);
		exit (1);
	}
}

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

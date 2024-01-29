#include "cube.h"

// check if the numbers of player is valid
void	check_nplayer(t_game *cube)
{
	int i;
	int j;
	int count;

	j = 0;
	count = 0;
	while (cube->map[j])
	{
		i = 0;
		while (cube->map[j][i])
		{
			if (ft_strchr("NWSE", cube->map[j][i]))
				count++;
			i++;
		}
		j++;
	}
	if (count != 1)
		free_err(cube, "Error\nInvalid number of players\n");
}

void	check_inner_map(t_game *cube)
{
	int x;
	int y;

	y = 0;
	while (cube->map[y])
	{
		x = 0;
		while (cube->map[y][x])
		{
			if (ft_strchr("N0WSE", cube->map[y][x]))
			{
				if (cube->map[y - 1][x] == 32 || cube->map[y + 1][x] == 32
					|| cube->map[y][x - 1] == 32 || cube->map[y][x + 1] == 32)
					free_err(cube, "Error\nthe map is not enclosed by 1s!\n");
				else if (cube->map[y - 1][x] == 10 || cube->map[y + 1][x] == 10
					|| cube->map[y][x + 1] == 10 || cube->map[y][x - 1] == 10)
					free_err(cube, "Error\nthe map is not enclosed by 1s!\n");
			}
			x++;
		}
		y++;
	}
}

// check first and last line of the map
void check_flmap(t_game *cube)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (cube->map[y][x])
	{
		if (ft_strchr("0NWSE", cube->map[y][x]))
			free_err(cube, "Error\ngeneral error on first line\n");
		x++;
	}

	y = cube->map_height - 1;
	x = 0;
	while (cube->map[y][x])
	{
		if (ft_strchr("0NWSE", cube->map[y][x]))
			free_err(cube, "Error\ngeneral error on last line\n");
		x++;
	}
}

void	check_edges(t_game *cube)
{
	int y;
	int first_x;
	int last_x;

	y = 0;
	while (cube->map[y])
	{
		first_x = 0;
		last_x = ft_strlen(cube->map[y]) - 1;

		if (ft_strchr("0NSWE", cube->map[y][first_x]))
			free_err(cube, "Error\nInvalid character at the start of a line\n");

		if (ft_strchr("0NSWE", cube->map[y][last_x]))
			free_err(cube, "Error\nInvalid character at the end of a line\n");

		y++;
	}
}

// check if there is any invalid symbols in the map
void	check_symbols(t_game *cube)
{
	int i;
	int j;

	i = 0;
	while (cube->map[i])
	{
		j = 0;
		while (cube->map[i][j])
		{
			if (!ft_strchr("10NSEW \n", cube->map[i][j]))
				free_err(cube, "Error\nWrong symbols in the map\n");
			j++;
		}
		i++;
	}
}

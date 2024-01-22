#include "cube.h"

// check if the file is a .cub file
void is_cube(char *argv)
{
	int len;

	len = ft_strlen(argv);
	if (len < 5)
	{
		write(2, "Error\nInvalid file extension\n", 30);
		exit(1);
	}
	if (ft_strncmp(argv + len - 4, ".cub", 4) != 0)
	{
		write(2, "Error\nInvalid file extension\n", 30);
		exit(1);
	}
}

// check if the numbers of player is valid
void check_player(t_game *cube)
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

// check if the map is surrounded by walls
void check_map(t_game *cube)
{
	int x;
	int y;

	y = 0;
	while (cube->map[y])
	{
		x = 0;
		while (cube->map[y][x])
		{
			if (ft_strchr("0NWSE", cube->map[y][x]))
			{
				if ((cube->map[y][x] == '0') && (cube->map[y - 1][x] == 0
					|| cube->map[y + 1][x] == 0))
					free_err(cube, "Error\nnot surrounded by wall\n");
				if (((cube->map[y - 1][x] == 32 || cube->map[y + 1][x] == 32
					|| cube->map[y][x - 1] == 32 || cube->map[y][x + 1] == 32))
					|| ((cube->map[y][x + 1] == '\n' || 
					cube->map[y][x - 1] == '\n' || cube->map[y + 1][x] == '\n'
					|| cube->map[y - 1][x] == '\n')))
					free_err(cube, "Error\nnot surrounded by wall\n");
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
		if (cube->map[y][x] == '0')
			free_err(cube, "Error\nnot surrounded by wall\n");
		x++;
	}
	y = cube->map_height - 1;
	x = 0;
	while (cube->map[y][x])
	{
		if (cube->map[y][x] == '0')
			free_err(cube, "Error\nnot surrounded by wall\n");
		x++;
	}
}

// check if there is any invalid symbols in the map
void check_symbols(t_game *cube)
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

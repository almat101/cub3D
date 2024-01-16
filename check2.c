#include "cube.h"

void	is_cube(char *argv)
{
	int len;

	len = ft_strlen(argv);
	if (len < 5)
	{
		printf("Error\nInvalid file extension\n");
		exit (1);
	}
	if (ft_strncmp(argv + len - 4, ".cub", 4) != 0)
	{
		printf("Error\nInvalid file extension\n");
		exit (1);
	}
}

void	check_player(t_game *cube)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (cube->real_map[j])
	{
		i = 0;
		while (cube->real_map[j][i])
		{
			if (ft_strchr("NWSE", cube->real_map[j][i]))
				count++;
			i++;
		}
		j++;
	}
	if (count != 1)
	free_err(cube, "Error\nInvalid number of players\n");
}

// void	check_map(t_game *cube)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (cube->real_map[y])
// 	{
// 		x = 0;
// 		while (cube->real_map[y][x])
// 		{
// 			if (ft_strchr("0NWSE", cube->real_map[y][x]))
// 			{
// 				if (cube->real_map[y - 1][x] == 32 || cube->real_map[y + 1][x] == 32
// 					|| cube->real_map[y][x - 1] == 32
// 					|| cube->real_map[y][x + 1] == 32 )
// 					free_err(cube, "Error\nnot surrounded by wall\n");
// 				else if (cube->real_map[y][x + 1] == '\n' || cube->real_map[y][x - 1] == '\n'
// 					|| cube->real_map[y + 1][x] == '\n' || cube->real_map[y - 1][x] == '\n')
// 					free_err(cube, "Error\nnot surrounded by wall\n");
// 				else if (cube->real_map[y][x] == '0' && cube->real_map[y + 1 ][x] == '1' &&
// 				 (cube->real_map[y + 1][x + 1] == '\n' || cube->real_map[y + 1][x - 1] == 32))
// 					free_err(cube, "Error\n");

// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	check_map(t_game *cube)
{
	int	x;
	int	y;

	y = 0;
	while (cube->real_map[y])
	{
		x = 0;
		while (cube->real_map[y][x])
		{
			if (ft_strchr("0NWSE", cube->real_map[y][x]))
			{
				if ((cube->real_map[y - 1][x] == 32 || cube->real_map[y + 1][x] == 32
					|| cube->real_map[y][x - 1] == 32 || cube->real_map[y][x + 1] == 32 )
					|| (cube->real_map[y][x + 1] == '\n' || cube->real_map[y][x - 1] == '\n'
					|| cube->real_map[y + 1][x] == '\n' || cube->real_map[y - 1][x] == '\n')
					|| (cube->real_map[y][x] == '0' && cube->real_map[y + 1 ][x] == '1'
					&& (cube->real_map[y + 1][x + 1] == '\n' || cube->real_map[y + 1][x - 1] == 32)))
					free_err(cube, "Error\n");
			}
			x++;
		}
		y++;
	}
}

//check first and last line of the real_map
void	check_flmap(t_game *cube)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (cube->real_map[y][x])
	{
		if (cube->real_map[y][x] == '0')
			free_err(cube, "Error\nnot surrounded by wall\n");
		x++;
	}
	y = cube->map_height - 1;
	x = 0;
	while (cube->real_map[y][x])
	{
		if (cube->real_map[y][x] == '0')
			free_err(cube, "Error\nnot surrounded by wall\n");
		x++;
	}
}

// void	check_map(t_game *cube)
// {
//     int	x;
//     int	y;

//     y = 0;
//     while (cube->real_map[y])
//     {
//         x = 0;
//         while (cube->real_map[y][x])
//         {
//             if (ft_strchr("0NWSE", cube->real_map[y][x]))
//             {
// 				printf("cube->real_map[%d][%d] = %c\n",y,x, cube->real_map[y][x]);
//                 if ((y > 0 && cube->real_map[y - 1][x] == 32) ||
//                     (cube->real_map[y + 1] && cube->real_map[y + 1][x] == 32) ||
//                     (x > 0 && cube->real_map[y][x - 1] == 32) ||
//                     (cube->real_map[y][x + 1] && cube->real_map[y][x + 1] == 32))
// 					printf("if y = %d, x = %d\n", y, x);
// 					//free_err(cube, "Error\nnot surrounded by wall\n");
//                 else if ((y == 0 || x == 0 || !cube->real_map[y + 1] || !cube->real_map[y][x + 1]))
//                     printf("else if y = %d, x = %d\n", y, x);
// 					//free_err(cube, "Error\nnot surrounded by wall\n");
//             }
//             x++;
//         }
//         y++;
//     }
// }

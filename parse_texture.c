#include "cube.h"

// check if the file has .xpm extension
int	has_xpm_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return 0;
	if (ft_strncmp(filename + len - 5, ".xpm", 4) == 0)
		return (1);
	return (0);
}

// assign the texture path to the corresponding variable
void	assign(t_game *cube, char **dest, const char *src, int *flag)
{
	if (*flag == 1)
	{
		printf("Error\nDuplicate cardinal texture\n");
		free_all(cube);
		exit(1);
	}
	else if (*flag == 0)
	{
		if (!has_xpm_extension(src))
		{

			printf("Error\nInvalid texture file extension\n");
			free_all(cube);
			exit(1);
		}
		*dest = ft_strdup(src);
		*flag = 1;
	}
}

// extract the texture path from the map
void extract_texture(t_game *cube)
{
	int i;

	i = 0;
	while (cube->map[i] != NULL)
	{
		if (ft_strncmp(cube->map[i], "NO ", 3) == 0)
			assign(cube, &cube->cards->no, cube->map[i] + 3, &cube->cards->f_no);
		else if (ft_strncmp(cube->map[i], "SO ", 3) == 0)
			assign(cube, &cube->cards->so, cube->map[i] + 3, &cube->cards->f_so);
		else if (ft_strncmp(cube->map[i], "WE ", 3) == 0)
			assign(cube, &cube->cards->we, cube->map[i] + 3, &cube->cards->f_we);
		else if (ft_strncmp(cube->map[i], "EA ", 3) == 0)
			assign(cube, &cube->cards->ea, cube->map[i] + 3, &cube->cards->f_ea);
		i++;
	}
	if (cube->cards->f_no == 0 || cube->cards->f_so == 0
		|| cube->cards->f_we == 0 || cube->cards->f_ea == 0)
	{
		printf("Error\nMissing cardinal texture\n");
		free_all(cube);
		exit (1);
	}
}

void	print_texture_value(t_game *cube)
{
	printf("%s", cube->cards->no);
	printf("%s", cube->cards->so);
	printf("%s", cube->cards->we);
	printf("%s", cube->cards->ea);
}


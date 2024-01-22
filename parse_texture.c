#include "cube.h"

// check if the file has .xpm extension
int	has_xpm_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return 0;
	if (ft_strncmp(filename + len - 4, ".xpm", 4) == 0)
		return (1);
	return (0);
}

int is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}
char	*trim_whitespace(char *str)
{
	char	*end;

	// Trim leading space
	while(is_space((unsigned char)*str))
		str++;

	if(*str == 0)  // All spaces?
		return str;

	// Trim trailing space
	end = str + ft_strlen(str) - 1;
	while(end > str && is_space((unsigned char)*end))
		end--;

	// Write new null terminator character
	end[1] = '\0';

	return str;
}
// assign the texture path to the corresponding variable
void	assign(t_game *cube, char **dest, char *src, int *flag)
{
	//int src_len;

	src = trim_whitespace(src);
	//src_len = ft_strlen(src) - 1;
	if (*flag == 1)
	{
		printf("Error\nDuplicate cardinal texture\n");
		free_all2(cube);
		exit(1);
	}
	else if (*flag == 0)
	{
		if (!has_xpm_extension(src))
		{

			printf("Error\nInvalid texture file extension\n");
			free_all2(cube);
			exit(1);
		}
		*dest = ft_strdup(src);
		*flag = 1;
	}
}

// extract the texture path from the map and check if it is valid
void extract_texture(t_game *cube)
{
	int i;

	i = 0;
	while (cube->map[i] != NULL)
	{
		if (ft_strncmp(cube->map[i], "NO ", 3) == 0)
			assign(cube, &cube->card->no, cube->map[i] + 3, &cube->card->n);
		else if (ft_strncmp(cube->map[i], "SO ", 3) == 0)
			assign(cube, &cube->card->so, cube->map[i] + 3, &cube->card->s);
		else if (ft_strncmp(cube->map[i], "WE ", 3) == 0)
			assign(cube, &cube->card->we, cube->map[i] + 3, &cube->card->w);
		else if (ft_strncmp(cube->map[i], "EA ", 3) == 0)
			assign(cube, &cube->card->ea, cube->map[i] + 3, &cube->card->e);
		i++;
	}
	if (cube->card->n == 0 || cube->card->s == 0
		|| cube->card->w == 0 || cube->card->e == 0)
	{
		printf("Error\nMissing cardinal texture\n");
		free_all2(cube);
		exit (1);
	}
}




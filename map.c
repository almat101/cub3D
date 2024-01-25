#include "cube.h"

void add_to_real_map(char *line, t_game *cube)
{
	int		old_size;
	char	**new_real_map;
	int		new_size;

	if (!line)
		free_err(cube,"Error\nEmpty line in map\n");
	old_size = 0;
	while (cube->map && cube->map[old_size] != NULL)
		old_size++;
	new_size = old_size + 1;
	new_real_map = ft_realloc(cube->map, (old_size + 1) * sizeof(char *),
	 (new_size + 1) * sizeof(char *));
	if (new_real_map == NULL)
	{
		printf("Error\nFailed to allocate memory for real map\n");
		exit(1);
	}
	cube->map = new_real_map;
	cube->map[old_size] = ft_strdup(line);
	if (cube->map[old_size] == NULL)
	{
		printf("Error\nFailed to allocate memory for real map line\n");
		exit(1);
	}
	cube->map[new_size] = NULL;
}


void	extract_real_map(t_game *cube)
{
	int		i;

	i = 0;
	while (cube->info[i] != NULL)
	{
		if (ft_strncmp(cube->info[i], "NO ", 3) == 0 ||
			ft_strncmp(cube->info[i], "SO ", 3) == 0 ||
			ft_strncmp(cube->info[i], "WE ", 3) == 0 ||
			ft_strncmp(cube->info[i], "EA ", 3) == 0 ||
			ft_strncmp(cube->info[i], "F ", 2) == 0 ||
			ft_strncmp(cube->info[i], "C ", 2) == 0 ||
			ft_strncmp(cube->info[i], "\n", 1) == 0)
		{
			i++;
			continue ;
		}
		add_to_real_map(cube->info[i], cube);
		i++;
	}
	cube->map_height = ft_strlen_row(cube->map);
}

// void	check_real_map(t_game *cube)
// {
// 	int		i;
// 	int		is_map;

// 	is_map = 0;
// 	i = 0;
// 	while (cube->info[i] != NULL)
// 	{
// 		if (ft_strncmp(cube->info[i], "NO ", 3) == 0 ||
// 			ft_strncmp(cube->info[i], "SO ", 3) == 0 ||
// 			ft_strncmp(cube->info[i], "WE ", 3) == 0 ||
// 			ft_strncmp(cube->info[i], "EA ", 3) == 0 ||
// 			ft_strncmp(cube->info[i], "F ", 2) == 0 ||
// 			ft_strncmp(cube->info[i], "C ", 2) == 0 ||
// 			ft_strncmp(cube->info[i] , "\n", 1) == 0)
// 		{
// 			i++;
// 			if (is_map && ft_strncmp(cube->info[i - 1], "\n", 1) == 0)
// 			{
// 				while (cube->info[i] != NULL && ft_strncmp(cube->info[i], "\n", 1) == 0)
// 					i++;
// 				if (cube->info[i] != NULL)
// 					free_err(cube, "Error\nEmpty line in map\n");
// 			}
// 			if (cube->info[i] == NULL && !is_map)
// 				free_err(cube, "Error\nNo Map after texture and colors\n");
// 			continue ;
// 		}
// 		is_map = 1;
// 		i++;
// 	}
// }

void check_empty_line_in_map(t_game *cube, int *i, int is_map)
{
	if (is_map && ft_strncmp(cube->info[*i - 1], "\n", 1) == 0)
	{
		while (cube->info[*i] != NULL
			&& ft_strncmp(cube->info[*i], "\n", 1) == 0)
			(*i)++;
		if (cube->info[*i] != NULL)
			free_err(cube, "Error\nEmpty line in map\n");
	}
}

void check_real_map(t_game *cube)
{
	int i;
	int is_map;

	is_map = 0;
	i = 0;
	while (cube->info[i] != NULL)
	{
		if (ft_strncmp(cube->info[i], "NO ", 3) == 0 ||
			ft_strncmp(cube->info[i], "SO ", 3) == 0 ||
			ft_strncmp(cube->info[i], "WE ", 3) == 0 ||
			ft_strncmp(cube->info[i], "EA ", 3) == 0 ||
			ft_strncmp(cube->info[i], "F ", 2) == 0 ||
			ft_strncmp(cube->info[i], "C ", 2) == 0 ||
			ft_strncmp(cube->info[i] , "\n", 1) == 0)
		{
			i++;
			check_empty_line_in_map(cube, &i, is_map);
			if (cube->info[i] == NULL && !is_map)
				free_err(cube, "Error\nNo Map after texture and colors\n");
			continue ;
		}
		is_map = 1;
		i++;
	}
}

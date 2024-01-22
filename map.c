#include "cube.h"

// // todo extract real map

// // t_list *read_file_map(int fd)
// // {
// // 	char	*line;
// // 	t_list	*new;
// // 	t_list	*lst;
// // 	int		map_started;
// // 	int		map_ended;

// // 	lst = NULL;
// // 	map_started = 0;
// // 	map_ended = 0;
// // 	while ((line = get_next_line(fd)) != NULL)
// // 	{
// // 		if (ft_strncmp(line, "NO ", 3) == 0 ||
// // 			ft_strncmp(line, "SO ", 3) == 0 ||
// // 			ft_strncmp(line, "WE ", 3) == 0 ||
// // 			ft_strncmp(line, "EA ", 3) == 0 ||
// // 			ft_strncmp(line, "F ", 2) == 0 ||
// // 			ft_strncmp(line, "C ", 2) == 0)
// // 		{
// // 			free(line);
// // 			continue;
// // 		}
// // 		else if (ft_strncmp(line, "\n", 1) == 0)
// // 		{
// // 			if (map_started)
// // 			{
// // 				map_ended = 1;
// // 			}
// // 			free(line);
// // 			continue;
// // 		}
// // 		else
// // 		{
// // 			if (map_ended)
// // 			{
// // 				printf("Error\nNewline found in the map\n");
// // 				exit (1);
// // 			}
// // 			map_started = 1;
// // 		}

// // 		new = ft_lstnew(line);
// // 		if (new == NULL)
// // 		{
// // 			printf("Error\nFailed to allocate memory for line\n");
// // 			exit (1);
// // 		}
// // 		ft_lstadd_back(&lst, new);
// // 	}
// // 	return (lst);
// // }


// // void copy_real_map(t_list *lst, t_game *cube)
// // {
// // 		int i;
// // 		t_list *new;
// // 		int line_count;

// // 		i = 0;
// // 		new = lst;
// // 		line_count = count_lines(lst);
// // 		cube->map = malloc(sizeof(char*) * (line_count + 1));
// // 		if (cube->map == NULL)
// // 		{
// // 			printf("Error\nFailed to allocate memory for map\n");
// // 			exit (1);
// // 		}
// // 		while (new != NULL)
// // 		{
// // 			cube->map[i] = new->content;
// // 			i++;
// // 			new = new->next;
// // 		}
// // 		cube->map[i] = NULL; // end the map with a NULL pointer
// // }

// // void	extract_map(char **argv, t_game *cube)
// // {
// // 	int		fd;
// // 	t_list	*lst;

// // 	fd = open(argv[1], O_RDONLY);
// // 	if (fd == -1)
// // 	{
// // 		printf("Error\nFailed to open file\n");
// // 		exit (1);
// // 	}
// // 	lst = read_file_map(fd);
// // 	close(fd);
// // 	copy_real_map(lst, cube);
// // 	free_list(lst);
// // }

// //refactor

// void copy_real_map(t_list *lst, t_game *cube)
// {
// 	int		i;
// 	t_list	*new;
// 	int		line_count;

// 	i = 0;
// 	new = lst;
// 	line_count = count_lines(lst);
// 	cube->map = malloc(sizeof(char*) * (line_count + 1));
// 	if (cube->map == NULL)
// 	{
// 		printf("Error\nFailed to allocate memory for map\n");
// 		exit (1);
// 	}
// 	while (new != NULL)
// 	{
// 		cube->map[i] = new->content;
// 		i++;
// 		new = new->next;
// 	}
// 	cube->map[i] = NULL;
// }

// int	is_texture_or_color(char *line)
// {
// 	return (ft_strncmp(line, "NO ", 3) == 0 ||
// 		ft_strncmp(line, "SO ", 3) == 0 ||
// 		ft_strncmp(line, "WE ", 3) == 0 ||
// 		ft_strncmp(line, "EA ", 3) == 0 ||
// 		ft_strncmp(line, "F ", 2) == 0 ||
// 		ft_strncmp(line, "C ", 2) == 0 ||
// 		ft_strncmp(line, "\n", 1) == 0);
// }

// // void	handle_texture_or_color_line(char **line)
// // {
// // 	if (is_texture_or_color(*line))
// // 	{
// // 		free(*line); // Don't forget to free the line
// // 		*line = NULL;
// // 	}
// // }

// // void	handle_newline(char **line, int *map_started, int *map_ended)
// // {
// // 	if (*line && ft_strncmp(*line, "\n", 1) == 0)
// // 	{
// // 		if (*map_started)
// // 			*map_ended = 1;
// // 		free(*line); // Don't forget to free the line
// // 		*line = NULL;
// // 	}
// // }



// // void	handle_map_line(char **line, t_list **lst, int *map_started, int *map_ended)
// // {
// // 	(void)lst;
// // 	if (*line)
// // 	{
// // 		if (*map_ended)
// // 		{
// // 			printf("Error\nNewline found in the map\n");
// // 			free(*line);
// // 			free_list(*lst);
// // 			exit (1);
// // 		}
// // 		*map_started = 1;
// // 	}

// // }

// // void	handle_line(char **line, t_list **lst, int *map_started, int *map_ended)
// // {
// // 	t_list	*new;
// // 	(void)map_started;
// // 	(void)map_ended;
// // 	handle_texture_or_color_line(line);
// // 	//handle_newline(line, map_started, map_ended);
// // 	//handle_map_line(line, lst, map_started, map_ended);
// // 	if (*line)
// // 	{
// // 		printf("line: %s", *line);
// // 		new = ft_lstnew(*line);
// // 		if (new == NULL)
// // 		{
// // 			printf("Error\nFailed to allocate memory for line\n");
// // 			exit (1);
// // 		}
// // 		ft_lstadd_back(lst, new);
// // 	}
// // }

// // void	read_file_map(int fd, t_game *cube)
// // {
// // 	char	*line;
// // 	t_list	*lst;
// // 	// int		map_started;
// // 	// int		map_ended;

// // 	lst = NULL;
// // 	// map_started = 0;
// // 	// map_ended = 0;
// // 	while ((line = get_next_line(fd)) != NULL)
// // 	{
// // 		if (ft_strncmp(line, "NO ", 3) == 0 ||
// // 			ft_strncmp(line, "SO ", 3) == 0 ||
// // 			ft_strncmp(line, "WE ", 3) == 0 ||
// // 			ft_strncmp(line, "EA ", 3) == 0 ||
// // 			ft_strncmp(line, "F ", 2) == 0 ||
// // 			ft_strncmp(line, "C ", 2) == 0 ||
// // 			ft_strncmp(line, "\n", 1) == 0)
// // 		{
// // 			free(line);
// // 			continue;
// // 		}
// // 		else
// // 		{
// // 			copy_real_map(lst, cube);
// // 			// if (map_ended)
// // 			// {
// // 			// 	printf("Error\nNewline found in the map\n");
// // 			// 	exit (1);
// // 			// }
// // 			// map_started = 1;
// // 		}
// // 		// handle_line(&line, &lst, &map_started, &map_ended);
// // 		// if (line != NULL)
// // 		// {
// // 		// 	free(line);
// // 		// 	//line = NULL;
// // 		// }
// // 		//printf("line after handle line: %s", line);
// // 	}

// // 	free_list(lst);
// // }

// t_list *read_file_map(int fd)
// {
// 	char	*line;
// 	t_list	*new;
// 	t_list	*lst;

// 	lst = NULL;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		if (ft_strncmp(line, "NO ", 3) == 0 ||
// 			ft_strncmp(line, "SO ", 3) == 0 ||
// 			ft_strncmp(line, "WE ", 3) == 0 ||
// 			ft_strncmp(line, "EA ", 3) == 0 ||
// 			ft_strncmp(line, "F ", 2) == 0 ||
// 			ft_strncmp(line, "C ", 2) == 0 ||
// 			ft_strncmp(line, "\n", 1) == 0)
// 		{
// 			printf("line in real file map: %s", line);
// 			free(line);
// 			continue;
// 		}
// 		else
// 		{
// 			new = ft_lstnew(line);
// 			if (new == NULL)
// 			{
// 				printf("Error\nFailed to allocate memory for line\n");
// 				exit (1);
// 			}
// 			ft_lstadd_back(&lst, new);
// 		}
// 	}
// 	return (lst);
// }

// void	extract_real_map(char **argv, t_game *cube)
// {
// 	int		fd;
// 	t_list	*lst;

// 	lst = NULL;
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error\nFailed to open file\n");
// 		exit (1);
// 	}
// 	lst = read_file_map(fd);
// 	copy_real_map(lst, cube);
// 	free_list(lst);
// 	close(fd);
// }

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
			// if (cube->info[i] == NULL)
			// 	free_err(cube, "Error\nno Map\n");
			continue ;
		}
		add_to_real_map(cube->info[i], cube);
		i++;
	}
	cube->map_height = ft_strlen_row(cube->map);
}


void	check_real_map(t_game *cube)
{
	int		i;
	int		is_map;

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
			ft_strncmp(cube->info[i], "\n", 1) == 0)
		{
			i++;
			if (cube->info[i] == NULL && !is_map)
				free_err(cube, "Error\nNo Map after texture and colors\n");
			continue ;
		}
		is_map = 1;
		i++;
	}
}

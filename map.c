#include "cube.h"

// todo extract real map

// t_list *read_file_map(int fd)
// {
// 	char	*line;
// 	t_list	*new;
// 	t_list	*lst;
// 	int		map_started;
// 	int		map_ended;

// 	lst = NULL;
// 	map_started = 0;
// 	map_ended = 0;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		if (ft_strncmp(line, "NO ", 3) == 0 ||
// 			ft_strncmp(line, "SO ", 3) == 0 ||
// 			ft_strncmp(line, "WE ", 3) == 0 ||
// 			ft_strncmp(line, "EA ", 3) == 0 ||
// 			ft_strncmp(line, "F ", 2) == 0 ||
// 			ft_strncmp(line, "C ", 2) == 0)
// 		{
// 			free(line);
// 			continue;
// 		}
// 		else if (ft_strncmp(line, "\n", 1) == 0)
// 		{
// 			if (map_started)
// 			{
// 				map_ended = 1;
// 			}
// 			free(line);
// 			continue;
// 		}
// 		else
// 		{
// 			if (map_ended)
// 			{
// 				printf("Error\nNewline found in the map\n");
// 				exit (1);
// 			}
// 			map_started = 1;
// 		}

// 		new = ft_lstnew(line);
// 		if (new == NULL)
// 		{
// 			printf("Error\nFailed to allocate memory for line\n");
// 			exit (1);
// 		}
// 		ft_lstadd_back(&lst, new);
// 	}
// 	return (lst);
// }


// void copy_real_map(t_list *lst, t_game *cube)
// {
// 		int i;
// 		t_list *new;
// 		int line_count;

// 		i = 0;
// 		new = lst;
// 		line_count = count_lines(lst);
// 		cube->real_map = malloc(sizeof(char*) * (line_count + 1));
// 		if (cube->real_map == NULL)
// 		{
// 			printf("Error\nFailed to allocate memory for map\n");
// 			exit (1);
// 		}
// 		while (new != NULL)
// 		{
// 			cube->real_map[i] = new->content;
// 			i++;
// 			new = new->next;
// 		}
// 		cube->real_map[i] = NULL; // end the map with a NULL pointer
// }

// void	extract_map(char **argv, t_game *cube)
// {
// 	int		fd;
// 	t_list	*lst;

// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error\nFailed to open file\n");
// 		exit (1);
// 	}
// 	lst = read_file_map(fd);
// 	close(fd);
// 	copy_real_map(lst, cube);
// 	free_list(lst);
// }

//refactor

void copy_real_map(t_list *lst, t_game *cube)
{
	int		i;
	t_list	*new;
	int		line_count;

	i = 0;
	new = lst;
	line_count = count_lines(lst);
	cube->real_map = malloc(sizeof(char*) * (line_count + 1));
	if (cube->real_map == NULL)
	{
		printf("Error\nFailed to allocate memory for map\n");
		exit (1);
	}
	while (new != NULL)
	{
		cube->real_map[i] = new->content;
		i++;
		new = new->next;
	}
	cube->real_map[i] = NULL;
}

int	is_texture_or_color(char *line)
{
	return (ft_strncmp(line, "NO ", 3) == 0 ||
		ft_strncmp(line, "SO ", 3) == 0 ||
		ft_strncmp(line, "WE ", 3) == 0 ||
		ft_strncmp(line, "EA ", 3) == 0 ||
		ft_strncmp(line, "F ", 2) == 0 ||
		ft_strncmp(line, "C ", 2) == 0);
}

void	handle_texture_or_color_line(char **line)
{
	if (is_texture_or_color(*line))
	{
		free(*line); // Don't forget to free the line
		*line = NULL;
	}
}

void	handle_newline(char **line, int *map_started, int *map_ended)
{
	if (*line && ft_strncmp(*line, "\n", 1) == 0)
	{
		if (*map_started)
			*map_ended = 1;
		free(*line); // Don't forget to free the line
		*line = NULL;
	}
}



void	handle_map_line(char **line, t_list **lst, int *map_started, int *map_ended)
{
	if (*line)
	{
		if (*map_ended)
		{
			printf("Error\nNewline found in the map\n");
			free(*line);
			free_list(*lst);
			exit (1);
		}
		*map_started = 1;
	}

}

void	handle_line(char **line, t_list **lst, int *map_started, int *map_ended)
{
	t_list	*new;


	handle_texture_or_color_line(line);
	handle_newline(line, map_started, map_ended);
	handle_map_line(line, lst, map_started, map_ended);
	if (*line)
	{
		new = ft_lstnew(*line);
		if (new == NULL)
		{
			printf("Error\nFailed to allocate memory for line\n");
			exit (1);
		}
		ft_lstadd_back(lst, new);
	}
}

void	read_file_map(int fd, t_game *cube)
{
	char	*line;
	t_list	*lst;
	int		map_started;
	int		map_ended;

	lst = NULL;
	map_started = 0;
	map_ended = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		handle_line(&line, &lst, &map_started, &map_ended);
		// if (line != NULL)
		// {
		// 	free(line);
		// 	//line = NULL;
		// }
		//printf("line after handle line: %s", line);
	}
	copy_real_map(lst, cube);
	free_list(lst);
}

void	extract_map(char **argv, t_game *cube)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nFailed to open file\n");
		exit (1);
	}
	read_file_map(fd,cube);
	close(fd);
}

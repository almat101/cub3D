#include "cube.h"

t_list *read_file(int fd)
{
	char *line;
	t_list *new;
	t_list *lst;

	lst = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		new = ft_lstnew(line);
		if (new == NULL)
		{
			printf("Error\nFailed to allocate memory for line\n");
			exit (1);
		}
		ft_lstadd_back(&lst, new);
	}
	return (lst);
}

void check_empty_file(t_list *lst)
{
	if (lst == NULL)
	{
		printf("Error\nEmpty map\n");
		exit (1);
	}
}

int count_lines(t_list *lst)
{
    int i = 0;
    t_list *new = lst;
    while (new != NULL)
    {
        i++;
        new = new->next;
    }
    return i;
}

void convert_list_to_array(t_list *lst, t_game *cube)
{
		int i;
		t_list *new;
		int line_count;

		i = 0;
		new = lst;
		line_count = count_lines(lst);
		cube->map = malloc(sizeof(char*) * (line_count + 1));
		if (cube->map == NULL)
		{
			printf("Error\nFailed to allocate memory for map\n");
			exit (1);
		}

		while (new != NULL)
		{
			cube->map[i] = new->content;
			i++;
			new = new->next;
		}
		cube->map[i] = NULL; // end the map with a NULL pointer
}


void	parse_map(char **argv, t_game *cube)
{
	int		fd;
	t_list	*lst;

	fd = open(argv[1], O_RDONLY);
	lst = read_file(fd);
	close(fd);
	check_empty_file(lst);
	convert_list_to_array(lst, cube);
	free_list(lst);
}




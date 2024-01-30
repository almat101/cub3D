/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:29:59 by amatta            #+#    #+#             */
/*   Updated: 2024/01/30 14:16:00 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_list	*read_file(int fd)
{
	char	*line;
	t_list	*new;
	t_list	*lst;

	lst = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		new = ft_lstnew(line);
		if (new == NULL)
		{
			printf("Error\nFailed to allocate memory for line\n");
			exit (1);
		}
		ft_lstadd_back(&lst, new);
		line = get_next_line(fd);
	}
	return (lst);
}

void	check_empty_file(t_list *lst, t_game *cube)
{
	if (lst == NULL)
	{
		printf("Error\nEmpty map\n");
		free_all2(cube);
		exit (1);
	}
}

int	count_lines(t_list *lst)
{
	int		i;
	t_list	*new;

	i = 0;
	new = lst;
	while (new != NULL)
	{
		i++;
		new = new->next;
	}
	return (i);
}

void	copy_all_map(t_list *lst, t_game *cube)
{
	int		i;
	t_list	*new;
	int		line_count;

	i = 0;
	new = lst;
	line_count = count_lines(lst);
	cube->info = malloc(sizeof(char *) * (line_count + 1));
	if (cube->info == NULL)
	{
		printf("Error\nFailed to allocate memory for map\n");
		exit (1);
	}
	while (new != NULL)
	{
		cube->info[i] = new->content;
		i++;
		new = new->next;
	}
	cube->info[i] = NULL;
}

void	parse_info(char **argv, t_game *cube)
{
	int		fd;
	t_list	*lst;

	fd = open(argv[1], O_RDONLY);
	lst = read_file(fd);
	close(fd);
	check_empty_file(lst, cube);
	copy_all_map(lst, cube);
	free_list(lst);
}

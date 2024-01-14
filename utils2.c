#include "cube.h"

void	free_texture(t_game *cube)
{
	if ((cube->cards->no) != NULL)
		free(cube->cards->no);
	if ((cube->cards->so) != NULL)
		free(cube->cards->so);
	if ((cube->cards->we) != NULL)
		free(cube->cards->we);
	if ((cube->cards->ea) != NULL)
		free(cube->cards->ea);
}

void	print_map(char **map)
{
	int		i;

	i = 0;
	while (map[i] != NULL)
	{
		printf("%s", map[i]);
		i++;
	}
}

void free_list(t_list *lst)
{
	t_list *tmp;

	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}
void	free_mat(char **mat)
{
	int i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

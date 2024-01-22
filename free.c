#include "cube.h"

void	free_texture(t_game *cube)
{
	if ((cube->card->no) != NULL)
		free(cube->card->no);
	if ((cube->card->so) != NULL)
		free(cube->card->so);
	if ((cube->card->we) != NULL)
		free(cube->card->we);
	if ((cube->card->ea) != NULL)
		free(cube->card->ea);
}

void free_colors(t_game *cube)
{
	if ((cube->colors->floor_color) != NULL)
		free(cube->colors->floor_color);
	if ((cube->colors->ceil_color) != NULL)
		free(cube->colors->ceil_color);
	if ((cube->colors->f_hex_color) != NULL)
		free(cube->colors->f_hex_color);
	if ((cube->colors->c_hex_color) != NULL)
		free(cube->colors->c_hex_color);
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

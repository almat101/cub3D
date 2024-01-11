#include "cube.h"

void	free_map(t_game *cube)
{
	int i;

	i = 0;
	while (cube->map[i] != NULL)
		free(cube->map[i++]);
	free(cube->map);
}

void	free_texture(t_game *cube)
{
	if ((cube->north_texture) != NULL)
		free(cube->north_texture);
	if ((cube->south_texture) != NULL)
		free(cube->south_texture);
	if ((cube->west_texture) != NULL)
		free(cube->west_texture);
	if ((cube->east_texture) != NULL)
		free(cube->east_texture);
	if ((cube->floor_color_rgb) != NULL)
		free(cube->floor_color_rgb);
	if ((cube->ceil_color_rgb) != NULL)
		free(cube->ceil_color_rgb);
}


void	print_all_map(t_game *cube)
{
	int		i;

	i = 0;
	while (cube->map[i] != NULL)
	{
		printf("%s", cube->map[i]);
		i++;
	}
}

void	print_real_map(t_game *cube)
{
	int		i;

	i = 0;
	while (cube->real_map[i] != NULL)
	{
		printf("%s", cube->real_map[i]);
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

int ft_exit(t_game *cube)
{
	free_map(cube);
	free_texture(cube);
	exit(0);
}

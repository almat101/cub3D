#include "cube.h"

void	save_player(t_game *cube)
{
	int	i;
	int	j;

	i = 0;
	while(cube->real_map[i] != NULL)
	{
		j = 0;
		while (cube->real_map[i][j] != '\0')
		{
			if (is_player(cube->real_map[i][j]))
			{
				cube->player->posX = i;
				cube->player->posY = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	printf_player(t_game *cube)
{
	printf("Player position: %f %f\n", cube->player->posX, cube->player->posY);
//	printf("Player direction: %f %f\n", cube->player->dirX, cube->player->dirY);
//	printf("Player plane: %f %f\n", cube->player->planeX, cube->player->planeY);
}


int ft_strlen_row(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
	{
		i++;
	}
	return i;
}

void replace_tabs_in_real_map(char ***real_map, int num_lines)
{
	int		i;
	char	*new_line;

	i = 0;
	while (i < num_lines)
	{
		new_line = replace_tabs_with_spaces((*real_map)[i],num_lines);
		free((*real_map)[i]);
		(*real_map)[i] = new_line;
		i++;
	}
}
int	count_tab(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\t')
			count++;
		else
			i++;
	}
	return (count);
}
char	*replace_tabs_with_spaces(const char *str, int tab_count)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = malloc(ft_strlen(str) + (tab_count * 3) + 1);
	while (str[i] != '\0')
	{
		if (str[i] == '\t')
		{
			new_str[j++] = ' ';
			new_str[j++] = ' ';
			new_str[j++] = ' ';
			new_str[j++] = ' ';
		}
		else
		{
			new_str[j++] = str[i];
		}
		i++;
	}
	new_str[j] = '\0';
	//free(str);
	return new_str;
}

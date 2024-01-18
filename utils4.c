#include "cube.h"

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

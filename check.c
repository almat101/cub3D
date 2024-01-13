#include "cube.h"

void	check_card1(t_game *cube)
{
	int i;
	int count_no;
	int count_so;
	int count_we;

	i = 0;
	count_no = 0;
	count_so = 0;
	count_we = 0;
	while (cube->map[i] != NULL)
	{
		if (ft_strncmp(cube->map[i], "NO ", 3) == 0)
			count_no++;
		else if (ft_strncmp(cube->map[i], "SO ", 3) == 0)
			count_so++;
		else if (ft_strncmp(cube->map[i], "WE ", 3) == 0)
			count_we++;
		i++;
	}
	if (count_no != 1 || count_so != 1 || count_we != 1)
	{
		printf("Error\nMissing or duplicate cardinal\n");
		free_all_map(cube);
		exit (1);
	}
}

void	check_card2(t_game *cube)
{
	int i;
	int count_ea;
	int count_f;
	int count_c;

	i = 0;
	count_ea = 0;
	count_f = 0;
	count_c = 0;
	while (cube->map[i] != NULL)
	{
		if (ft_strncmp(cube->map[i], "EA ", 3) == 0)
			count_ea++;
		else if (ft_strncmp(cube->map[i], "F ", 2) == 0)
			count_f++;
		else if (ft_strncmp(cube->map[i], "C ", 2) == 0)
			count_c++;
		i++;
	}
	if (count_ea != 1 || count_f != 1 || count_c != 1)
	{
		printf("Error\nMissing or duplicate cardinal\n");
		free_all_map(cube);
		exit (1);
	}
}


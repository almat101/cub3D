/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:02:59 by amatta            #+#    #+#             */
/*   Updated: 2024/01/30 13:03:00 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// check if the file has .xpm extension
int	has_xpm_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strncmp(filename + len - 4, ".xpm", 4) == 0)
		return (1);
	return (0);
}

// assign the texture path to the corresponding variable
void	assign(t_game *cube, char **dest, char *src, int *flag)
{
	src = trim_whitespace(src);
	if (*flag == 1)
	{
		printf("Error\nDuplicate cardinal texture\n");
		free_all2(cube);
		exit(1);
	}
	else if (*flag == 0)
	{
		if (!has_xpm_extension(src))
		{
			printf("Error\nInvalid texture file extension\n");
			free_all2(cube);
			exit(1);
		}
		*dest = ft_strdup(src);
		*flag = 1;
	}
}

// extract the texture path from the map and check if it is valid
void	extract_texture(t_game *cube)
{
	int	i;

	i = 0;
	while (cube->info[i] != NULL)
	{
		if (ft_strncmp(cube->info[i], "NO ", 3) == 0)
			assign(cube, &cube->card->no, cube->info[i] + 3, &cube->card->n);
		else if (ft_strncmp(cube->info[i], "SO ", 3) == 0)
			assign(cube, &cube->card->so, cube->info[i] + 3, &cube->card->s);
		else if (ft_strncmp(cube->info[i], "WE ", 3) == 0)
			assign(cube, &cube->card->we, cube->info[i] + 3, &cube->card->w);
		else if (ft_strncmp(cube->info[i], "EA ", 3) == 0)
			assign(cube, &cube->card->ea, cube->info[i] + 3, &cube->card->e);
		i++;
	}
	if (cube->card->n == 0 || cube->card->s == 0
		|| cube->card->w == 0 || cube->card->e == 0)
	{
		printf("Error\nMissing cardinal texture\n");
		free_all2(cube);
		exit (1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:01:38 by amatta            #+#    #+#             */
/*   Updated: 2024/01/30 13:01:39 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// extract color values from the map and put in a string with the assign
void	extract_colors(t_game *cube)
{
	int	i;

	i = 0;
	while (cube->info[i] != NULL)
	{
		if (ft_strncmp(cube->info[i], "F ", 2) == 0)
			assign_colors(cube, &cube->colors->floor_color,
				cube->info[i] + 2, &cube->colors->f_floor);
		else if (ft_strncmp(cube->info[i], "C ", 2) == 0)
			assign_colors(cube, &cube->colors->ceil_color,
				cube->info[i] + 2, &cube->colors->c_ceil);
		i++;
	}
	if (cube->colors->f_floor == 0 || cube->colors->c_ceil == 0)
	{
		free_err(cube, "Error\nInvalid color\n");
		exit(1);
	}
}

// check if the color values are valid and assign them with strdup
void	assign_colors(t_game *cube, char **dest, char *src, int *flag)
{
	src = trim_whitespace(src);
	if (*flag == 1)
	{
		free_err(cube, "Error\nInvalid color\n");
		exit(1);
	}
	else if (*flag == 0)
	{
		*dest = ft_strdup(src);
		*flag = 1;
	}
}

void	ft_rgb_err(t_game *cube, char *line, char **rgb_value)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
		{
			free_err(cube, "Error\nInvalid color\n");
			free_mat(rgb_value);
			exit(1);
		}
		i++;
	}
}

// check if the color values are valid rgb > 0 and < 255
void	check_valid_rgb(t_game *cube, char *line)
{
	char	**rgb_values;
	int		i;
	int		value;

	value = 0;
	i = 0;
	rgb_values = ft_split(line + 2, ',');
	while (rgb_values[i] != NULL)
		i++;
	if (i != 3)
		ft_rgb_err(cube, line, rgb_values);
	while (i-- > 0)
	{
		value = ft_atoi_rgb(rgb_values[i]);
		if (value < 0 || value > 255)
			ft_rgb_err(cube, line, rgb_values);
	}
	free_mat(rgb_values);
}

// check if the color values are valid in form of rgb 3 values
void	check_rgb(t_game *cube)
{
	int	i;

	i = 0;
	while (cube->info[i] != NULL)
	{
		if (ft_strncmp(cube->info[i], "F ", 2) == 0)
			check_valid_rgb(cube, cube->info[i]);
		else if (ft_strncmp(cube->info[i], "C ", 2) == 0)
			check_valid_rgb(cube, cube->info[i]);
		i++;
	}
}

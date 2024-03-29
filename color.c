/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:01:51 by amatta            #+#    #+#             */
/*   Updated: 2024/01/30 13:01:52 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

// convert rgb value to an int hexadecimal value
void	convert_color(t_game *cube, char *line, int is_floor)
{
	char	**rgb_values;
	int		value[3];

	value[0] = 0;
	value[1] = 0;
	value[2] = 0;
	rgb_values = ft_split(line + 2, ',');
	value[0] = ft_atoi_rgb(rgb_values[0]);
	value[1] = ft_atoi_rgb(rgb_values[1]);
	value[2] = ft_atoi_rgb(rgb_values[2]);
	if (is_floor)
		cube->colors->f_floor = ft_rgb(value[0], value[1], value[2]);
	else
		cube->colors->c_ceil = ft_rgb(value[0], value[1], value[2]);
	free_mat(rgb_values);
}

//rgb to hexadecimal
char	*to_hex(int decimal)
{
	int		i;
	int		temp;
	char	*hexa_number;

	i = 7;
	hexa_number = malloc(8 * sizeof(char) + 1);
	while (decimal != 0)
	{
		temp = decimal % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		hexa_number[i--] = temp;
		decimal = decimal / 16;
	}
	hexa_number[0] = '0';
	hexa_number[1] = 'x';
	hexa_number[8] = '\0';
	return (hexa_number);
}

// convert rgb of F and C to a hexadecimal string
void	rgb_to_hex(t_game *cube)
{
	int	i;

	i = 0;
	while (cube->info[i] != NULL)
	{
		if (ft_strncmp(cube->info[i], "F ", 2) == 0)
		{
			convert_color(cube, cube->info[i], 1);
			cube->colors->f_hex_color = to_hex(cube->colors->f_floor);
		}
		else if (ft_strncmp(cube->info[i], "C ", 2) == 0)
		{
			convert_color(cube, cube->info[i], 0);
			cube->colors->c_hex_color = to_hex(cube->colors->c_ceil);
		}
		i++;
	}
}

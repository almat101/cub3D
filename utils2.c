/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:55:47 by amatta            #+#    #+#             */
/*   Updated: 2024/01/30 12:56:00 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	print_map(char **info)
{
	int		i;

	i = 0;
	while (info[i] != NULL)
	{
		printf("%s", info[i]);
		i++;
	}
}

void	print_colors_value(t_game *cube)
{
	printf("floor color int: %d\n", cube->colors->f_floor);
	printf("ceil color int: %d\n", cube->colors->c_ceil);
	printf("floor hexa color: %s\n", cube->colors->f_hex_color);
	printf("ceil hexa color: %s\n", cube->colors->c_hex_color);
}

void	print_texture_value(t_game *cube)
{
	printf("%s\n", cube->card->no);
	printf("%s\n", cube->card->so);
	printf("%s\n", cube->card->we);
	printf("%s\n", cube->card->ea);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:56:14 by amatta            #+#    #+#             */
/*   Updated: 2024/01/30 12:57:07 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	save_player(t_game *cube)
{
	int	i;
	int	j;

	i = 0;
	while (cube->map[i] != NULL)
	{
		j = 0;
		while (cube->map[i][j] != '\0')
		{
			if (is_player(cube->map[i][j]))
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

int	player_exist(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				game->player->posY = i + 0.5;
				game->player->posX = j + 0.5;
				game->player->direction = game->map[i][j];
				game->map[i][j] = '0';
				return (1);
			}
		}
	}
	return (0);
}

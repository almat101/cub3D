/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:02:13 by amatta            #+#    #+#             */
/*   Updated: 2024/01/30 13:02:14 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_all(t_game *cube)
{
	if (cube->info)
		free_mat(cube->info);
	if (cube->map)
		free_mat(cube->map);
	free_texture(cube);
	free_colors(cube);
	free(cube->card);
	free(cube->player);
	free(cube->colors);
	free(cube->img);
	mlx_destroy_window(cube->mlx, cube->mlx_win);
	free(cube->mlx);
	free(cube);
}

void	free_all2(t_game *cube)
{
	if (cube->info)
		free_mat(cube->info);
	if (cube->map)
		free_mat(cube->map);
	free_texture(cube);
	free_colors(cube);
	free(cube->card);
	free(cube->player);
	free(cube->colors);
	free(cube->img);
	free(cube);
}

int	close_window(t_game *cube)
{
	mlx_destroy_image(cube->mlx, cube->card->east_wall.img);
	mlx_destroy_image(cube->mlx, cube->card->west_wall.img);
	mlx_destroy_image(cube->mlx, cube->card->north_wall.img);
	mlx_destroy_image(cube->mlx, cube->card->south_wall.img);
	mlx_destroy_image(cube->mlx, cube->img->img);
	free_all(cube);
	exit(0);
}

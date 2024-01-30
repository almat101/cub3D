/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:51:15 by amatta            #+#    #+#             */
/*   Updated: 2024/01/30 14:43:08 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rotate_to_left(t_game *cube, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->player->dirX;
	cube->player->dirX = cube->player->dirX * cos(-rot_speed)
		- cube->player->dirY * sin(-rot_speed);
	cube->player->dirY = old_dir_x * sin(-rot_speed)
		+ cube->player->dirY * cos(-rot_speed);
	old_plane_x = cube->player->planeX;
	cube->player->planeX = cube->player->planeX * cos(-rot_speed)
		- cube->player->planeY * sin(-rot_speed);
	cube->player->planeY = old_plane_x * sin(-rot_speed)
		+ cube->player->planeY * cos(-rot_speed);
}

void	rotate_to_right(t_game *cube, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->player->dirX;
	cube->player->dirX = cube->player->dirX * cos(rot_speed)
		- cube->player->dirY * sin(rot_speed);
	cube->player->dirY = old_dir_x * sin(rot_speed)
		+ cube->player->dirY * cos(rot_speed);
	old_plane_x = cube->player->planeX;
	cube->player->planeX = cube->player->planeX * cos(rot_speed)
		- cube->player->planeY * sin(rot_speed);
	cube->player->planeY = old_plane_x * sin(rot_speed)
		+ cube->player->planeY * cos(rot_speed);
}

void	update_rotation(t_game *cube)
{
	double	rot_speed;

	rot_speed = cube->frameTime * 3.0;
	if (cube->player->cam_dir == -1)
		rotate_to_right(cube, rot_speed);
	if (cube->player->cam_dir == 1)
		rotate_to_left(cube, rot_speed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:51:15 by amatta            #+#    #+#             */
/*   Updated: 2024/01/30 15:14:59 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rotate_to_left(t_game *cube, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->player->dir_x;
	cube->player->dir_x = cube->player->dir_x * cos(-rot_speed)
		- cube->player->dir_y * sin(-rot_speed);
	cube->player->dir_y = old_dir_x * sin(-rot_speed)
		+ cube->player->dir_y * cos(-rot_speed);
	old_plane_x = cube->player->plane_x;
	cube->player->plane_x = cube->player->plane_x * cos(-rot_speed)
		- cube->player->plane_y * sin(-rot_speed);
	cube->player->plane_y = old_plane_x * sin(-rot_speed)
		+ cube->player->plane_y * cos(-rot_speed);
}

void	rotate_to_right(t_game *cube, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->player->dir_x;
	cube->player->dir_x = cube->player->dir_x * cos(rot_speed)
		- cube->player->dir_y * sin(rot_speed);
	cube->player->dir_y = old_dir_x * sin(rot_speed)
		+ cube->player->dir_y * cos(rot_speed);
	old_plane_x = cube->player->plane_x;
	cube->player->plane_x = cube->player->plane_x * cos(rot_speed)
		- cube->player->plane_y * sin(rot_speed);
	cube->player->plane_y = old_plane_x * sin(rot_speed)
		+ cube->player->plane_y * cos(rot_speed);
}

void	update_rotation(t_game *cube)
{
	double	rot_speed;

	rot_speed = cube->frame_time * 3.0;
	if (cube->player->cam_dir == -1)
		rotate_to_right(cube, rot_speed);
	if (cube->player->cam_dir == 1)
		rotate_to_left(cube, rot_speed);
}

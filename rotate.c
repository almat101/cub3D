/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:51:15 by amatta            #+#    #+#             */
/*   Updated: 2024/01/30 12:54:04 by amatta           ###   ########.fr       */
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

void	rotate_cam(float angle, t_game *cube)
{
	double	new_dir_x;
	double	new_dir_y;
	double	new_plane_x;
	double	new_plane_y;

	angle = angle * M_PI / 180.0f;
	new_dir_x = cube->player->dir_x * cos(angle)
		- cube->player->dir_y * sin(angle);
	new_dir_y = cube->player->dir_x * sin(angle)
		+ cube->player->dir_y * cos(angle);
	new_plane_x = cube->player->plane_x * cos(angle)
		- cube->player->plane_y * sin(angle);
	new_plane_y = cube->player->plane_x * sin(angle)
		+ cube->player->plane_y * cos(angle);
	cube->player->dir_x = new_dir_x;
	cube->player->dir_y = new_dir_y;
	cube->player->plane_x = new_plane_x;
	cube->player->plane_y = new_plane_y;
}

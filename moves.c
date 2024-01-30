/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:02:53 by amatta            #+#    #+#             */
/*   Updated: 2024/01/30 13:02:54 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	move_forward(t_game *cube, double moveSpeed)
{
	if (cube->map[(int)cube->player->pos_y]
		[(int)(cube->player->pos_x + cube->player->dir_x * moveSpeed)] == '0')
		cube->player->pos_x += cube->player->dir_x * moveSpeed;
	if (cube->map[(int)(cube->player->pos_y + cube->player->dir_y * moveSpeed)]
		[(int)(cube->player->pos_x)] == '0')
		cube->player->pos_y += cube->player->dir_y * moveSpeed;
}

void	move_backward(t_game *cube, double moveSpeed)
{
	if (cube->map[(int)cube->player->pos_y]
		[(int)(cube->player->pos_x - cube->player->dir_x * moveSpeed)] == '0')
		cube->player->pos_x -= cube->player->dir_x * moveSpeed;
	if (cube->map[(int)(cube->player->pos_y - cube->player->dir_y * moveSpeed)]
		[(int)cube->player->pos_x] == '0')
		cube->player->pos_y -= cube->player->dir_y * moveSpeed;
}

void	move_right(t_game *cube, double moveSpeed)
{
	if (cube->map[(int)cube->player->pos_y]
		[(int)(cube->player->pos_x - cube->player->dir_y * moveSpeed)] == '0')
		cube->player->pos_x -= cube->player->dir_y * moveSpeed;
	if (cube->map[(int)(cube->player->pos_y + cube->player->dir_x * moveSpeed)]
		[(int)(cube->player->pos_x)] == '0')
		cube->player->pos_y += (cube->player->dir_x) * moveSpeed;
}

void	move_left(t_game *cube, double moveSpeed)
{
	if (cube->map[(int)cube->player->pos_y]
		[(int)(cube->player->pos_x + cube->player->dir_y * moveSpeed)] == '0')
		cube->player->pos_x += cube->player->dir_y * moveSpeed;
	if (cube->map[(int)(cube->player->pos_y - cube->player->dir_x * moveSpeed)]
		[(int)cube->player->pos_x] == '0')
		cube->player->pos_y -= (cube->player->dir_x) * moveSpeed;
}

void	update_movement(t_game *cube)
{
	double	move_speed;

	move_speed = cube->frame_time * 5.0;
	if (cube->player->mov_dir_y == 1)
		move_forward(cube, move_speed);
	if (cube->player->mov_dir_y == -1)
		move_backward(cube, move_speed);
	if (cube->player->mov_dir_x == 1)
		move_left(cube, move_speed);
	if (cube->player->mov_dir_x == -1)
		move_right(cube, move_speed);
}

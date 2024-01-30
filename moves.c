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
	if (cube->map[(int)cube->player->posY]
		[(int)(cube->player->posX + cube->player->dirX * moveSpeed)] == '0')
		cube->player->posX += cube->player->dirX * moveSpeed;
	if (cube->map[(int)(cube->player->posY + cube->player->dirY * moveSpeed)]
		[(int)(cube->player->posX)] == '0')
		cube->player->posY += cube->player->dirY * moveSpeed;
}

void	move_backward(t_game *cube, double moveSpeed)
{
	if (cube->map[(int)cube->player->posY]
		[(int)(cube->player->posX - cube->player->dirX * moveSpeed)] == '0')
		cube->player->posX -= cube->player->dirX * moveSpeed;
	if (cube->map[(int)(cube->player->posY - cube->player->dirY * moveSpeed)]
		[(int)cube->player->posX] == '0')
		cube->player->posY -= cube->player->dirY * moveSpeed;
}

void	move_right(t_game *cube, double moveSpeed)
{
	if (cube->map[(int)cube->player->posY]
		[(int)(cube->player->posX - cube->player->dirY * moveSpeed)] == '0')
		cube->player->posX -= cube->player->dirY * moveSpeed;
	if (cube->map[(int)(cube->player->posY + cube->player->dirX * moveSpeed)]
		[(int)(cube->player->posX)] == '0')
		cube->player->posY += (cube->player->dirX) * moveSpeed;
}

void	move_left(t_game *cube, double moveSpeed)
{
	if (cube->map[(int)cube->player->posY]
		[(int)(cube->player->posX + cube->player->dirY * moveSpeed)] == '0')
		cube->player->posX += cube->player->dirY * moveSpeed;
	if (cube->map[(int)(cube->player->posY - cube->player->dirX * moveSpeed)]
		[(int)cube->player->posX] == '0')
		cube->player->posY -= (cube->player->dirX) * moveSpeed;
}

void	update_movement(t_game *cube)
{
	double	move_speed;

	move_speed = cube->frameTime * 5.0;
	if (cube->player->mov_dirY == 1)
		move_forward(cube, move_speed);
	if (cube->player->mov_dirY == -1)
		move_backward(cube, move_speed);
	if (cube->player->mov_dirX == 1)
		move_left(cube, move_speed);
	if (cube->player->mov_dirX == -1)
		move_right(cube, move_speed);
}

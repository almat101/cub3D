/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:54:48 by amatta            #+#    #+#             */
/*   Updated: 2024/01/30 16:09:08 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

u_int64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

void	ft_sleep(u_int64_t time)
{
	u_int64_t	start;

	start = 0;
	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	count_fps(t_game *cube)
{
	char	*number;

	cube->old_time = cube->time;
	cube->time = get_time();
	cube->frame_time = (cube->time - cube->old_time) / 1000.0;
	cube->fps = (int)(1.0 / cube->frame_time);
	if (cube->fps > 60)
	{
		ft_sleep(((1.0 / 60) - cube->frame_time) * 1000);
		cube->time = get_time();
		cube->frame_time = (cube->time - cube->old_time) / 1000.0;
		cube->fps = (int)(1.0 / cube->frame_time);
	}
	number = ft_itoa(cube->fps);
	mlx_string_put(cube->mlx, cube->mlx_win,
		SW - 50, 20, -1, number);
	free(number);
}

void	free_err(t_game *cube, char *s)
{
	free_all2(cube);
	printf("%s", s);
	exit(1);
}

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

	dst = img->addr	+ (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_window(t_game *cube)
{
	mlx_destroy_window(cube->mlx, cube->mlx_win);
	free(cube->mlx);
	exit (1);
}

void	count_fps(t_game *cube)
{
	char *number;

	cube->oldTime = cube->time;
	cube->time = get_time();
	cube->frameTime = (cube->time - cube->oldTime) / 1000.0;
	cube->fps = (int)(1.0 / cube->frameTime);
	if (cube->fps > 60)
	{
		ft_sleep(((1.0 / 60) - cube->frameTime) * 1000);
		cube->time = get_time();
		cube->frameTime = (cube->time - cube->oldTime) / 1000.0;
		cube->fps = (int)(1.0 / cube->frameTime);
	}
	number = ft_itoa(cube->fps);
	mlx_string_put(cube->mlx, cube->mlx_win,
		screenWidth - 50, 20, -1, number);
}

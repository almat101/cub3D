#ifndef cube_H
# define cube_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "mlx_linux/mlx.h"
# include <stdbool.h>

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

typedef	struct s_player
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	mov_dirX;
	double	mov_dirY;
	double	cam_dir;
}	t_player;

typedef	struct s_colors
{
	int				f_color_num;
	int				c_color_num;
	char			**floor_colors;
	char			**ceiling_colors;
	char			*f_hex_color;
	char			*c_hex_color;
}	t_colors;

typedef	struct s_game
{
	void			*mlx;
	void			*mlx_win;
	t_colors		*colors;
	t_player		*player;
	double			time;
	double			oldTime;
	int				fps;
	double			frameTime;
}	t_game;

// utils.c
u_int64_t	get_time(void);
void	ft_sleep(u_int64_t time);

#endif

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

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
}	t_data;


typedef	struct s_colors
{
	int		f_color_num;
	int		c_color_num;
	char	**floor_colors;
	char	**ceiling_colors;
	char	*f_hex_color;
	char	*c_hex_color;
}	t_colors;

typedef	struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_colors	*colors;
	t_player	*player;
	double		time;
	double		oldTime;
	int			fps;
	double		frameTime;
	t_img 		*img;
}	t_game;


// main.c
void		init_step(t_data *data, t_game *cube);
void		init_data(t_data *data, t_game *cube, int x);
void		dda_algorithm(t_data *data);
void		draw_vertical_line(t_game *cube, t_data *data, int x);
void		render_map(t_game *cube);
void		set_color(t_data *data);

// utils.c
u_int64_t	get_time(void);
void		ft_sleep(u_int64_t time);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif

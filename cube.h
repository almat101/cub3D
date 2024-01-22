#ifndef cube_H
#define cube_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <sys/time.h>
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "mlx_linux/mlx.h"
#include <stdbool.h>

#define SCREENWIDTH 1000
#define SCREENHEIGHT 700

typedef struct s_player
{
	double posx;
	double posy;
	double dirx;
	double diry;
	double planex;
	double planey;
	double mov_dirx;
	double mov_diry;
	double cam_dir;
	double rot_angle;
	char direction;
	// double			posX;
	// double			posY;
	// double			dirX;
	// double			dirY;
	// double			planeX;
	// double			planeY;
	// double			mov_dirX;
	// double			mov_dirY;
	// double			cam_dir;
	// char			direction;
} t_player;

typedef struct s_img
{
	void *img;
	char *addr;
	int bpp;
	int line_length;
	int endian;
} t_img;

typedef struct s_data
{

	double map_x;
	double map_y;
	double step_x;
	double step_y;
	int hit;
	int side;
	int line_height;
	int draw_start;
	int draw_end;
	int tex_width;
	int tex_height;
	int tex_x;
	int tex_y;
	unsigned int color;
	double camera_x;
	double ray_dir_x;
	double ray_dir_y;
	double side_dist_x;
	double side_dist_y;
	double delta_dist_x;
	double delta_dist_y;
	double perp_wall_dist;
	double wall_x;
	double step;
	double tex_pos;
	// double			cameraX;
	// double			rayDirX;
	// double			rayDirY;
	// int				mapX;
	// int				mapY;
	// double			sideDistX;
	// double			sideDistY;
	// double			deltaDistX;
	// double			deltaDistY;
	// double			perpWallDist;
	// int				stepX;
	// int				stepY;
	// int				hit;
	// int				side;
	// int				lineHeight;
	// int				drawStart;
	// int				drawEnd;
	// unsigned int	color;
	// int				texWidth;
	// int				texHeight;
	// int				texX;
	// int				texY;
	// double			wallX;
	// double			step;
	// double			texPos;

} t_data;

typedef struct s_colors
{
	int f_floor;
	int c_ceil;
	char *floor_color;
	char *ceil_color;
	char *f_hex_color;
	char *c_hex_color;
} t_colors;

typedef struct s_xpm_img
{
	void *img;
	void *addr;
	int bpp;
	int line_length;
	int endian;
	int width;
	int height;
} t_xpm_img;

typedef struct s_cards
{
	t_xpm_img north_wall;
	t_xpm_img south_wall;
	t_xpm_img east_wall;
	t_xpm_img west_wall;
	char *no;
	char *so;
	char *ea;
	char *we;
	int n;
	int s;
	int w;
	int e;
} t_cards;

typedef struct s_game
{
	void *mlx;
	void *mlx_win;
	t_colors *colors; // floor and ceil
	t_player *player;
	double time;
	double oldTime;
	int fps;
	double frameTime;
	t_img *img;
	char **info;
	char **map;
	int map_width;
	int map_height;
	// char			*north_texture;
	// char			*south_texture;
	// char			*west_texture;
	// char			*east_texture;
	// char			*ceil_color_rgb;
	// char			*floor_color_rgb;
	t_cards *card; // texture no so ea we

} t_game;

// init.c
void init_all(t_game *cube);
int close_window(t_game *cube);
void destroy_all(t_game *cube);

// parser.c
void parse_map(char **argv, t_game *cube);
t_list *read_file(int fd);
void check_empty_file(t_list *lst, t_game *cube);
int count_lines(t_list *lst);
void copy_all_map(t_list *lst, t_game *cube);

// main.c
void init_step(t_data *data, t_game *cube);
void init_data(t_data *data, t_game *cube, int x);
void dda_algorithm(t_data *data, t_game *cube);
void render_map(t_game *cube);

// check1.c
void extract_colors(t_game *cube);
void assign_colors(t_game *cube, char **dest, char *src, int *flag);
void ft_rgb_err(t_game *cube, char *line, char **rgb_value);
void check_rgb(t_game *cube);
void check_valid_rgb(t_game *cube, char *line);

// check2.c
void is_cube(char *argv);
void check_player(t_game *cube);
void check_map(t_game *cube);
void check_flmap(t_game *cube);
void check_symbols(t_game *cube);

// color.c
int ft_rgb(int r, int g, int b);
void convert_color(t_game *cube, char *line, int is_floor);
char *to_hex(int decimal);
void rgb_to_hex(t_game *cube);

// map.c
void extract_real_map(t_game *cube);
void replace_tabs_in_real_map(char ***map, int num_lines);
int ft_strlen_row(char **info);
void check_map(t_game *cube);
char *replace_tabs_with_spaces(const char *str, int tab_count);
void fill_map_with_zero(char ***map, int num_lines);
void check_real_map(t_game *cube);

// key.c
int key_press(int key, t_game *cube);
int key_release(int key, t_game *cube);

// utils.c
u_int64_t get_time(void);
void ft_sleep(u_int64_t time);
void my_mlx_pixel_put(t_img *img, int x, int y, int color);
void count_fps(t_game *cube);
void free_err(t_game *cube, char *s);

// utils2.c
void print_map(char **info);
void print_colors_value(t_game *cube);
void print_texture_value(t_game *cube);
void printf_player(t_game *cube);

// utils3.c
int is_player(char c);
void save_player(t_game *cube);
void fix_texture_color(t_game *cube);

// utils4.c
int ft_strlen_row(char **info);
void replace_tabs_in_real_map(char ***map, int num_lines);
int count_tab(char *line);
char *replace_tabs_with_spaces(const char *str, int tab_count);

// parse_texture.c
int has_xpm_extension(const char *filename);
void extract_texture(t_game *cube);
void assign(t_game *cube, char **dest, char *src, int *flag);

// load_texture.c
void load_img(t_game *cube);
void load_texture_NO_SO(t_game *cube);
void load_texture_EA_WE(t_game *cube);
void load_all_texture(t_game *cube);

void draw_vertical_line(t_data *data, t_game *cube, int x);
void set_color(t_data *data, t_game *cube, int shift);
void setTexWH(t_data *data, t_game *cube);
int wallPosRayPosOnWall(t_data *data, t_game *cube);
void drawTextWall(t_data *data, t_game *cube, int x);

// free.c
void free_all(t_game *cube);
void free_texture(t_game *cube);
void free_list(t_list *lst);
void free_mat(char **mat);
void free_colors(t_game *cube);
void free_all2(t_game *cube);

int is_space(char c);
char *trim_whitespace(char *str);

#endif

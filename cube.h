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
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double mov_dirX;
	double mov_dirY;
	double cam_dir;
	double rot_angle; //todo mouse
	char direction;
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
	double camera_x;
	double delta_dist_x;
	double delta_dist_y;
	double map_x;
	double map_y;
	double perp_wall_dist;
	double ray_dir_x;
	double ray_dir_y;
	double side_dist_x;
	double side_dist_y;
	double step_x;
	double step_y;
	double step;
	double tex_pos;
	double wall_x;
	int draw_end;
	int draw_start;
	int hit;
	int line_height;
	int side;
	int tex_height;
	int tex_width;
	int tex_x;
	int tex_y;
	unsigned int color;
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
	t_colors *colors;
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
	t_cards *card;
} t_game;

// init.c
void			init_all(t_game *cube);
void			init_all2(t_game *cube);
int				close_window(t_game *cube);
void			init_data(t_data *data, t_game *cube, int x);
void			init_step(t_data *data, t_game *cube);
void			init_direction(t_game *cube);


// parser.c
void parse_info(char **argv, t_game *cube);
t_list *read_file(int fd);
void check_empty_file(t_list *lst, t_game *cube);
int count_lines(t_list *lst);
void copy_all_map(t_list *lst, t_game *cube);

// check1.c
void extract_colors(t_game *cube);
void assign_colors(t_game *cube, char **dest, char *src, int *flag);
void ft_rgb_err(t_game *cube, char *line, char **rgb_value);
void check_rgb(t_game *cube);
void check_valid_rgb(t_game *cube, char *line);

// check2.c
void			check_nplayer(t_game *cube);
void			check_inner_map(t_game *cube);
void			check_flmap(t_game *cube);
void			check_symbols(t_game *cube);
void			check_edges(t_game *cube);

// color.c
int ft_rgb(int r, int g, int b);
void convert_color(t_game *cube, char *line, int is_floor);
char *to_hex(int decimal);
void rgb_to_hex(t_game *cube);

// map.c
void			extract_real_map(t_game *cube);
void			replace_tabs_in_real_map(char ***map, int num_lines);
void			check_map(t_game *cube);
char			*replace_tabs_with_spaces(const char *str, int tab_count);
void			check_real_map(t_game *cube);

// key.c
int				key_press(int key, t_game *cube);
int				key_release(int key, t_game *cube);
int				handle_mouse(int x, int y, void *cube);

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
int			is_player(char c);
void		save_player(t_game *cube);
int			player_exist(t_game *game);

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
void			load_texture_NO_SO(t_game *cube);
void			load_texture_EA_WE(t_game *cube);
void			load_all_texture(t_game *cube);
void			load_imgs(t_game *cube);

void draw_vertical_line(t_data *data, t_game *cube, int x);
void set_color(t_data *data, t_game *cube, int shift);
void setTexWH(t_data *data, t_game *cube);
int wallPosRayPosOnWall(t_data *data, t_game *cube);
void drawTextWall(t_data *data, t_game *cube, int x);

// free.c
void			free_all(t_game *cube);
void			free_texture(t_game *cube);
void			free_list(t_list *lst);
void			free_mat(char **mat);
void			free_colors(t_game *cube);
void			free_all2(t_game *cube);

// utils5.c
int				is_space(char c);
char			*trim_whitespace(char *str);
void			mlx_hooks(t_game *cube);
void			is_cube(t_game *cube, char *argv);

// moves.c
void			move_forward(t_game *cube, double moveSpeed);
void			move_backward(t_game *cube, double moveSpeed);
void			move_right(t_game *cube, double moveSpeed);
void			move_left(t_game *cube, double moveSpeed);
void			update_movement(t_game *cube);

//rotate.c
void			rotate_to_left(t_game *cube, double rot_speed);
void			rotate_to_right(t_game *cube, double rot_speed);
void			update_rotation(t_game *cube);
void			rotate_cam(float angle, t_game *cube);


//render.c
void			render_map(t_game *cube);
void			dda_algorithm(t_data *data, t_game *cube);
void			draw_vertical_line(t_data *data, t_game *cube, int x);

//draw.c
void			drawTextWall(t_data *data, t_game *cube, int x);
void			set_color(t_data *data, t_game *cube, int shift);
void			setTexWH(t_data *data, t_game *cube);
int 			set_wall_x(t_data *data, t_game *cube);
int				wallPosRayPosOnWall(t_data *data, t_game *cube);

//main.c
int				game_loop(t_game *cube);
void			initialize_game(t_game *cube, char **argv);
void			start_game(t_game *cube);


#endif

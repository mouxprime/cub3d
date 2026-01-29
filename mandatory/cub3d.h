/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:57:53 by mianni            #+#    #+#             */
/*   Updated: 2025/02/24 14:31:04 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../includes/libft/libft.h"
# include "../includes/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <sys/time.h>

# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363
# define FORWARD_W_Z 122
# define BACK_S_S 115
# define RIGHT_D_D 100
# define LEFT_A_Q 113

# define SCREEN_W 1920
# define SCREEN_H 1080
# define TILE_SIZE 30
# define FOV 90
# define ROTATION_SPEED 0.015
# define PLAYER_SPEED 4
# define MINIMAP_SCALE 10

# define NORTH 0
# define SOUTH 2
# define EAST 1
# define WEST 3
# define DOOR_OPEN 4
# define DOOR_CLOSE 5
# define MINIMAP_MAX_SIZE 200
# define PLAYER_RADIUS 0.02
# define MAX_PARTICLES 50

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		angle;
	double		fov_rad;
	void		*img_sword;
	char		*addr_sword;
	void		*img_sword_bis;
	char		*addr_sword_bis;
	int			bpp_sword;
	int			line_len_sword;
	int			endian_sword;
	int			tex_sword_height;
	int			tex_sword_width;
	int			attack_frame;
}				t_player;

typedef struct s_ray // structure des rayons
{
	double	perp_wall_dist;
	double	dir_x;
	double	dir_y;
	double	plan_x;
	double	plan_y;
	double	camera_x;
	double	ray_x;
	double	ray_y;
	double	delta_x;
	double	delta_y;
	double	side_dist_x;
	double	side_dist_y;
	double	wall_hit;
	int		j_x;
	int		j_y;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_index;
	int		tex_x;
	int		tex_y;
	double	step_tex;
	double	tex_pos;
}				t_ray;

typedef struct s_data
{
	char		**map2d;
	int			map_pos_x;
	int			map_pos_y;
	int			map_width;
	int			map_height;
	int			doors_flag;
	int			door_height;
	int			door_width;
}				t_data;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	void		*img_tex;
	char		*addr_tex;
	int			bpp_tex;
	int			line_len_tex;
	int			endian_tex;
	void		*textures[5];
	char		*textures_data[5];
	int			tex_width;
	int			tex_height;
	int			color_c;
	int			color_f;
}				t_image;

typedef struct s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			up;
	int			down;
	int			left;
	int			right;
}				t_keys;

typedef struct s_mlx
{
	t_image		*image;
	t_ray		*ray;
	t_data		*data;
	t_player	*player;
	t_keys		keys;
	void		*mlx_p;
	void		*mlx_win;
	double		speed;
	int			fps;
	double		minimap_scale;
}				t_mlx;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

// Parsing
bool			check_cub_extension(char *str);
void			error_parsing(int type);
char			**parse_it(char *map_name);
int				count_max_i(char **map);
int				count_max_j(char *line);
bool			check_around(char **map, int i, int j);
char			*find_map(int fd);
bool			parse_ressources(char *file_name);
bool			is_in_double(int a, int b, char *file_name);
bool			is_rgb(char *line);
bool			check_4(char *file_name);
bool			check_5(char *file_name);
bool			check_6(char *file_name, int i);
bool			check_color_path(char *line);
char			**fill_map(char **map, int fd);
int				check_doors_position(char **map);
bool			check_door_number(char **map);

// Minimap
int				load_minimap(void);
void			calculate_minimap_scale(t_mlx *mlx);

// Init
t_mlx			init_struct(void);
void			fill_struct(char **map, t_mlx *mlx_struct);
void			init_minilibx(t_mlx *mlx_struct, char *file_name);
void			minimap_builder(t_mlx *mlx_struct);
int				update_display(t_mlx *mlx_struct);
t_mlx			*get_mlx(t_mlx *mlx_struct);
char			*get_tex_path_rgb(char *prefix, char *file_name);
char			*get_tex_path(char *prefix, char *file_name);
int				convert_img(t_image *img);

// Raycasting
int				cast_ray(void);

// Utils
// void	print_struct(int type);
void			set_pixel(double *ray_x, double *ray_y, double s_x, double s_y);
void			set_pixel2(double x, double y, int color);
void			close_or_open_door(t_mlx *mlx_struct);
void			draw_column(int x, int draw_start, int draw_end);
void			draw_c_f(int x);
void			clear_image(void);
void			destroy_mlx(t_mlx *map);
bool			is_player(char **map, int i, int j);
void			display_fps(void);

// Mouvements
void			move_forward(t_mlx *mlx_struct);
void			move_backward(t_mlx *mlx_struct);
void			move_left(t_mlx *mlx_struct);
void			move_right(t_mlx *mlx_struct);
void			angle_right(t_mlx *mlx_struct);
void			angle_left(t_mlx *mlx_struct);
int				key_press(int keycode, t_mlx *mlx_struct);
int				key_release(int keycode, t_mlx *mlx_struct);
void			print_door_message(t_mlx *mlx_struct);
bool			check_door(t_mlx *mlx_struct);
int				key_press(int keycode, t_mlx *mlx_struct);
int				key_release(int keycode, t_mlx *mlx_struct);
double			get_view_angle(t_mlx *mlx_struct);
int				is_walkable(char **map, double x, double y);

// Gestion des fenêtres et textures
int				destroy_window(t_mlx *mlx_struct);
int				open_img(char *file_name, t_image *img, t_player *player);
int				sword_loop(t_mlx *mlx);
int				key_press_sword(t_mlx *mlx);
void			draw_square(double x, double y, int size, int color);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:32:52 by ldedier           #+#    #+#             */
/*   Updated: 2017/12/04 22:57:25 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "../libft/libft.h"
# include <math.h>
# include "mlx.h"
# include <OpenCL/opencl.h>
# define WIN_WIDTH 1080
# define WIN_HEIGHT 1080
# define SMOOTH_COLOR 1
# define BURNING_COLOR 2
# define NEONS 4
# define NB_THREADS 4
# define NB_FRACTALS 6
# define BUFF_SIZE 12000

typedef struct s_env	t_env;

typedef struct			s_init
{
	char				*name;
	void				(* func)(t_env *);
}						t_init;

typedef struct			s_image
{
	void				*ptr;
	int					*data;
	int					width;
	int					height;
	int					bbp;
	int					endian;
	int					line_size;
}						t_image;

typedef struct			s_open_cl
{
	size_t				size;
	size_t				local_item_size;
	int					*input;
	int					*output;
	cl_platform_id		platform_id;
	cl_device_id		device_id;
	cl_uint				ret_num_platforms;
	cl_uint				ret_num_devices;
	cl_int				ret;
	cl_context			context;
	cl_command_queue	command_queue;
	cl_mem				input_mem_obj;
	cl_mem				output_mem_obj;
	cl_program			program;
	cl_kernel			kernel;
	char				*source_str;
	size_t				source_size;
}						t_open_cl;

typedef struct			s_fract
{
	double				x_min_init;
	double				x_max_init;
	double				y_min_init;
	double				y_max_init;
	double				x_min;
	double				x_max;
	double				y_min;
	double				y_max;
	int					color;
	int					smooth;
	int					x_mouse;
	int					y_mouse;
	int					id;
	double				c_r;
	double				c_i;
	double				c_r_init;
	double				c_i_init;
	int					iter_max;
	int					toggled;
	double				pos[20];
	int					iter_init;
	double				speed;
}						t_fract;

struct					s_env
{
	void				*mlx;
	void				*win;
	t_image				image;
	t_fract				fract;
	int					num_thread;
	t_init				tab_init[NB_FRACTALS];
	int					toggled_info;
};

int						key_hook(int keycode, t_env *e);
int						key_pressed_hook(int keycode, t_env *e);
int						motion_hook(int x, int y, t_env *e);
void					add_square_data(t_image *image, int x, int y, int c);
void					mlx_put_pixel_to_image(t_image *image, int color);
int						get_color(int r, int g, int b);
void					process_fractol(t_env *e);
int						mouse_event_funct(int keycode, int x, int y, t_env *e);
void					ft_init_burning_ship(t_env *e);
void					ft_init_perp_ship(t_env *e);
void					ft_init_julia(t_env *e);
void					ft_init_mandelbrot(t_env *e);
void					ft_init_tricorn(t_env *e);
void					ft_init_balloons(t_env *e);
void					init_fract_pos(t_env *e);
int						ft_error(int argc, char **argv, t_env *e, t_env *e2);
void					ft_print_man(void);
void					ft_print_commands(void);
void					init_env(t_env *e, int ind, char **argv);
t_image					ft_new_image(int width, int height);
int						init_fract(char *str, t_env *e);
void					init_t_init(t_env *e);
void					mlx_put_fract_img_open_cl(t_env *e);
void					wheel_hook_forward(int keycode, int x, int y, t_env *e);
void					wheel_hook_backward(int k, int x, int y, t_env *e);
void					key_hook_3(int keycode, t_env *e);
void					put_speed(t_env *e);
void					put_fatal_error(void);
void					put_interface(t_env *e);
void					put_iters(t_env *e);
#endif

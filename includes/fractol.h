/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:17:21 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/18 11:47:24 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MONITOR_WIDTH 1000
# define MONITOR_HEIGHT 800
# define MAX_ITERATIONS 100

# define a 1
# define o 3
# define dt 0.5

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>

typedef	void		(*t_func)();

typedef	struct		s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgb;

typedef struct		s_data
{
	int				width;
	int				height;
	int				max_iterations;
	void			*m_mlx_ptr;
	void			*m_win_ptr;
	double			zoom;
	double			move_x;
	double			move_y;
	double			c_re;
	double			c_im;
	void			*mlx_new_image;
	char			*mlx_get_data_addr;
	t_func			fractol;
	int				process;
}					t_data;

typedef struct s_m_buf
{
	int x;
	int y;
	double pr;
	double pi;
	double newRe;
	double newIm;
	double oldRe;
	double oldIm;
	t_rgb rgb;
} t_m_buf;

void				validation(int argc, char *argv, t_data *data);
char				*rgb_hexadecimal(t_rgb rgb);
void				constructor(t_data *data);
void				mandelbrot(t_data *data);
void				julia(t_data *data);
int					zoom(int button, int x, int y, t_data *data);
int					mouse_move(int x, int y, t_data *data);
void				fill_pixel(char *my_image_string, int x, int y, t_rgb rgb);
int					deal_with_keyboard(int key, t_data *data);
void				martin(t_data *data);

void m_calculations(t_data *data, t_m_buf m_buf, int *i);
void buf_zero(t_m_buf *buf);
void set_color_m(t_rgb *rgb, int iterations_per_pixel, int max_iterations);

#endif

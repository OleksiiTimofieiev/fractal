/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:17:21 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/17 14:00:20 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MONITOR_WIDTH 1000
# define MONITOR_HEIGHT 800
# define MAX_ITERATIONS 100

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>

typedef	void		(*t_func)();

typedef struct s_complex
{
	double x;
	double y;
}			t_complex;

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

void				validation(int argc, char *argv, t_data *data);
char				*rgb_hexadecimal(t_rgb rgb);
void				constructor(t_data *data);
void				mandelbrot(t_data *data);
void				julia(t_data *data);
int					zoom(int button, int x, int y, t_data *data);
int					mouse_move(int x, int y, t_data *data);
void				fill_pixel(char *my_image_string, int x, int y, t_rgb rgb);
int					deal_with_keyboard(int key, t_data *data);
void				cyrcle(t_data *data);

#endif

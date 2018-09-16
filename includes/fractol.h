/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:17:21 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 10:09:46 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MONITOR_WIDTH 800
# define MONITOR_HEIGHT 800
# define MAX_ITERATIONS 120

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
#include <time.h>

// # include <math.h>

typedef	struct	s_hsv
{
	double		H;
	double		S;
	double		V;
}				t_hsv;

typedef	struct	s_rgb
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
}				t_rgb;

typedef	struct	s_data
{
	double			width;
	double			height;
	double			m_max_re;
	double			m_min_re;
	double			m_max_im;
	double			m_min_im;
	double			max_iterations;
	void			*m_mlx_ptr;
	void			*m_win_ptr;

}				t_data;

void	validation(int argc, char *argv);
t_rgb hsv_to_rgb(t_hsv hsv);
char *RGBToHexadecimal(t_rgb rgb);
void constructor(t_data *data);
void mandelbrot(void **mlx_ptr, void **win_ptr, float left, float top, float xside, float yside);

#endif
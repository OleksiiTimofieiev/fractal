/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:17:21 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 15:55:11 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MONITOR_WIDTH 1000
# define MONITOR_HEIGHT 800
# define MAX_ITERATIONS 128

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <time.h>

typedef	struct	s_rgb
{
	unsigned char	R;
	unsigned char	G;
	unsigned char B;
}				t_rgb;

typedef	struct	s_data
{
	int				width;
	int				height;
	int				max_iterations;
	void			*m_mlx_ptr; // TODO: different pointers, in order to have three ones;
	void			*m_win_ptr;
	double			zoom;
	double			moveX;
	double			moveY;
	double			cRe;
	double			cIm;
	void 			*mlx_new_image;
	char			*mlx_get_data_addr;

}				t_data;

void	validation(int argc, char *argv);
char	*RGBToHexadecimal(t_rgb rgb);
void	constructor(t_data *data);
void	mandelbrot(t_data *data);
void	julia(t_data *data);

#endif
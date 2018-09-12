/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:17:21 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/12 12:57:00 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MONITOR_WIDTH 5120
# define MONITOR_HEIGHT 2880

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

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

void	validation(int argc, char *argv);
char *RGBToHexadecimal(t_rgb rgb);

#endif
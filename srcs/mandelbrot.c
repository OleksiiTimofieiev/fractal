/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 09:35:26 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 16:00:22 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void set_color(t_rgb *rgb, int IterationsPerPixel, int MaxIterations)
{
	if (IterationsPerPixel == MaxIterations)
	{
		rgb->R = 51;
		rgb->G = 0;
		rgb->B = 0;
	}
	else if (IterationsPerPixel < 64)
	{
		rgb->R = IterationsPerPixel * 2;
		rgb->G = 0;
		rgb->B = 0;
	}
	else if (IterationsPerPixel < 128)
	{
		rgb->R = (((IterationsPerPixel - 64) * 128) / 126) + 128;
		rgb->G = 0;
		rgb->B = 0;
	}
}

void fill_pixel(char *my_image_string, int x, int y, t_rgb rgb)
{
	my_image_string[x * 4 + 4000 * y] = rgb.G;
	my_image_string[x * 4 + 4000 * y + 1] = rgb.B;
	my_image_string[x * 4 + 4000 * y + 2] = rgb.R;
}

void mandelbrot(t_data *data) // different funcs;
{
	double pr, pi;	
	double newRe, newIm, oldRe, oldIm; 
	int i;
	int x = 0;
	int y = 0;
		
	for (y = 0; y < data->height; y++)
	{
		for (x = 0; x < data->width; x++)
		{
			pr = 1.5 * (x - data->width / 2) / (0.5 * data->zoom * data->width) + (data->moveX);
			pi = (y - data->height / 2) / (0.5 * data->zoom * data->height) + (data->moveY);
			newRe = newIm = oldRe = oldIm = 0;
			for (i = 0; i < data->max_iterations; i++)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + pr;
				newIm = 2 * oldRe * oldIm + pi;
				if ((newRe * newRe + newIm * newIm) > 4)
					break;
			}
			t_rgb rgb;
			set_color(&rgb, i, data->max_iterations);
			fill_pixel(data->mlx_get_data_addr, x, y, rgb);
		}
	}
	mlx_put_image_to_window(data->m_mlx_ptr, data->m_win_ptr, data->mlx_new_image, 0, 0);
}


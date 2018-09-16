/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 12:32:49 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 15:23:22 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"



void set_color(t_rgb *rgb, int IterationsPerPixel, int MaxIterations)
{
	if (IterationsPerPixel == MaxIterations)
	{
		rgb->R = 0;
		rgb->G = 0;
		rgb->B = 0;
	}
	else if (IterationsPerPixel < 64)
	{
		rgb->R = IterationsPerPixel * 2;
		rgb->G = 50;
		rgb->B = 15;
	}
	else if (IterationsPerPixel < 128)
	{
		rgb->R = 15;
		rgb->G = 0;
		rgb->B = (((IterationsPerPixel - 64) * 128) / 126) + 128;
	}
}

static void fill_pixel(char *my_image_string, int x, int y, t_rgb rgb)
{
	my_image_string[x * 4 + 4000 * y] = rgb.G;
	my_image_string[x * 4 + 4000 * y + 1] = rgb.B;
	my_image_string[x * 4 + 4000 * y + 2] = rgb.R;
}

void julia(t_data *data)
{
	double newRe, newIm, oldRe, oldIm;
	for (int y = 0; y < data->height; y++)
		for (int x = 0; x < data->width; x++)
		{
			newRe = 1.5 * (x - data->width / 2) / (0.5 * data->zoom * data->width) + (data->moveX);
			newIm = (y - data->height / 2) / (0.5 * data->zoom * data->height) + (data->moveY);
			int i;
			for (i = 0; i < data->max_iterations; i++)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + data->cRe;
				newIm = 2 * oldRe * oldIm + data->cIm;
				if ((newRe * newRe + newIm * newIm) > 4)
					break;
			}
			t_rgb rgb;

			set_color(&rgb, i, data->max_iterations);

			fill_pixel(data->mlx_get_data_addr, x, y, rgb);
		}
	mlx_put_image_to_window(data->m_mlx_ptr, data->m_win_ptr, data->mlx_new_image, 0, 0);
}

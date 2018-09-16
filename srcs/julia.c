/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 12:32:49 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 17:28:15 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"



static void set_color(t_rgb *rgb, int IterationsPerPixel, int MaxIterations)
{
	if (IterationsPerPixel == MaxIterations)
	{
		rgb->r = 0;
		rgb->g = 0;
		rgb->b = 0;
	}
	else if (IterationsPerPixel < 64)
	{
		rgb->r = IterationsPerPixel * 2;
		rgb->g = 50;
		rgb->b = 15;
	}
	else if (IterationsPerPixel < 128)
	{
		rgb->r = 15;
		rgb->g = 0;
		rgb->b = (((IterationsPerPixel - 64) * 128) / 126) + 128;
	}
}

static void fill_pixel(char *my_image_string, int x, int y, t_rgb rgb)
{
	my_image_string[x * 4 + 4000 * y] = rgb.g;
	my_image_string[x * 4 + 4000 * y + 1] = rgb.b;
	my_image_string[x * 4 + 4000 * y + 2] = rgb.r;
}

void julia(t_data *data)
{
	double newRe, newIm, oldRe, oldIm;
	for (int y = 0; y < data->height; y++)
		for (int x = 0; x < data->width; x++)
		{
			newRe = 1.5 * (x - data->width / 2) / (0.5 * data->zoom * data->width) + (data->move_x);
			newIm = (y - data->height / 2) / (0.5 * data->zoom * data->height) + (data->move_y);
			int i;
			for (i = 0; i < data->max_iterations; i++)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + data->c_re;
				newIm = 2 * oldRe * oldIm + data->c_im;
				if ((newRe * newRe + newIm * newIm) > 4)
					break;
			}
			t_rgb rgb;

			set_color(&rgb, i, data->max_iterations);

			fill_pixel(data->mlx_get_data_addr, x, y, rgb);
		}
	mlx_put_image_to_window(data->m_mlx_ptr, data->m_win_ptr, data->mlx_new_image, 0, 0);
}

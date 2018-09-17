/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 09:35:26 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/17 12:52:09 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void set_color(t_rgb *rgb, int IterationsPerPixel, int MaxIterations)
{
	if (IterationsPerPixel == MaxIterations)
	{
		rgb->r = 51;
		rgb->g = 0;
		rgb->b = 0;
	}
	else if (IterationsPerPixel < 64)
	{
		rgb->r = IterationsPerPixel * 2;
		rgb->g = 0;
		rgb->b = 0;
	}
	else if (IterationsPerPixel < 128)
	{
		rgb->r = (((IterationsPerPixel - 64) * 128) / 126) + 128;
		rgb->g = 0;
		rgb->b = 0;
	}
}

void mandelbrot1(void *data) // different funcs;
{
	double pr, pi;	
	double newRe, newIm, oldRe, oldIm; 
	int i;
	int x = 0;
	int y = 0;
	t_data *data_buf = (t_data*)data;
		
	for (y = 0; y < 399; y++)
	{
		for (x = 0; x < 499; x++)
		{
			// TODO: tmp for calculations;

			pr = 1.5 * (x - (data_buf)->width / 2) / (0.5 * (data_buf)->zoom * (data_buf)->width) + ((data_buf)->move_x);
			pi = (y - (data_buf)->height / 2) / (0.5 * (data_buf)->zoom * (data_buf)->height) + ((data_buf)->move_y);
			newRe = newIm = oldRe = oldIm = 0;
			for (i = 0; i < (data_buf)->max_iterations; i++)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + pr;
				newIm = 2 * oldRe * oldIm + pi;
				if ((newRe * newRe + newIm * newIm) > 4)
					break;
			}
			t_rgb rgb;
			set_color(&rgb, i, (data_buf)->max_iterations);
			fill_pixel((data_buf)->mlx_get_data_addr, x, y, rgb);
		}
	}
}
void mandelbrot2(t_data *data) // different funcs;
{
	t_data *data_buf = (t_data *)data;

	double pr, pi;
	double newRe, newIm, oldRe, oldIm;
	int i;
	int x = 0;
	int y = 0;

	for (y = 399; y < 800; y++)
	{
		for (x = 0; x < 499; x++)
		{
			// TODO: tmp for calculations;

			pr = 1.5 * (x - (data_buf)->width / 2) / (0.5 * (data_buf)->zoom * (data_buf)->width) + ((data_buf)->move_x);
			pi = (y - (data_buf)->height / 2) / (0.5 * (data_buf)->zoom * (data_buf)->height) + ((data_buf)->move_y);
			newRe = newIm = oldRe = oldIm = 0;
			for (i = 0; i < (data_buf)->max_iterations; i++)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + pr;
				newIm = 2 * oldRe * oldIm + pi;
				if ((newRe * newRe + newIm * newIm) > 4)
					break;
			}
			t_rgb rgb;
			set_color(&rgb, i, (data_buf)->max_iterations);
			fill_pixel((data_buf)->mlx_get_data_addr, x, y, rgb);
		}
	}
}
void mandelbrot3(t_data *data) // different funcs;
{
	t_data *data_buf = (t_data *)data;

	double pr, pi;
	double newRe, newIm, oldRe, oldIm;
	int i;
	int x = 0;
	int y = 0;

	for (y = 0; y < 399; y++)
	{
		for (x = 499; x < 1000; x++)
		{
			// TODO: tmp for calculations;

			pr = 1.5 * (x - (data_buf)->width / 2) / (0.5 * (data_buf)->zoom * (data_buf)->width) + ((data_buf)->move_x);
			pi = (y - (data_buf)->height / 2) / (0.5 * (data_buf)->zoom * (data_buf)->height) + ((data_buf)->move_y);
			newRe = newIm = oldRe = oldIm = 0;
			for (i = 0; i < (data_buf)->max_iterations; i++)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + pr;
				newIm = 2 * oldRe * oldIm + pi;
				if ((newRe * newRe + newIm * newIm) > 4)
					break;
			}
			t_rgb rgb;
			set_color(&rgb, i, (data_buf)->max_iterations);
			fill_pixel((data_buf)->mlx_get_data_addr, x, y, rgb);
		}
	}
}
void mandelbrot4(t_data *data) // different funcs;
{
	t_data *data_buf = (t_data *)data;

	double pr, pi;
	double newRe, newIm, oldRe, oldIm;
	int i;
	int x = 0;
	int y = 0;

	for (y = 399; y < 800; y++)
	{
		for (x = 499; x < 1000; x++)
		{
			// TODO: tmp for calculations;

			pr = 1.5 * (x - (data_buf)->width / 2) / (0.5 * (data_buf)->zoom * (data_buf)->width) + ((data_buf)->move_x);
			pi = (y - (data_buf)->height / 2) / (0.5 * (data_buf)->zoom * (data_buf)->height) + ((data_buf)->move_y);
			newRe = newIm = oldRe = oldIm = 0;
			for (i = 0; i < (data_buf)->max_iterations; i++)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + pr;
				newIm = 2 * oldRe * oldIm + pi;
				if ((newRe * newRe + newIm * newIm) > 4)
					break;
			}
			t_rgb rgb;
			set_color(&rgb, i, (data_buf)->max_iterations);
			fill_pixel((data_buf)->mlx_get_data_addr, x, y, rgb);
		}
	}

}

void	mandelbrot(t_data *data)
{
	mandelbrot1(data);
	mandelbrot2(data);
	mandelbrot3(data);
	mandelbrot4(data);
	mlx_put_image_to_window(data->m_mlx_ptr, data->m_win_ptr, data->mlx_new_image, 0, 0);
}

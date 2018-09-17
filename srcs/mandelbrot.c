/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 09:35:26 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/17 13:05:16 by otimofie         ###   ########.fr       */
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

void *mandelbrot1(void *data) // different funcs;
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
	pthread_exit(0);
}
void *mandelbrot2(void *data) // different funcs;
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
	pthread_exit(0);
}
void *mandelbrot3(void *data) // different funcs;
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
	pthread_exit(0);
}
void *mandelbrot4(void *data) // different funcs;
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
	pthread_exit(0); 
}

void	mandelbrot(t_data *data)
{
	pthread_t	tids[4];
	pthread_attr_t	attr;
	
	pthread_attr_init(&attr);


	pthread_create(&tids[0], &attr, mandelbrot1, data);
	pthread_create(&tids[1], &attr, mandelbrot2, data);
	pthread_create(&tids[2], &attr, mandelbrot3, data);
	pthread_create(&tids[3], &attr, mandelbrot4, data);

	pthread_join(tids[0], NULL);
	pthread_join(tids[1], NULL);
	pthread_join(tids[2], NULL);
	pthread_join(tids[3], NULL);

	mlx_put_image_to_window(data->m_mlx_ptr, data->m_win_ptr, data->mlx_new_image, 0, 0);
}

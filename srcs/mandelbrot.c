/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 09:35:26 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/18 11:41:58 by otimofie         ###   ########.fr       */
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

void	buf_zero(t_m_buf *buf)
{
	buf->newRe = 0;
	buf->newIm = 0;
	buf->oldRe = 0;
	buf->oldIm = 0;
}

void m_calculations(t_data *data, t_m_buf m_buf, int *i)
{
	*i = 0;
	while (*i < data->max_iterations)
	{
		m_buf.oldRe = m_buf.newRe;
		m_buf.oldIm = m_buf.newIm;
		m_buf.newRe = m_buf.oldRe * m_buf.oldRe - m_buf.oldIm * m_buf.oldIm + m_buf.pr;
		m_buf.newIm = 2 * m_buf.oldRe * m_buf.oldIm + m_buf.pi;

		if ((m_buf.newRe * m_buf.newRe + m_buf.newIm * m_buf.newIm) > 4)
			break;
		(*i)++;
	}
}

	void mandelbrot1(t_data *data)
{
	t_m_buf	m_buf;
	int		i;

	m_buf.y = 0;
	while (m_buf.y < 399)
	{
		m_buf.x = 0;
		while (m_buf.x < 499)
		{
			m_buf.pr = 1.5 * (m_buf.x - data->width / 2) / (0.5 * data->zoom * data->width) + (data->move_x);
			m_buf.pi = (m_buf.y - data->height / 2) / (0.5 * data->zoom * data->height) + (data->move_y);
			buf_zero(&m_buf);

			m_calculations(data, m_buf, &i);
			
			set_color(&m_buf.rgb, i, data->max_iterations);
			fill_pixel(data->mlx_get_data_addr, m_buf.x, m_buf.y, m_buf.rgb);
			m_buf.x++;
		}
		m_buf.y++;
	}
}

// void *mandelbrot1(void *data) // different funcs;
// {
// 	double newRe, newIm, oldRe, oldIm; 
// 	int i;
// 	t_data *data_buf = (t_data*)data;
		
// 	for (y = 0; y < 399; y++)
// 	{
// 		for (x = 0; x < 499; x++)
// 		{
// 			// TODO: tmp for calculations;
// 			pr = 1.5 * (x - (data_buf)->width / 2) / (0.5 * (data_buf)->zoom * (data_buf)->width) + ((data_buf)->move_x);
// 			pi = (y - (data_buf)->height / 2) / (0.5 * (data_buf)->zoom * (data_buf)->height) + ((data_buf)->move_y);
// 			newRe = newIm = oldRe = oldIm = 0;
// 			for (i = 0; i < (data_buf)->max_iterations; i++)
// 			{
// 				oldRe = newRe;
// 				oldIm = newIm;
// 				newRe = oldRe * oldRe - oldIm * oldIm + pr;
// 				newIm = 2 * oldRe * oldIm + pi;
// 				if ((newRe * newRe + newIm * newIm) > 4)
// 					break;
// 			}
// 			set_color(&rgb, i, (data_buf)->max_iterations);
// 			fill_pixel((data_buf)->mlx_get_data_addr, x, y, rgb);
// 		}
// 	}
// 	pthread_exit(0);
// }
// void *mandelbrot2(void *data) // different funcs;
// {
// 	t_data *data_buf = (t_data *)data;

// 	double pr, pi;
// 	double newRe, newIm, oldRe, oldIm;
// 	int i;
// 	int x = 0;
// 	int y = 0;

// 	for (y = 399; y < 800; y++)
// 	{
// 		for (x = 0; x < 499; x++)
// 		{
// 			// TODO: tmp for calculations;

// 			pr = 1.5 * (x - (data_buf)->width / 2) / (0.5 * (data_buf)->zoom * (data_buf)->width) + ((data_buf)->move_x);
// 			pi = (y - (data_buf)->height / 2) / (0.5 * (data_buf)->zoom * (data_buf)->height) + ((data_buf)->move_y);
// 			newRe = newIm = oldRe = oldIm = 0;
// 			for (i = 0; i < (data_buf)->max_iterations; i++)
// 			{
// 				oldRe = newRe;
// 				oldIm = newIm;
// 				newRe = oldRe * oldRe - oldIm * oldIm + pr;
// 				newIm = 2 * oldRe * oldIm + pi;
// 				if ((newRe * newRe + newIm * newIm) > 4)
// 					break;
// 			}
// 			t_rgb rgb;
// 			set_color(&rgb, i, (data_buf)->max_iterations);
// 			fill_pixel((data_buf)->mlx_get_data_addr, x, y, rgb);
// 		}
// 	}
// 	pthread_exit(0);
// }
// void *mandelbrot3(void *data) // different funcs;
// {
// 	t_data *data_buf = (t_data *)data;

// 	double pr, pi;
// 	double newRe, newIm, oldRe, oldIm;
// 	int i;
// 	int x = 0;
// 	int y = 0;

// 	for (y = 0; y < 399; y++)
// 	{
// 		for (x = 499; x < 1000; x++)
// 		{
// 			// TODO: tmp for calculations;

// 			pr = 1.5 * (x - (data_buf)->width / 2) / (0.5 * (data_buf)->zoom * (data_buf)->width) + ((data_buf)->move_x);
// 			pi = (y - (data_buf)->height / 2) / (0.5 * (data_buf)->zoom * (data_buf)->height) + ((data_buf)->move_y);
// 			newRe = newIm = oldRe = oldIm = 0;
// 			for (i = 0; i < (data_buf)->max_iterations; i++)
// 			{
// 				oldRe = newRe;
// 				oldIm = newIm;
// 				newRe = oldRe * oldRe - oldIm * oldIm + pr;
// 				newIm = 2 * oldRe * oldIm + pi;
// 				if ((newRe * newRe + newIm * newIm) > 4)
// 					break;
// 			}
// 			t_rgb rgb;
// 			set_color(&rgb, i, (data_buf)->max_iterations);
// 			fill_pixel((data_buf)->mlx_get_data_addr, x, y, rgb);
// 		}
// 	}
// 	pthread_exit(0);
// }
// void *mandelbrot4(void *data) // different funcs; // x y as input params;
// {
// 	t_data *data_buf = (t_data *)data;

// 	double pr, pi;
// 	double newRe, newIm, oldRe, oldIm;
// 	int i;
// 	int x = 0;
// 	int y = 0;

// 	for (y = 399; y < 800; y++)
// 	{
// 		for (x = 499; x < 1000; x++)
// 		{
// 			// TODO: tmp for constants;
// 			pr = 1.5 * (x - (data_buf)->width / 2) / (0.5 * (data_buf)->zoom * (data_buf)->width) + ((data_buf)->move_x);
// 			pi = (y - (data_buf)->height / 2) / (0.5 * (data_buf)->zoom * (data_buf)->height) + ((data_buf)->move_y);
// 			newRe = newIm = oldRe = oldIm = 0;
// 			for (i = 0; i < (data_buf)->max_iterations; i++)
// 			{
// 				oldRe = newRe;
// 				oldIm = newIm;
// 				newRe = oldRe * oldRe - oldIm * oldIm + pr;
// 				newIm = 2 * oldRe * oldIm + pi;
// 				if ((newRe * newRe + newIm * newIm) > 4)
// 					break;
// 			}
// 			t_rgb rgb;
// 			set_color(&rgb, i, (data_buf)->max_iterations);
// 			fill_pixel((data_buf)->mlx_get_data_addr, x, y, rgb);
// 		}
// 	}
// 	pthread_exit(0); 
// }

void	mandelbrot(t_data *data)
{
	// pthread_t		tids[4];
	// pthread_attr_t	attr;
	
	// pthread_attr_init(&attr);

	// pthread_create(&tids[0], &attr, mandelbrot1, data);
	// pthread_create(&tids[1], &attr, mandelbrot2, data);
	// pthread_create(&tids[2], &attr, mandelbrot3, data);
	// pthread_create(&tids[3], &attr, mandelbrot4, data);

	// pthread_join(tids[0], NULL);
	// pthread_join(tids[1], NULL);
	// pthread_join(tids[2], NULL);
	// pthread_join(tids[3], NULL);
	mandelbrot1(data);

	mlx_put_image_to_window(data->m_mlx_ptr, data->m_win_ptr, data->mlx_new_image, 0, 0);
}

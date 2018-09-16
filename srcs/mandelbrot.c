/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 09:35:26 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 09:55:32 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// void **mlx_ptr, void **win_ptr, float data->m_min_re, float data->m_max_re, float data->m_min_im, float data->m_max_im

void	mandelbrot(t_data *data)
{
	float xscale, yscale, zx, zy, cx, tempx, cy;
	int x, y;
	int count;
	t_hsv _hsv;
	t_rgb rgb;

	xscale = data->m_min_im / data->width;
	yscale = data->m_max_im / data->height;
	for (y = 1; y <= data->height - 1; y++)
	{
		for (x = 1; x <= data->width - 1; x++)
		{
			cx = x * xscale + data->m_min_re;
			cy = y * yscale + data->m_max_re;
			zx = 0;
			zy = 0;
			count = 0;
			while ((zx * zx + zy * zy < 4) && (count < data->max_iterations))
			{
				tempx = zx * zx - zy * zy + cx;
				zy = 2 * zx * zy + cy;
				zx = tempx;
				count = count + 1;
			}

			_hsv.H = count % 256;
			_hsv.S = 120;
			_hsv.V = 255 * (count < data->max_iterations);

			rgb = hsv_to_rgb(_hsv);

			mlx_pixel_put(data->m_mlx_ptr, data->m_win_ptr, x, y, hex_int_converter(RGBToHexadecimal(rgb)));
		}
	}
}
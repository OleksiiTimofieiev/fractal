/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 09:35:26 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 11:31:16 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


static int hex_int_converter(char *input)
{
	int base;
	size_t len;
	int dec_val;
	int i;

	base = 1;
	len = ft_strlen(input);
	dec_val = 0;
	i = len - 1;
	while (i >= 0)
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			dec_val += (input[i] - 48) * base;
			base = base * 16;
		}
		else if (input[i] >= 'A' && input[i] <= 'F')
		{
			dec_val += (input[i] - 55) * base;
			base = base * 16;
		}
		i--;
	}
	return (dec_val);
}

// void **mlx_ptr, void **win_ptr, float left, float top, float xside, float yside

void	mandelbrot(t_data *data)
{
	float xscale, yscale, zx, zy, cx, tempx, cy;
	int x, y;
	int count;

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
			t_hsv _hsv;

			_hsv.H = count % 256;
			_hsv.S = 120;
			_hsv.V = 255 * (count < 120);

			t_rgb rgb = hsv_to_rgb(_hsv);

			mlx_pixel_put(data->m_mlx_ptr, data->m_win_ptr, x, y, hex_int_converter(RGBToHexadecimal(rgb)));
		}
	}
}

// void mandelbrot(t_data * data)
// {
// 	// double MinRe = -2.0;
// 	// double MaxRe = 1.0;
// 	// double MinIm = -1.2;
// 	// double MaxIm = MinIm + (MaxRe - MinRe) * data->height / data->width;
	
// 	double Re_factor = (data->m_max_re - data->m_min_re) / (data->width - 1);
// 	double Im_factor = (data->m_max_im - data->m_min_im) / (data->height - 1);

// 	int MaxIterations = 30;

// 	for (int y = 0; y < data->height; ++y)
// 	{
// 		double c_im = data->m_max_im - y * Im_factor;

// 		for (int x = 0; x < data->width; ++x)
// 		{
// 			double c_re = data->m_min_re + x * Re_factor;

// 			double Z_re = c_re, Z_im = c_im;
// 			int isInside = 0;
// 			int n = 0;
// 			for (; n < MaxIterations; ++n)
// 			{
// 				double Z_re2 = Z_re * Z_re;
// 				double Z_im2 = Z_im * Z_im;
// 				if (Z_re2 + Z_im2 > 4)
// 				{
// 					isInside = 1;
// 					break;
// 				}
// 				Z_im = 2 * Z_re * Z_im + c_im;
// 				Z_re = Z_re2 - Z_im2 + c_re;
// 			}
// 			if (isInside)
// 			{
// 				t_hsv _hsv;

// 				_hsv.H = n % 256;
// 				_hsv.S = 120;
// 				_hsv.V = 255 * (n < MaxIterations);

// 				t_rgb rgb = hsv_to_rgb(_hsv);

// 				mlx_pixel_put(data->m_mlx_ptr, data->m_win_ptr, x, y, hex_int_converter(RGBToHexadecimal(rgb)));
// 			}
// 		}
// 	}
// }
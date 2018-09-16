/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 09:35:26 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 10:29:12 by otimofie         ###   ########.fr       */
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
	int x, y; /* i, j;*/
	int maxx, maxy, count;

	// getting maximum value of x-axis of screen
	maxx = 800;

	// getting maximum value of y-axis of screen
	maxy = 800;

	// setting up the xscale and yscale
	xscale = data->m_min_im / maxx;
	yscale = data->m_max_im / maxy;

	// scanning every point in that rectangular area.
	// Each point represents a Complex number (x + yi).
	// Iterate that complex number
	for (y = 1; y <= maxy - 1; y++)
	{
		for (x = 1; x <= maxx - 1; x++)
		{
			// c_real
			cx = x * xscale + data->m_min_re;

			// c_imaginary
			cy = y * yscale + data->m_max_re;

			// z_real
			zx = 0;

			// z_imaginary
			zy = 0;
			count = 0;

			// Calculate whether c(c_real + c_imaginary) belongs
			// to the Mandelbrot set or not and draw a pixel
			// at coordinates (x, y) accordingly
			// If you reach the Maximum number of iterations
			// and If the distance from the origin is
			// greater than 2 exit the loop
			while ((zx * zx + zy * zy < 4) && (count < 120))
			{
				// Calculate Mandelbrot function
				// z = z*z + c where z is a complex number

				// tempx = z_real*_real - z_imaginary*z_imaginary + c_real
				tempx = zx * zx - zy * zy + cx;

				// 2*z_real*z_imaginary + c_imaginary
				zy = 2 * zx * zy + cy;

				// Updating z_real = tempx
				zx = tempx;

				// Increment count
				count = count + 1;
			}

			// To display the created fractal
			t_hsv _hsv;

			_hsv.H = count % 256;
			_hsv.S = 120;
			_hsv.V = 255 * (count < 120);

			t_rgb rgb = hsv_to_rgb(_hsv);

			mlx_pixel_put(data->m_mlx_ptr, data->m_win_ptr, x, y, hex_int_converter(RGBToHexadecimal(rgb)));
		}
	}
}
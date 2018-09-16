/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 09:35:26 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 10:30:44 by otimofie         ###   ########.fr       */
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
			while ((zx * zx + zy * zy < 4) && (count < 120))
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
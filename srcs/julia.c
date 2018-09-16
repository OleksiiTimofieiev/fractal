/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 12:32:49 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 12:39:15 by otimofie         ###   ########.fr       */
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

void julia(t_data *data)
{
	//each iteration, it calculates: new = old*old + c, where c is a constant and old starts at current pixel

	double newRe, newIm, oldRe, oldIm; //real and imaginary parts of new and old

	double cRe = -0.7, cIm = 0.27015;
	// basic data->zoom;
	// ColorRGB color;							  //the RGB color value for the pixel
	int maxIterations = 128; //after how much iterations the function should stop

	// int showText = 0;
	for (int y = 0; y < data->height; y++)
		for (int x = 0; x < data->width; x++)
		{
			//calculate the initial real and imaginary part of z, based on the pixel location and data->zoom and position values
			newRe = 1.5 * (x - data->width / 2) / (0.5 * data->zoom * data->width) + (data->moveX);
			newIm = (y - data->height / 2) / (0.5 * data->zoom * data->height) + (data->moveY);
			// newRe = newIm = oldRe = oldIm = 0; //these should start at 0,0
			//i will represent the number of iterations
			int i;
			//start the iteration process
			for (i = 0; i < maxIterations; i++)
			{
				//remember value of previous iteration
				oldRe = newRe;
				oldIm = newIm;
				//the actual iteration, the real and imaginary part are calculated
				newRe = oldRe * oldRe - oldIm * oldIm + cRe;
				newIm = 2 * oldRe * oldIm + cIm;
				//if the point is outside the circle with radius 2: stop
				if ((newRe * newRe + newIm * newIm) > 4)
					break;
			}

			t_hsv _hsv;

			_hsv.H = i % 256;
			_hsv.S = 120; //100
			_hsv.V = 255 * (i < maxIterations);

			t_rgb rgb = hsv_to_rgb(_hsv);

			mlx_pixel_put(data->m_mlx_ptr, data->m_win_ptr, x, y, hex_int_converter(RGBToHexadecimal(rgb)));
		}
}

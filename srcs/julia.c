/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 12:32:49 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 13:20:19 by otimofie         ###   ########.fr       */
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
	else if (IterationsPerPixel < 256)
	{
		rgb->R = (((IterationsPerPixel - 128) * 62) / 127) + 193;
		rgb->G = 0;
		rgb->B = 0;
	}
	else if (IterationsPerPixel < 512)
	{
		rgb->R = 255;
		rgb->G = (((IterationsPerPixel - 256) * 62) / 255) + 1;
		rgb->B = 0;
	}
	else if (IterationsPerPixel < 1024)
	{
		rgb->R = 255;
		rgb->G = (((IterationsPerPixel - 512) * 63) / 511) + 64;
		rgb->B = 0;
	}
	else if (IterationsPerPixel < 2048)
	{
		rgb->R = 255;
		rgb->G = (((IterationsPerPixel - 1024) * 63) / 1023) + 128;
		rgb->B = 0;
	}
	else if (IterationsPerPixel < 4096)
	{
		rgb->R = 255;
		rgb->G = (((IterationsPerPixel - 2048) * 63) / 2047) + 192;
		rgb->B = 0;
	}
	else
	{
		rgb->R = 255;
		rgb->G = 255;
		rgb->B = 0;
	}
}

void julia(t_data *data)
{
	//each iteration, it calculates: new = old*old + c, where c is a constant and old starts at current pixel

	double newRe, newIm, oldRe, oldIm; //real and imaginary parts of new and old

	
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
				newRe = oldRe * oldRe - oldIm * oldIm + data->cRe;
				newIm = 2 * oldRe * oldIm + data->cIm;
				//if the point is outside the circle with radius 2: stop
				if ((newRe * newRe + newIm * newIm) > 4)
					break;
			}

			t_rgb rgb;

			set_color(&rgb, i, maxIterations);

			mlx_pixel_put(data->m_mlx_ptr, data->m_win_ptr, x, y, hex_int_converter(RGBToHexadecimal(rgb)));
		}
}
